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
        void mostrarCancionesPorNombre(string nombre);
        void mostrarCancionesPorArtista(string nombre);


    private:

        CancionArchivo _repo;
        ArtistaArchivo _repoArtista;
};


