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
#include "ArtistaManager.h"
#include "CancionManager.h"

using namespace std;

int main()
{
    CancionManager c;
    ArtistaManager a;

    a.iniciarSesion();

    c.agregarCancion(a.getArtistaActual().getId());


    c.mostrarCancionPorId(1);


    return 0;
}
