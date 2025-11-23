#include <cstring>
#include "Artista.h"

Artista::Artista()
:Persona(){
    strcpy(_nacionalidad, "");
}

Artista::Artista(int id, std::string dni, std::string nombre, bool estado, int reproducciones, std::string nacionalidad, std::string contrasenia)
:Persona(id, dni, nombre, estado, reproducciones, contrasenia)
{
    setNacionalidad(nacionalidad);
}

///Getters
std::string Artista::getNacionalidad()const { return _nacionalidad; }


///Setters
void Artista::setNacionalidad(std::string nacionalidad){
    strncpy(_nacionalidad, nacionalidad.c_str(), sizeof(_nacionalidad) - 1);
    _nacionalidad[sizeof(_nacionalidad) - 1] = '\0';
}

void Artista::sumarReproduccion(){
    _reproducciones++;
}

/// MOSTRAMOS O EXPORTAMOS TEXTO
std::string Artista::toCSV(){
    return Persona::toCSV() +
    "," + std::string(_nacionalidad);
}
