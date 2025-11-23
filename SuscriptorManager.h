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
        bool modificarNombre(std::string nombre, Suscriptor& registro);
        bool modificarSuscripcion(int suscripcion, Suscriptor& registro);
        Suscriptor getSuscriptorActual();

    private:

        SuscriptorArchivo _repo;
        Suscriptor _suscriptorActual;
        bool _haySesion;
};


