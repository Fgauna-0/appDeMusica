#pragma once
#include <string>
#include "Persona.h"
#include "Fecha.h"


class Suscriptor:public Persona
{
    public:
        Suscriptor();
        Suscriptor(int id, std::string dni, std::string nombre, bool estado, int reproducciones, int tipoSuscripcion, std::string apellido,
                   std::string telefono, std::string email, Fecha fechaNacimiento);

        ///Getters
        int getTipoSuscripcion();
        std::string getApellido();
        std::string getTelefono();
        std::string getEmail();
        Fecha getFechaNacimiento();

        ///Setters
        void setTipoSuscripcion(int tipoSuscripcion);
        void setApellido(std::string apellido);
        void setTelefono(std::string telefono);
        void setEmail(std::string email);
        void setFechaNacimiento(Fecha fechaNacimiento);

        ///Comportamientos
        std::string toCSV();

    private:
        int _tipoSuscripcion;
        char _apellido[21];
        char _telefono[11];
        char _email[61];
        Fecha _fechaNacimiento;

};


