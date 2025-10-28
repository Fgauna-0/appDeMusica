#include <cstring>
#include "Suscriptor.h"


Suscriptor::Suscriptor()
: Persona(), _tipoSuscripcion(0), _apellido(" "), _telefono(" "), _email(" "), _fechaNacimiento(){

}

Suscriptor::Suscriptor(int id, std::string dni, std::string nombre, bool estado, int reproducciones, int tipoSuscripcion, std::string apellido,
std::string telefono, std::string email, Fecha fechaNacimiento)
:Persona(id,dni,nombre,estado,reproducciones){
    setTipoSuscripcion(tipoSuscripcion);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
}

int Suscriptor::getTipoSuscripcion(){
    return _tipoSuscripcion;
}

std::string Suscriptor::getApellido(){
    return _apellido;
}

std::string Suscriptor::getTelefono(){
    return _telefono;
}

std::string Suscriptor::getEmail(){
    return _email;
}

Fecha Suscriptor::getFechaNacimiento(){
    return _fechaNacimiento;
}

void Suscriptor::setTipoSuscripcion(int tipoSuscripcion){
    _tipoSuscripcion = tipoSuscripcion;
}

void Suscriptor::setApellido(std::string apellido){
    strncpy(_apellido, apellido.c_str(), 20);
    _apellido[20] = '\0';
}
void Suscriptor::setTelefono(std::string telefono){
    strncpy(_telefono, telefono.c_str(), 10);
    _apellido[10] = '\0';
}

void Suscriptor::setEmail(std::string email){
    strncpy(_email, email.c_str(), 60);
    _apellido[60] = '\0';
}

void Suscriptor::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

std::string Suscriptor::toCSV(){
    return Persona::toCSV() +
    "," +  to_string(_tipoSuscripcion)+
    "," +  string(_apellido) +
    "," +  string(_telefono) +
    "," +  string(_email) +
    "," +  _fechaNacimiento.toCSV();

}


