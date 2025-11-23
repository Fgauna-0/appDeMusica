#pragma once
#include <string>
#include "PlaylistCancion.h"

class PlaylistCancionArchivo
{
    public:
        PlaylistCancionArchivo(std::string nombreArchivo = "playlist_canciones.dat");
        bool guardar(PlaylistCancion& registro);
        bool leer(int pos, PlaylistCancion& registro);
        int getCantidadRegistros();
        bool existeRelacion(int idPlaylist, int idCancion);
        int buscarPorId(int idCancion, int idPlaylist);


    private:
        std::string _nombreArchivo;
};


