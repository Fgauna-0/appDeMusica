#include <iostream>
#include "PlaylistManager.h"

using namespace std;

PlaylistManager::PlaylistManager()
{
    //ctor
}

void PlaylistManager::crearPlaylist(int idSuscriptor){

    PlaylistArchivo archivo;
    Playlist p;
    string nombre;

    cout << "=======================================" << endl;
    cout << "#            CREAR PLAYLIST            #" << endl;
    cout << "=======================================" << endl;
    cout << "-Ingrese el nombre de la playlist: " << endl;
    getline(cin, nombre);

    p.setIdPlaylist(archivo.getCantidadRegistros() + 1);
    p.setIdSuscriptor(idSuscriptor);
    p.setNombrePlaylist(nombre);
    p.setReproducciones(0);
    p.setEstado(true);

    if(archivo.guardar(p)){
        cout << "Playlist creada exitosamente!" << endl;
    }else{
        cout << "No se pudo crear la playlist..." << endl;
    }


}

void PlaylistManager::mostrarPlaylistDelSuscriptor(int idSuscriptor){

    PlaylistArchivo archivo;
    Playlist p;
    int total = archivo.getCantidadRegistros();
    bool hay = false;

    cout << "=======================================" << endl;
    cout << "#            PLAYLISTS                #" << endl;
    cout << "=======================================" << endl;

    for(int i = 0; i < total; i++){
        if(archivo.leer(i,p) && p.getEstado() && p.getIdSuscriptor() == idSuscriptor){
            cout << "ID: " << p.getIdPlaylist() << " | Nombre: " << p.getNombrePlaylist() << endl;
            hay = true;
        }
    }

    if(!hay) cout << "No tenes playlist creadas.\n";

}
