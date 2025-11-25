#pragma once
#include <string>
#include <vector>
#include "Artista.h"
#include "ArtistaArchivo.h"
#include "CancionArchivo.h"


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

        /// CARGA
        std::vector<Artista> cargarTodos();

        // LISTADOS
        void listarPorNombre();
        void listarPorNacionalidad();
        void listarPorCantidadCanciones();

        // CONSULTAS
        bool consultarPorPais(std::string pais);
        bool consultarPorNombre(std::string nombreParcial);


    private:

        ArtistaArchivo _repo;
        Artista _artistaActual;
        bool _haySesion;

};


