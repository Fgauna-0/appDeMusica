#pragma once
#include "CancionArchivo.h"
#include "Cancion.h"
#include "Artista.h"
#include "ArtistaArchivo.h"


class CancionManager
{
    public:
        CancionManager();
        void agregarCancion(int idArtista);


    private:

        CancionArchivo _repo;
};


