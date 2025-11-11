#pragma once
#include "Genero.h"


class GeneroArchivo
{
    public:
        GeneroArchivo(std::string nombreArchivo = "generos.dat");
        bool guardar(Genero& genero);
        bool leer(int pos, Genero &registro);
        int getCantidadRegistros();
        int buscarId(int id);

    protected:

    private:
        std::string _nombreArchivo;
};


