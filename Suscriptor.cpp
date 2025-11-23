#include <cstring>
#include "Suscriptor.h"


Suscriptor::Suscriptor()
: _fechaNacimiento(){
    _tipoSuscripcion = 0;
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Suscriptor::Suscriptor(int id, std::string dni, std::string nombre, bool estado, int reproducciones, int tipoSuscripcion, std::string apellido,
std::string telefono, std::string email, Fecha fechaNacimiento, std::string contrasenia)
:Persona(id,dni,nombre,estado,reproducciones, contrasenia){
    setTipoSuscripcion(tipoSuscripcion);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
}

///Getters
int Suscriptor::getTipoSuscripcion()const { return _tipoSuscripcion; }

std::string Suscriptor::getApellido()const { return _apellido; }

std::string Suscriptor::getTelefono()const { return _telefono; }

std::string Suscriptor::getEmail()const { return _email; }

Fecha Suscriptor::getFechaNacimiento()const { return _fechaNacimiento; }

void Suscriptor::setTipoSuscripcion(int tipoSuscripcion){
    _tipoSuscripcion = tipoSuscripcion;
}


///Setters
void Suscriptor::setApellido(std::string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}
void Suscriptor::setTelefono(std::string telefono){
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _apellido[sizeof(_telefono) - 1] = '\0';
}

void Suscriptor::setEmail(std::string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
    _apellido[sizeof(_email) - 1] = '\0';
}

void Suscriptor::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}


/// MOSTRAMOS O EXPORTAMOS TEXTO
std::string Suscriptor::toCSV(){
    return Persona::toCSV() +
    "," +  to_string(_tipoSuscripcion)+
    "," +  string(_apellido) +
    "," +  string(_telefono) +
    "," +  string(_email) +
    "," +  _fechaNacimiento.toCSV();

}

std::string Suscriptor::mostrarFechaDeNacimiento(){
    return _fechaNacimiento.toCSV();
}


