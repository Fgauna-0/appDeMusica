#pragma once
#include "Genero.h"


class GeneroArchivo
{
    public:
        GeneroArchivo(std::string nombreArchivo = "generos.dat");
        bool guardar(Genero& genero);
        bool leer(int pos, Genero &registro);
        bool leerPorId(int id, Genero &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        bool eliminarGenero(int idGenero);

    protected:

    private:
        std::string _nombreArchivo;
};


