#pragma once
#include <iostream>
#include "MenuSuscriptor.h"
#include "ArtistaManager.h"
#include "GeneroManager.h"



class MenuPrincipal
{
    public:
    MenuPrincipal();
    void iniciar();

    private:

    SuscriptorManager _sm;
    ArtistaManager _am;
    PlaylistManager _pm;
    CancionManager _cm;
    GeneroManager _gm;
};

