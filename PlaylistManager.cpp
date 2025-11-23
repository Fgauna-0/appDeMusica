#include <iostream>
#include "PlaylistManager.h"

using namespace std;

PlaylistManager::PlaylistManager()
{
    //ctor
}

void PlaylistManager::crearPlaylist(int idSuscriptor){

    Playlist p;
    string nombre;

    cout << "=======================================" << endl;
    cout << "#            CREAR PLAYLIST            #" << endl;
    cout << "=======================================" << endl;
    cout << "-Ingrese el nombre de la playlist: " << endl;
    getline(cin, nombre);

    p.setIdPlaylist(_repoPlaylist.getNuevoId());
    p.setIdSuscriptor(idSuscriptor);
    p.setNombrePlaylist(nombre);
    p.setReproducciones(0);
    p.setEstado(true);

    if(_repoPlaylist.guardar(p)){
        cout << "Playlist creada exitosamente!" << endl;
    }else{
        cout << "No se pudo crear la playlist..." << endl;
    }
}

void PlaylistManager::mostrarPlaylistDelSuscriptor(int idSuscriptor){

    Playlist p;
    int total = _repoPlaylist.getCantidadRegistros();
    bool hay = false;

    cout << "=======================================" << endl;
    cout << "#            PLAYLISTS                #" << endl;
    cout << "=======================================" << endl;

    for(int i = 0; i < total; i++){
        if(_repoPlaylist.leer(i,p) && p.getEstado() && p.getIdSuscriptor() == idSuscriptor){
            int cantidad = getCantidadCancionesPlaylist(p.getIdPlaylist());
            cout << "ID: " << p.getIdPlaylist() << "| Nombre: " << p.getNombrePlaylist() << " | Canciones: " << cantidad << endl;
            hay = true;
        }
    }

    if(!hay) cout << "No tenes playlist creadas.\n";
}

int PlaylistManager::getCantidadCancionesPlaylist(int idPlaylist){

    PlaylistCancion canciones;
    int total = _repoPlaylist.getCantidadRegistros();
    int contador = 0;

    for(int i = 0; i < total; i++){
        if(_repoPlaylistCancion.leer(i, canciones)){
            if(canciones.getIdPlaylist() == idPlaylist && canciones.getEstado()){
                contador ++;
            }
        }
    }
    return contador;
}

void PlaylistManager::mostrarCancionesDePlaylist(int idPlaylist){

    PlaylistCancion p;
    Cancion c;
    int total = _repoPlaylistCancion.getCantidadRegistros();
    bool hay = false;

    cout << "=======================================" << endl;
    cout << "#       CANCIONES DE LA PLAYLIST       #" << endl;
    cout << "=======================================" << endl;

    for(int i=0; i < total; i++){
        if(_repoPlaylistCancion.leer(i,p)){
            if(p.getEstado() && p.getIdPlaylist() == idPlaylist){
                int pos = _repoCancion.buscarId(p.getIdCancion());
                if (pos >= 0 && _repoCancion.leer(pos, c)){
                        cout << "- " << c.getNombreCancion() << endl;
                        hay = true;
                    }
            }
        }
    }

    if(!hay) cout << "No hay canciones en esta playlist.\n";
}
