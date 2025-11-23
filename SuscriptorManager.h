#pragma once
#include "SuscriptorArchivo.h"
#include "PlaylistManager.h"


class SuscriptorManager
{
    public:
        SuscriptorManager();
        void registrarSuscriptor();
        bool iniciarSesion();
        void cerrarSesion();
        bool haySesion();
        void modificarNombre();
        void modificarSuscripcion();
        Suscriptor getSuscriptorActual();

    private:

        SuscriptorArchivo _repo;
        Suscriptor _suscriptorActual;
        bool _haySesion;
};


