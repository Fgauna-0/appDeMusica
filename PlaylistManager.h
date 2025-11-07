#pragma once
#include "PlaylistArchivo.h"
#include "PlaylistCancionArchivo.h"
#include "CancionArchivo.h"


class PlaylistManager
{
    public:
        PlaylistManager();
        void crearPlaylist(int idSuscriptor);
        void mostrarPlaylistDelSuscriptor(int idSuscriptor);
        int getCantidadCancionesPlaylist(int idPlaylist);
        void mostrarCancionesDePlaylist(int idPlaylist);




    protected:

    private:
        PlaylistArchivo _repoPlaylist;
        PlaylistCancionArchivo _repoCancion;

};


