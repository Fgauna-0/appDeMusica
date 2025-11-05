#include "PlaylistCancion.h"

PlaylistCancion::PlaylistCancion()
:_idPlaylist(0), _idCancion(0), _estado(0){

}

PlaylistCancion::PlaylistCancion(int idPlaylist, int idCancion, bool estado){
    setIdPlaylist(idPlaylist);
    setIdCancion(idCancion);
    setEstado(estado);
}


///Getters
int PlaylistCancion::getIdPlaylist(){ return _idPlaylist;}
int PlaylistCancion::getIdCancion(){ return _idCancion;}
bool PlaylistCancion::getEstado(){ return _estado;}

///Setters
void PlaylistCancion::setIdPlaylist(int id){
    _idPlaylist = id;
}

void PlaylistCancion::setIdCancion(int id){
    _idCancion = id;
}

void PlaylistCancion::setEstado(bool estado){
    _estado = estado;
}
