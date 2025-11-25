#pragma once
#include <iostream>
#include "MenuSuscriptor.h"
#include "ArtistaManager.h"
#include "GeneroManager.h"
#include "ArtistaManager.h"
#include "MenuAdministrador.h"



class MenuPrincipal
{
    public:
    MenuPrincipal(SuscriptorManager& sm, ArtistaManager& am, CancionManager& cm, PlaylistManager& pm);
    void iniciar();

    private:

    SuscriptorManager &_sm;
    ArtistaManager &_am;
    CancionManager &_cm;
    PlaylistManager &_pm;
    FuncionesGlobales fg;
};

