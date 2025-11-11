#pragma once
#include "CancionArchivo.h"
#include "Cancion.h"


class CancionManager
{
    public:
        CancionManager();
        void agregarCancion(int idArtista);


    private:

        CancionArchivo _repo;
};


