#pragma once
#include <string>
#include "Cancion.h"

class CancionArchivo
{
    public:
        CancionArchivo(std::string nombreArchivo = "canciones.dat");
        bool guardar(Cancion registro);




    private:
        std::string _nombreArchivo;

};

