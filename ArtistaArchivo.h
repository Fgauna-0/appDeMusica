#pragma once
#include <string>
#include "Artista.h"
#include "FuncionesGlobales.h"


class ArtistaArchivo
{
    public:
        ArtistaArchivo(std::string nombreArchivo = "artistas.dat");
        bool guardar(Artista& artista);
        bool leer(int pos, Artista &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        bool eliminarArtista(Artista &registro);
        int buscarPorNombre(std::string nombre);
        int buscarPorDni(std::string dni);

    protected:

    private:
        std::string _nombreArchivo;
};


