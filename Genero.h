#pragma once
#include <string>

class Genero
{
    public:
        Genero();
        Genero(int id, int reproducciones, std::string nombre, bool estado);

        ///Getters
        int getIdGenero();
        int getReproduccionesGenero();
        std::string getNombreGenero();
        bool getEstado();

        ///Setters
        void setIdGenero(int id);
        void setReproduccionesGenero(int reproducciones);
        void setNombreGenero(std::string nombre);
        void setEstado(bool estado);

        std::string toCSV();

        void sumarReproduccion();

    protected:

    private:
        int _idGenero;
        int _reproduccionesGenero;
        char _nombreGenero[31];
        bool _estado;
};


