#pragma once
#include "Genero.h"
#include "GeneroArchivo.h"


class GeneroManager
{
    public:
        GeneroManager();
        void agregarGenero();
        void mostrarGeneroPorId(int id);
        void listarGeneros();

    protected:

    private:
        GeneroArchivo _repo;
};


