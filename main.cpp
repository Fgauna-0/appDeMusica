#include <iostream>
#include "MenuSuscriptor.h"

using namespace std;

int main()
{

    SuscriptorManager sm;
    PlaylistManager pm;
    CancionManager cm;

    if(sm.iniciarSesion()){

        pm.setSuscriptorActual(sm.getSuscriptorActual());

        MenuSuscriptor ms(sm,cm,pm);
        ms.iniciar();
    }


    return 0;
}
