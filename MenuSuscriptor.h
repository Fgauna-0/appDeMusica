#pragma once
#include "SuscriptorManager.h"
#include "CancionManager.h"
#include "PlaylistManager.h"


class MenuSuscriptor
{
    public:
        MenuSuscriptor(SuscriptorManager& sm, CancionManager& cm, PlaylistManager& pm);
        void iniciar();

    protected:

    private:
        SuscriptorManager& _sm;
        CancionManager& _cm;
        PlaylistManager& _pm;


        void menuPrincipal();
        void menuBuscarCancion();
        void menuPerfil();
        void menuPlaylist();
        void menuModificarPerfil();
        void menuCrearPlaylist();
        void menuModificarPlaylist();
        void accionesSobreCancion(int idCancion);
        void buscarCancionesPorNombre();
        void buscarCancionesPorArtista();
        void modificarNombre();
        void modificarSuscripcion();
        bool verPlaylistsActuales();
        void crearPlaylist();
        void verDatosDelPerfil();
        void verCancionesDePlaylist();
        void eliminarPlaylist();
        void agregarCancionAPlaylist();
        void eliminarCancionDePlaylist();
        void reproducirPlaylist();
        void eliminarPerfil();

};


