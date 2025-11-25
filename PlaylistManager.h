#pragma once
#include "PlaylistArchivo.h"
#include "PlaylistCancionArchivo.h"
#include "CancionManager.h"
#include "SuscriptorManager.h"
#include "ArtistaManager.h"


class PlaylistManager
{
    public:
        PlaylistManager();
        bool crearPlaylist(int idSuscriptor, string nombre);
        bool mostrarPlaylistDelSuscriptor(int idSuscriptor);
        int getCantidadCancionesPlaylist(int idPlaylist);
        void mostrarCancionesDePlaylist(int idPlaylist);
        void agregarCancionAPlaylistPorIdPlaylist(int idPlaylist);
        bool agregarCancionAPlaylistPorIdPlaylistYIdCancion(int idPlaylist, int idCancion);
        void setSuscriptorActual(const Suscriptor& s);
        void eliminarPlaylist(int id);
        bool eliminarCancionDePlaylist(int idPlaylist, int idCancion);

        std::vector<Playlist> cargarTodas();

        void listarPorNombre();
        void listarPorCantidadCanciones();
        void listarPorUsuario();

        bool consultarPorUsuario(int idSuscriptor);
        bool consultarPorCantidadCanciones(int minCanciones);



    protected:

    private:
        PlaylistArchivo _repoPlaylist;
        PlaylistCancionArchivo _repoPlaylistCancion;
        ArtistaArchivo _repoArtista;
        CancionArchivo _repoCancion;
        Suscriptor _suscriptorActual;
        FuncionesGlobales fg;

};

