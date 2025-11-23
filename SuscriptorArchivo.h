#pragma once
#include <string>
#include "Suscriptor.h"


class SuscriptorArchivo
{
    public:
        SuscriptorArchivo(std::string nombreArchivo = "suscriptor.dat");
        bool guardar(Suscriptor suscriptor);
        bool leer(int pos, Suscriptor& registro);
        int buscarId(int id);
        int getCantidadRegistros();
        int getNuevoId();
        int buscarPorDni(std::string dni);
        int buscarPorEmail(std::string email);

    private:
        std::string _nombreArchivo;
};

