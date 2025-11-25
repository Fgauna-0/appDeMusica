#pragma once
#include <vector>
#include <cstring>
#include <map>
#include "CancionArchivo.h"
#include "Cancion.h"
#include "ArtistaManager.h"
#include "GeneroManager.h"
#include "ReproduccionSuscriptorArchivo.h"
#include "SuscriptorManager.h"


class CancionManager
{
    public:
        CancionManager();
        void agregarCancion(int idArtista);
        void mostrarCancionPorId(int id);
        bool mostrarCancionesPorNombre(string nombre);
        bool mostrarCancionesPorArtista(string nombre);
        bool mostrarCancionesPorGenero(string nombre);
        int reproducirCancion(int idCancion, int idSuscriptor);
        void mostrarMasEscuchadaPorUsuario(int idUsuario);
        void mostrarTodasLasCanciones();

        vector<Cancion> cargarTodas();
        void mostrar(const Cancion& c);

        // LISTADOS
        void listarPorTitulo();
        void listarPorFecha();
        void listarPorGenero();
        void listarPorArtista();
        void listarPorNacionalidad();

        // CONSULTAS
        void consultarPorNombreGenero(string nombreGenero);
        void consultarPorNombreArtista(string nombreArtista);
        void consultarPorAnio(int anio);
        void consultarPorPais(string pais);
        bool consultarPorTitulo(string titulo);

    private:

        CancionArchivo _repo;
        ArtistaArchivo _repoArtista;
        GeneroArchivo _repoGenero;
        ReproduccionSuscriptorArchivo _repoRepro;

};


