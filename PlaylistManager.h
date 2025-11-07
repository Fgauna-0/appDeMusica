#pragma once
#include "PlaylistArchivo.h"
#include "PlaylistCancionArchivo.h"


class PlaylistManager
{
    public:
        PlaylistManager();
        void crearPlaylist(int idSuscriptor);
        void mostrarPlaylistDelSuscriptor(int idSuscriptor);


    protected:

    private:
        PlaylistArchivo _repoPlaylist;
        PlaylistCancionArchivo _repoCancion;

};


