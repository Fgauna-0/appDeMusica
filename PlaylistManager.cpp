#include <iostream>
#include "PlaylistManager.h"

using namespace std;

PlaylistManager::PlaylistManager()
{
    //ctor
}

bool PlaylistManager::crearPlaylist(int idSuscriptor,string nombre){

    Playlist p;

    p.setIdPlaylist(_repoPlaylist.getNuevoId());
    p.setIdSuscriptor(idSuscriptor);
    p.setNombrePlaylist(nombre);
    p.setReproducciones(0);
    p.setEstado(true);

    if(_repoPlaylist.guardar(p)){
        return true;
    }else{
        return false;
    }
}

bool PlaylistManager::mostrarPlaylistDelSuscriptor(int idSuscriptor){

    Playlist p;
    int total = _repoPlaylist.getCantidadRegistros();
    bool hay = false;

    for(int i = 0; i < total; i++){
        if(_repoPlaylist.leer(i,p) && p.getEstado() && p.getIdSuscriptor() == idSuscriptor){
            int cantidad = getCantidadCancionesPlaylist(p.getIdPlaylist());
            cout << "ID: " << p.getIdPlaylist() << "| Nombre: " << p.getNombrePlaylist() << " | Canciones: " << cantidad << endl;
            hay = true;
        }
    }

    if(!hay) cout << "No tenes playlist creadas.\n";

    return hay;
}

int PlaylistManager::getCantidadCancionesPlaylist(int idPlaylist){

    PlaylistCancion canciones;
    int total = _repoPlaylistCancion.getCantidadRegistros();
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
            if (posCancion == -1) continue;  // cancion no existe

            if (!_repoCancion.leer(posCancion, c)) continue;

            // Buscar artista
            int posArt = _repoArtista.buscarId(c.getIdArtista());
            string nombreArtista = "(Desconocido)";

            if (posArt != -1 && _repoArtista.leer(posArt, a)) {
                nombreArtista = a.getNombre();
            }

            // Mostrar cancion + artista
            cout << c.getIdCancion()
                 << " - " << c.getNombreCancion()
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
        cout << "La playlist esta dada de baja.\n";
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
    cout << "Ingresar ID de la cancion a agregar";
    idCancion = fg.leerIntSeguro("Opcion: ");

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

bool PlaylistManager::agregarCancionAPlaylistPorIdPlaylistYIdCancion(int idPlaylist, int idCancion){

    Playlist p;
    int posPlaylist = _repoPlaylist.buscarPorId(idPlaylist);

    if (posPlaylist == -1 || !_repoPlaylist.leer(posPlaylist, p)) return false;

    if (p.getIdSuscriptor() != _suscriptorActual.getId()) return false;

    if (!p.getEstado()) return false;


    // Revisar si ya existe relacion
    int posRel = _repoPlaylistCancion.buscarPorId(idCancion, idPlaylist);

    if (posRel != -1) {
        PlaylistCancion pc;
        _repoPlaylistCancion.leer(posRel, pc);

        if (pc.getEstado()) {
            // Ya existe, NO se puede agregar
            cout << "La cancion ya esta en la playlist.\n";
            return false;
        }
        else {
            // Existe pero está deshabilitada
            pc.setEstado(true);
            return _repoPlaylistCancion.modificar(posRel, pc);
        }
    }


    // No existe la relación, agregar nueva

    PlaylistCancion nueva;
    nueva.setIdPlaylist(idPlaylist);
    nueva.setIdCancion(idCancion);
    nueva.setEstado(true);

    return _repoPlaylistCancion.guardar(nueva);

}

void PlaylistManager::setSuscriptorActual(const Suscriptor& s){
    _suscriptorActual = s;
}

void PlaylistManager::eliminarPlaylist(int id){

    Playlist p;

    int pos = _repoPlaylist.buscarPorId(id);
    if (pos == -1 || !_repoPlaylist.leer(pos, p)) {
        cout << "No existe una playlist con ese ID.\n";
        return;
    }

    // Validar que la playlist pertenece al suscriptor
    if (p.getIdSuscriptor() != _suscriptorActual.getId()) {
        cout << "No podes eliminar una playlist que no es tuya.\n";
        return;
    }

    if (!p.getEstado()) {
        cout << "La playlist ya está eliminada.\n";
        return;
    }

    //Marcar playlist como eliminada
    p.setEstado(false);
    if (!_repoPlaylist.modificar(pos, p)) {
        cout << "Error al intentar eliminar la playlist.\n";
        return;
    }

    //Marcar sus relaciones como eliminadas
    PlaylistCancion pc;
    int total = _repoPlaylistCancion.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        if (_repoPlaylistCancion.leer(i, pc)) {
            if (pc.getIdPlaylist() == id && pc.getEstado()) {
                pc.setEstado(false);
                _repoPlaylistCancion.modificar(i, pc);
            }
        }
    }

    cout << "Playlist eliminada correctamente.\n";

}

