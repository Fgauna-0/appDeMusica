#include "Playlist.h"
#include <cstring>

Playlist::Playlist()
{

}

///Getters
int Playlist::getIdPlaylist(){ return _idPlaylist;}

int Playlist::getIdSuscriptor(){ return _idSuscriptor;}

int Playlist::getIdCancion(){ return _idCancion;}

int Playlist::getReproducciones(){ return _reproducciones;}

std::string Playlist::getNombrePlaylist(){return _nombrePlaylist;}

bool Playlist::getEstado(){return _estado;}

///Setters
void Playlist::setIdPlaylist(int id){
    _idPlaylist = id;
}

void Playlist::setIdSuscriptor(int idSuscriptor){
    _idSuscriptor = idSuscriptor;
}

void Playlist::setIdCancion(int idCancion){
    _idCancion = idCancion;
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

