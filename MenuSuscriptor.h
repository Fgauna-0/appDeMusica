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
        Suscriptor _suscriptorActual;

        void menuPrincipal();
        void menuBuscarCancion();
        void menuModificarPerfil();
        void menuModificarPlaylist();
        void accionesSobreCancion(int idCancion);
        void buscarCancionesPorNombre();
        void buscarCancionesPorArtista();

};


