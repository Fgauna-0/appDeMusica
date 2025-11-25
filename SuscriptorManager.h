#pragma once
#include "SuscriptorArchivo.h"
#include "PlaylistManager.h"
#include "FuncionesGlobales.h"


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
        Suscriptor& getSuscriptorActual();
        void sumarReproduccionAlSuscriptor();
        bool eliminarCuenta(Suscriptor& registro);

    private:

        SuscriptorArchivo _repo;
        Suscriptor _suscriptorActual;
        FuncionesGlobales fg;
        bool _haySesion;
};


