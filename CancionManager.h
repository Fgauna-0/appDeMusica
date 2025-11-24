#pragma once
#include "CancionArchivo.h"
#include "Cancion.h"
#include "ArtistaManager.h"
#include "GeneroManager.h"
#include "ReproduccionSuscriptorArchivo.h"
#include "SuscriptorManager.h"


class CancionManager
{
    public:
        CancionManager();
        void agregarCancion(int idArtista);
        void mostrarCancionPorId(int id);
        bool mostrarCancionesPorNombre(string nombre);
        bool mostrarCancionesPorArtista(string nombre);
        int reproducirCancion(int idCancion, int idSuscriptor);
        void mostrarMasEscuchadaPorUsuario(int idUsuario);
        void mostrarTodasLasCanciones();


    private:

        CancionArchivo _repo;
        ArtistaArchivo _repoArtista;
        GeneroArchivo _repoGenero;
        ReproduccionSuscriptorArchivo _repoRepro;

};


