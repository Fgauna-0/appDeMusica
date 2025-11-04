#pragma once
#include "SuscriptorArchivo.h"


class SuscriptorManager
{
    public:
        SuscriptorManager();
        void registrarSuscriptor();
        void modificarNombre();
        void modificarSuscripcion();




    protected:

    private:

        SuscriptorArchivo _repo;
};


