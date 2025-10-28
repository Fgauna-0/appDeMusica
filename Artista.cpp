#include <cstring>
#include "Artista.h"

Artista::Artista()
:Persona(), _nacionalidad(" "){
}

Artista::Artista(int id, std::string dni, std::string nombre, bool estado, int reproducciones, std::string nacionalidad)
:Persona(id, dni, nombre, estado, reproducciones)
{
    setNacionalidad(nacionalidad);
}

std::string Artista::getNacionalidad(){
    return _nacionalidad;
}

void Artista::setNacionalidad(std::string nacionalidad){
    strncpy(_nacionalidad, nacionalidad.c_str(), 30);
    _nacionalidad[30] = '\0';
}

std::string Artista::toCSV(){
    return Persona::toCSV() +
    "," + std::string(_nacionalidad);
}