bool PlaylistManager::eliminarCancionDePlaylist(int idPlaylist, int idCancion) {

    //Validar que la playlist exista y sea del usuario
    Playlist p;

    int posP = _repoPlaylist.buscarPorId(idPlaylist);
    if (posP == -1 || !_repoPlaylist.leer(posP, p))
        return false;

    if (p.getIdSuscriptor() != _suscriptorActual.getId())
        return false;

    if (!p.getEstado())
        return false;

    // Buscar la relacion en el archivo de playlist canciones
    PlaylistCancion pc;
    int posRel = _repoPlaylistCancion.buscarPorId(idCancion, idPlaylist);

    if (posRel == -1)
        return false;

    //Leer registro
    if (!_repoPlaylistCancion.leer(posRel, pc))
        return false;

    //Marcar como eliminado
    pc.setEstado(false);

    return _repoPlaylistCancion.modificar(posRel, pc);
}

vector<Playlist> PlaylistManager::cargarTodas(){
    vector<Playlist> v;
    int total = _repoPlaylist.getCantidadRegistros();
    v.resize(total);
    for(int i=0;i<total;i++){
        _repoPlaylist.leer(i, v[i]);
    }
    return v;
}

// -------- LISTADOS --------

void PlaylistManager::listarPorNombre(){
    auto v = cargarTodas();

    sort(v.begin(), v.end(), [](const Playlist& a, const Playlist& b){
        return a.getNombrePlaylist() < b.getNombrePlaylist();
    });

    for(auto &pl : v){
        cout << pl.getNombrePlaylist()
             << " | Usuario: " << pl.getIdSuscriptor()
             << " | Canciones: " << getCantidadCancionesPlaylist(pl.getIdPlaylist())
             << endl;
    }
}

void PlaylistManager::listarPorCantidadCanciones(){
    auto v = cargarTodas();

    sort(v.begin(), v.end(), [this](const Playlist& a, const Playlist& b){
        return getCantidadCancionesPlaylist(a.getIdPlaylist()) >
               getCantidadCancionesPlaylist(b.getIdPlaylist());
    });

    for(auto &pl : v){
        cout << pl.getNombrePlaylist()
             << " | Canciones: " << getCantidadCancionesPlaylist(pl.getIdPlaylist())
             << " | Usuario: " << pl.getIdSuscriptor()
             << endl;
    }
}

void PlaylistManager::listarPorUsuario(){
    auto v = cargarTodas();

    sort(v.begin(), v.end(), [](const Playlist& a, const Playlist& b){
        return a.getIdSuscriptor() < b.getIdSuscriptor();
    });

    for(auto &pl : v){
        cout << pl.getNombrePlaylist()
             << " | Usuario: " << pl.getIdSuscriptor()
             << " | Canciones: " << getCantidadCancionesPlaylist(pl.getIdPlaylist())
             << endl;
    }
}

// -------- CONSULTAS --------

bool PlaylistManager::consultarPorUsuario(int idSuscriptor){
    auto v = cargarTodas();
    if(v.empty()) return false;

    bool encontro=false;
    for(auto &pl : v){
        if(pl.getEstado() && pl.getIdSuscriptor()==idSuscriptor){
            cout << pl.getNombrePlaylist() << endl;
            encontro=true;
        }
    }
    return encontro;
}

bool PlaylistManager::consultarPorCantidadCanciones(int minCanciones){
    auto v = cargarTodas();
    if(v.empty()) return false;

    bool encontro=false;
    for(auto &pl : v){
        int cant = getCantidadCancionesPlaylist(pl.getIdPlaylist());
        if(pl.getEstado() && cant>=minCanciones){
            cout << pl.getNombrePlaylist()
                 << " | Canciones: " << cant << endl;
            encontro=true;
        }
    }
    return encontro;
}
