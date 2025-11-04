#pragma once
#include <string>

class PlaylistArchivo
{
    public:
        PlaylistArchivo(std::string nombreArchivo = "playlist.dat");

    protected:

    private:
        std::string _nombreArchivo;
};


