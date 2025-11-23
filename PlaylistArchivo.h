#pragma once
#include <string>
#include "Playlist.h"

class PlaylistArchivo
{
    public:
        PlaylistArchivo(std::string nombreArchivo = "playlist.dat");
        bool guardar(Playlist& registro);
        bool leer(int pos, Playlist& registro);
        int getCantidadRegistros();
        int buscarPorId(int id);
        int getNuevoId();
        bool eliminarPlaylist(int idPlaylist);


    private:
        std::string _nombreArchivo;
};


