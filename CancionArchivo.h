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
        bool leerPorId(int id, Cancion &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        bool eliminarCancion(int idCancion);
        int buscarPorNombre(std::string nombre);
        bool modificar(int pos, Cancion& registro);

    private:
        std::string _nombreArchivo;

};

