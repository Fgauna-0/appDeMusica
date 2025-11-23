#pragma once
#include <string>
#include "Persona.h"

class Artista:public Persona
{
    public:
        Artista();
        Artista(int id, std::string dni, std::string nombre, bool estado, int reproducciones, std::string nacionalidad, std::string contrasenia);

        ///Getters
        std::string getNacionalidad() const;

        ///Setters
        void setNacionalidad(std::string nacionalidad);

        ///
        std::string toCSV();

        void sumarReproduccion();

    private:
        char _nacionalidad[31];
};


