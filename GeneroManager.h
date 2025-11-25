#pragma once
#include "Genero.h"
#include "GeneroArchivo.h"
#include "FuncionesGlobales.h"


class GeneroManager
{
    public:
        GeneroManager();
        void agregarGenero();
        void mostrarGeneroPorId(int id);
        void listarGeneros();
        bool verificarGeneroExistente(std::string nombre);

    protected:

    private:
        GeneroArchivo _repo;
};


