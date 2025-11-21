#pragma once
#include <string>
#include "Artista.h"


class ArtistaArchivo
{
    public:
        ArtistaArchivo(std::string nombreArchivo = "artistas.dat");
        bool guardar(Artista& artista);
        bool leer(int pos, Artista &registro);
        int getCantidadRegistros();
        int buscarId(int id);

    protected:

    private:
        std::string _nombreArchivo;
};


