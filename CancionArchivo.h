#pragma once
#include <string>
#include "Cancion.h"

class CancionArchivo
{
    public:
        CancionArchivo(std::string nombreArchivo = "canciones.dat");
        bool guardar(Cancion& cancion);
        bool leer(int pos, Cancion &registro);
        int getCantidadRegistros();




    private:
        std::string _nombreArchivo;

};

