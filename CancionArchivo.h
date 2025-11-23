#pragma once
#include <string>
#include "Cancion.h"
#include "FuncionesGlobales.h"

class CancionArchivo
{
    public:
        CancionArchivo(std::string nombreArchivo = "canciones.dat");
        bool guardar(Cancion& cancion);
        bool leer(int pos, Cancion &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        bool eliminarCancion(int idCancion);
        int buscarPorNombre(std::string nombre);

    private:
        std::string _nombreArchivo;

};

