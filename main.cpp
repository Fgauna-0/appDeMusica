#include <iostream>
#include "Cancion.h"
#include "Persona.h"
#include "Artista.h"
#include "Fecha.h"
#include "Suscriptor.h"
#include "SuscriptorArchivo.h"
#include "PlaylistManager.h"

using namespace std;

int main()
{

    PlaylistManager a;

    ///a.crearPlaylist(1);

    //a.mostrarPlaylistDelSuscriptor(1);

    a.mostrarCancionesDePlaylist(1);

    return 0;
}
