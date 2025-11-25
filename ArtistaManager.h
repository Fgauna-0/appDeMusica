#pragma once
#include <string>
#include "Artista.h"
#include "ArtistaArchivo.h"


class ArtistaManager
{
    public:
        ArtistaManager();
        bool registrarArtista();
        bool iniciarSesion(const std::string& dni, const std::string& contrasenia);
        void cerrarSesion();
        Artista& getArtistaActual();

        bool haySesion();


        bool modificarNombre(const std::string &nuevoNombre);
        bool modificarNacionalidad(const std::string &nuevaNac);
        bool modificarContrasenia(const std::string &nuevaPass);
        void mostrarArtistaPorId(int id);


        bool eliminarCuenta();

    private:

        ArtistaArchivo _repo;
        Artista _artistaActual;
        bool _haySesion;

};


