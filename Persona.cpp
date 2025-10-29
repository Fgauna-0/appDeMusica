#include <cstring>
#include "Persona.h"

Persona::Persona(){
    _id = 0;
    _reproducciones = 0;
    _estado = false;

    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_contrasenia, "");

}

Persona::Persona(int id, std::string dni, std::string nombre, bool estado, int reproducciones, std::string contrasenia){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setEstado(estado);
    setReproducciones(reproducciones);
    setContrasenia(contrasenia);
}

// GETTERS
int Persona::getId() const { return _id; }

std::string Persona::getDni() const { return _dni; }

std::string Persona::getNombre() const { return _nombre; }

bool Persona::getEstado() const { return _estado; }

int Persona::getReproducciones() const { return _reproducciones; }

std::string Persona::getContrasenia() const { return _contrasenia; }


// SETTERS
void Persona::setId(int id){
    _id = id;
}

void Persona::setDni(std::string dni){
    strncpy(_dni, dni.c_str(), sizeof(_dni) - 1);
    _dni[sizeof(_dni) - 1] = '\0';
}

void Persona::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Persona::setEstado(bool estado){
    _estado = estado;
}

void Persona::setReproducciones(int reproducciones){
    _reproducciones = reproducciones;
}

void Persona::setContrasenia(std::string contrasenia){
    strncpy(_contrasenia, contrasenia.c_str(), sizeof(_contrasenia) - 1);
    _contrasenia[sizeof(_contrasenia) - 1] = '\0';
}

// MOSTRAMOS O EXPORTAMOS TEXTO
std::string Persona::toCSV(){
    return std::to_string(_id) +
    "," + std::string(_dni)   +
    "," + std::string(_nombre)+
    "," + std::to_string(_estado)+
    "," + std::to_string(_reproducciones) +
    "," + std::string(_contrasenia);
}

