#pragma once
#include "Artista.h"
#include "ArtistaArchivo.h"


class ArtistaManager
{
    public:
        ArtistaManager();
        void registrarArtista();
        void mostrarArtistaPorId(int id);
        bool iniciarSesion();
        void cerrarSesion();
        Artista getArtistaActual();
        bool getHaySesion();

    private:

        ArtistaArchivo _repo;
        Artista _artistaActual;
        bool _haySesion;

};


