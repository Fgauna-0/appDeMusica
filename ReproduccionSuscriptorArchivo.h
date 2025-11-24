#pragma once
#include <string>
#include "ReproduccionSuscriptor.h"

class ReproduccionSuscriptorArchivo
{
public:
    ReproduccionSuscriptorArchivo(std::string nombreArchivo = "reproducciones_suscriptores.dat");

    bool guardar(ReproduccionSuscriptor& registro);
    bool modificar(int pos, ReproduccionSuscriptor& registro);
    bool leer(int pos, ReproduccionSuscriptor& registro);

    int buscar(int idSuscriptor, int idCancion);
    int getCantidadRegistros();

private:
    std::string _nombreArchivo;
};
