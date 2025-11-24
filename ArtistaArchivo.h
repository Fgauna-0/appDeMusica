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
        bool leerPorId(int id, Artista &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        int buscarPorNombre(std::string nombre);
        int buscarPorDni(std::string dni);
        bool modificar(int pos, Artista& registro);

    protected:

    private:
        std::string _nombreArchivo;
};


