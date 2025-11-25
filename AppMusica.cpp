#include "AppMusica.h"

AppMusica::AppMusica()
{
    //ctor
}

void AppMusica::iniciar() {

    SuscriptorManager sm;
    ArtistaManager am;
    CancionManager cm;
    PlaylistManager pm;

    MenuPrincipal mp(sm, am, cm, pm);
    mp.iniciar();
}
