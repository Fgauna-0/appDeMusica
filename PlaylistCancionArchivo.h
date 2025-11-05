#pragma once
#include <string>
#include "PlaylistCancion.h"

class PlaylistCancionArchivo
{
    public:
        PlaylistCancionArchivo(std::string nombreArchivo = "playlist_canciones.dat");
        bool guardar(PlaylistCancion& registro);
        PlaylistCancion leer(int pos, PlaylistCancion& registro);
        int getCantidadRegistros();



    private:
        std::string _nombreArchivo;
};


