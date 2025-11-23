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

    Playlist playlist;
    PlaylistCancion pc;
    Cancion c;
    Artista a;

    int posPlaylist = _repoPlaylist.buscarPorId(idPlaylist);
    if (posPlaylist == -1 || !_repoPlaylist.leer(posPlaylist, playlist)) {
        cout << "No existe la playlist." << endl;
        return;
    }

    // Validar propietario
    if (playlist.getIdSuscriptor() != _suscriptorActual.getId()) {
        cout << "No podes ver una playlist que no es tuya." << endl;
        return;
    }

    // Validar estado
    if (!playlist.getEstado()) {
        cout << "La playlist está deshabilitada." << endl;
        return;
    }

    cout << "=======================================" << endl;
    cout << "#       CANCIONES DE LA PLAYLIST       #" << endl;
    cout << "=======================================" << endl;
    cout << "| " << playlist.getNombrePlaylist() << endl << endl;

    int totalRel = _repoPlaylistCancion.getCantidadRegistros();
    bool hay = false;

    for (int i = 0; i < totalRel; i++) {

        if (!_repoPlaylistCancion.leer(i, pc)) continue;

        if (pc.getEstado() && pc.getIdPlaylist() == idPlaylist) {

            int posCancion = _repoCancion.buscarId(pc.getIdCancion());
            if (posCancion == -1) continue;  // canción no existe

            if (!_repoCancion.leer(posCancion, c)) continue;

            // Buscar artista
            int posArt = _repoArtista.buscarId(c.getIdArtista());
            string nombreArtista = "(Desconocido)";

            if (posArt != -1 && _repoArtista.leer(posArt, a)) {
                nombreArtista = a.getNombre();
            }

            // Mostrar canción + artista
            cout << "- " << c.getNombreCancion()
                 << " | Artista: " << nombreArtista << endl;

            hay = true;
        }
    }

    if (!hay) cout << "No hay canciones en esta playlist.\n";

}

void PlaylistManager::agregarCancionAPlaylistPorIdPlaylist(int idPlaylist) {

    Playlist p;

    int posPlaylist = _repoPlaylist.buscarPorId(idPlaylist);

    if(posPlaylist == -1 || !_repoPlaylist.leer(posPlaylist, p)){
        cout << "La playlist no existe.\n";
        return;
    }

    if(p.getIdSuscriptor() != _suscriptorActual.getId()){
        cout << "No tenes una playlist con ese ID.\n";
        return;
    }

    if(!p.getEstado()){
        cout << "La playlist está dada de baja.\n";
        return;
    }

    cout << "=======================================" << endl;
    cout << "#        AGREGAR CANCION A PLAYLIST    #" << endl;
    cout << "=======================================" << endl;

    int totalCanciones = _repoCancion.getCantidadRegistros();
    Cancion c;

    for(int i = 0; i < totalCanciones; i++){
    if(_repoCancion.leer(i, c) && c.getEstado()){

        // Buscar artista
        Artista a;
        int posArt = _repoArtista.buscarId(c.getIdArtista());
        string nombreArtista = "(Desconocido)";

        if(posArt != -1 && _repoArtista.leer(posArt, a)){
            nombreArtista = a.getNombre();
        }

        // Mostrar canción + artista
        cout << c.getIdCancion()
             << " - " << c.getNombreCancion()
             << " | Artista: " << nombreArtista
             << endl;
    }
}

    int idCancion;
    cout << "Ingresar ID de la cancion a agregar: ";
    cin >> idCancion;

    cin.ignore();

    int posCancion = _repoCancion.buscarId(idCancion);
    if(posCancion == -1){
        cout << "No existe una cancion con ese ID.\n";
        return;
    }

    _repoCancion.leer(posCancion, c);

    if(!c.getEstado()){
        cout << "La canción está deshabilitada.\n";
        return;
    }

    if(_repoPlaylistCancion.existeRelacion(idPlaylist, idCancion)){
        cout << "La canción ya está en la playlist.\n";
        return;
    }

    // Crear relación
    PlaylistCancion pc;
    pc.setIdPlaylist(idPlaylist);
    pc.setIdCancion(idCancion);
    pc.setEstado(true);

    if(_repoPlaylistCancion.guardar(pc)){
        cout << "Cancion agregada correctamente!\n";
    }
    else {
        cout << "Error al agregar la cancion.\n";
    }
}

void PlaylistManager::agregarCancionAPlaylistPorIdPlaylistYIdCancion(int idPlaylist, int idCancion){

    Playlist p;
    Cancion c;

    int posPlaylist = _repoPlaylist.buscarPorId(idPlaylist);

    if(posPlaylist == -1 || !_repoPlaylist.leer(posPlaylist, p)){
        cout << "La playlist no existe.\n";
        return;
    }

    if(p.getIdSuscriptor() != _suscriptorActual.getId()){
        cout << "No tenes una playlist con ese ID.\n";
        return;
    }

    if(!p.getEstado()){
        cout << "La playlist esta dada de baja.\n";
        return;
    }


    int posCancion = _repoCancion.buscarId(idCancion);
    if(posCancion == -1){
        cout << "No existe una cancion con ese ID.\n";
        return;
    }

    _repoCancion.leer(posCancion, c);

    if(!c.getEstado()){
        cout << "La cancion esta deshabilitada.\n";
        return;
    }

    if(_repoPlaylistCancion.existeRelacion(idPlaylist, idCancion)){
        cout << "La cancion ya esta en la playlist.\n";
        return;
    }

    // Crear relación
    PlaylistCancion pc;
    pc.setIdPlaylist(idPlaylist);
    pc.setIdCancion(idCancion);
    pc.setEstado(true);

    if(_repoPlaylistCancion.guardar(pc)){
        cout << "Cancion agregada correctamente!\n";
    }
    else {
        cout << "Error al agregar la cancion.\n";
    }
}

void PlaylistManager::setSuscriptorActual(const Suscriptor& s){
    _suscriptorActual = s;
}
