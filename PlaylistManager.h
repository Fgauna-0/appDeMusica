#pragma once
#include "PlaylistArchivo.h"
#include "PlaylistCancionArchivo.h"
#include "CancionArchivo.h"
#include "SuscriptorManager.h"
#include "ArtistaManager.h"


class PlaylistManager
{
    public:
        PlaylistManager();
        void crearPlaylist(int idSuscriptor);
        void mostrarPlaylistDelSuscriptor(int idSuscriptor);
        int getCantidadCancionesPlaylist(int idPlaylist);
        void mostrarCancionesDePlaylist(int idPlaylist);
        void agregarCancionAPlaylistPorIdPlaylist(int idPlaylist);
        void agregarCancionAPlaylistPorIdPlaylistYIdCancion(int idPlaylist, int idCancion);
        void setSuscriptorActual(const Suscriptor& s);


    protected:

    private:
        PlaylistArchivo _repoPlaylist;
        PlaylistCancionArchivo _repoPlaylistCancion;
        ArtistaArchivo _repoArtista;
        CancionArchivo _repoCancion;
        Suscriptor _suscriptorActual;

};


