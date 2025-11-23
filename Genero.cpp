#include <cstring>
#include "Genero.h"

using namespace std;

Genero::Genero()
: _idGenero(0), _reproduccionesGenero(0), _estado(0){
    strcpy(_nombreGenero, "");
}

Genero::Genero(int id, int reproducciones, string nombre, bool estado){
    setIdGenero(id);
    setReproduccionesGenero(reproducciones);
    setNombreGenero(nombre);
    setEstado(estado);
}


///Getters
int Genero::getIdGenero(){ return _idGenero; }

int Genero::getReproduccionesGenero(){ return _reproduccionesGenero; }

string Genero::getNombreGenero(){ return _nombreGenero; }

bool Genero::getEstado(){ return _estado; }


///Setters
void Genero::setIdGenero(int id){
    _idGenero = id;
}

void Genero::setReproduccionesGenero(int reproducciones){
    _reproduccionesGenero = reproducciones;
}

void Genero::setNombreGenero(string nombre){
    strncpy(_nombreGenero, nombre.c_str(),sizeof(_nombreGenero) - 1);
    _nombreGenero[sizeof(_nombreGenero) - 1] = '\0';
}

void Genero::setEstado(bool estado){
    _estado = estado;
}

/// MOSTRAMOS O EXPORTAMOS TEXTO
string Genero::toCSV(){

    return to_string(_idGenero) +
    "," + string(_nombreGenero) +
    "," + to_string(_estado) +
    "," + to_string(_reproduccionesGenero);
}

void Genero::sumarReproduccion(){
    _reproduccionesGenero++;
}
