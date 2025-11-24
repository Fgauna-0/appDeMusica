#pragma once
#include "MenuPrincipal.h"

class AppMusica
{
    public:
        AppMusica();
        void iniciar();


    private:
    SuscriptorManager sm;
    ArtistaManager am;
    PlaylistManager pm;
    CancionManager cm;
    GeneroManager gm;

};


