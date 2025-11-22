#pragma once
#include "CancionArchivo.h"
#include "Cancion.h"
#include "ArtistaManager.h"
#include "GeneroManager.h"


class CancionManager
{
    public:
        CancionManager();
        void agregarCancion(int idArtista);
        void mostrarCancionPorId(int id);


    private:

        CancionArchivo _repo;
};


