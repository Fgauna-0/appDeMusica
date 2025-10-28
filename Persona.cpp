#include <cstring>
#include "Persona.h"

Persona::Persona()
:_id(0), _reproducciones(0), _dni(" "), _nombre(" "), _estado(0) {

}

Persona::Persona(int id, std::string dni, std::string nombre, bool estado, int reproducciones){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setEstado(estado);
    setReproducciones(reproducciones);
}

int Persona::getId(){
    return _id;
}

std::string Persona::getDni(){
    return _dni;
}

std::string Persona::getNombre(){
    return _nombre;
}

bool Persona::getEstado(){
    return _estado;
}

int Persona::getReproducciones(){
    return _reproducciones;
}

void Persona::setId(int id){
    _id = id;
}

void Persona::setDni(std::string dni){
    strncpy(_dni,dni.c_str(),8);
    _dni[8] = '\0';
}

void Persona::setNombre(std::string nombre){
    strncpy(_nombre,nombre.c_str(),20);
    _nombre[20] = '\0';
}

void Persona::setEstado(bool estado){
    _estado = estado;
}

void Persona::setReproducciones(int reproducciones){
    _reproducciones = reproducciones;
}

std::string Persona::toCSV(){
    return std::to_string(_id) +
    "," + std::string(_dni)   +
    "," + std::string(_nombre)+
    "," + std::to_string(_estado)+
    "," + std::to_string(_reproducciones);
}

