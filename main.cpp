#include <iostream>
#include "Cancion.h"
#include "Persona.h"
#include "Artista.h"
#include "Fecha.h"
#include "Suscriptor.h"
#include "SuscriptorArchivo.h"
#include "PlaylistManager.h"
#include "Genero.h"
#include "GeneroArchivo.h"
#include "GeneroManager.h"

using namespace std;

int main()
{

    ///PlaylistManager a;

    GeneroManager g;

    g.listarGeneros();



    ///a.crearPlaylist(1);

    //a.mostrarPlaylistDelSuscriptor(1);

    ///a.mostrarCancionesDePlaylist(1);

    return 0;
}
