#pragma once
#include <string>
#include "Cancion.h"
#include "FuncionesGlobales.h"

class CancionArchivo {
public:
    CancionArchivo(const std::string& nombreArchivo = "canciones.dat");

    bool guardar(Cancion &cancion);
    bool leer(int pos, Cancion &registro);
    bool leerPorId(int id, Cancion &registro);
    int getCantidadRegistros();
    int buscarId(int id);
    int getNuevoId();
    int buscarPorNombre(int idArtista, const std::string &nombre);
    bool modificar(int pos, Cancion &registro);
    bool borrarCancion(int idArtista, const std::string &nombreCancion);

private:
    std::string _nombreArchivo;
};
