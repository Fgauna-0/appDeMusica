#include "Playlist.h"
#include <cstring>

Playlist::Playlist()
:_idPlaylist(0), _idSuscriptor(0), _reproducciones(0), _estado(false){
    strcpy(_nombrePlaylist, "");
}

Playlist::Playlist(int idPlaylist, int idSuscriptor, int reproducciones, std::string nombre, bool estado)
{
    setIdPlaylist(idPlaylist);
    setIdSuscriptor(idSuscriptor);
    setReproducciones(reproducciones);
    setNombrePlaylist(nombre);
    setEstado(estado);
}

///Getters
int Playlist::getIdPlaylist()const { return _idPlaylist;}

int Playlist::getIdSuscriptor() const { return _idSuscriptor;}

int Playlist::getReproducciones() const { return _reproducciones;}

std::string Playlist::getNombrePlaylist() const{return _nombrePlaylist;}

bool Playlist::getEstado()const {return _estado;}

///Setters
void Playlist::setIdPlaylist(int id){
    _idPlaylist = id;
}

void Playlist::setIdSuscriptor(int idSuscriptor){
    _idSuscriptor = idSuscriptor;
}

void Playlist::setReproducciones(int reproducciones){
    _reproducciones = reproducciones;
}

void Playlist::setNombrePlaylist(std::string nombre){
    strncpy(_nombrePlaylist, nombre.c_str(), sizeof(_nombrePlaylist) - 1);
    _nombrePlaylist[sizeof(_nombrePlaylist) - 1] = '\0';

}
void Playlist::setEstado(bool estado){
    _estado = estado;
}

void Playlist::sumarReproduccion(){
    _reproducciones++;
}
