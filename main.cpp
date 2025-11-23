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
#include "SuscriptorManager.h"
#include "FuncionesGlobales.h"

using namespace std;

int main()
{

    Playlist p;
    PlaylistArchivo pa;
    PlaylistCancion pc;
    PlaylistCancionArchivo pca;
    PlaylistManager pm;
    SuscriptorManager sm;
    SuscriptorArchivo sa;
    Suscriptor s;
    ArtistaManager am;
    Artista a;
    ArtistaArchivo aa;
    Cancion c;
    CancionArchivo ca;
    CancionManager cm;
    Genero g;
    GeneroArchivo ga;
    GeneroManager gm;

   /* int pos = sa.buscarId(1);

    sa.leer(pos, ss);

    cout << "Nombre: " << ss.getNombre() << endl;
    cout << "Apellido: " << ss.getApellido() << endl;
    cout << "Contrasenia: " << ss.getContrasenia() << endl;
    cout << "DNI: " << ss.getDni() << endl;
    cout << "Email: " << ss.getEmail() << endl;
    cout << "Estado: " << ss.getEstado() << endl;
    cout << "Fecha de nacimiento: " << ss.mostrarFechaDeNacimiento() << endl;
    cout << "ID: " << ss.getId() << endl;
    cout << "Reproducciones: " << ss.getReproducciones() << endl;
    cout << "Telefono: " << ss.getTelefono() << endl;
    cout << "Tipo de suscripccion: " << ss.getTipoSuscripcion() << endl;*/


    /*s.iniciarSesion();


    cout << "Nombre: " << s.getSuscriptorActual().getNombre() << endl;
    cout << "Apellido: " << s.getSuscriptorActual().getApellido() << endl;
    cout << "Contrasenia: " << s.getSuscriptorActual().getContrasenia() << endl;
    cout << "DNI: " << s.getSuscriptorActual().getDni() << endl;
    cout << "Email: " << s.getSuscriptorActual().getEmail() << endl;
    cout << "Estado: " << s.getSuscriptorActual().getEstado() << endl;
    cout << "Fecha de nacimiento: " << s.getSuscriptorActual().mostrarFechaDeNacimiento() << endl;
    cout << "ID: " << s.getSuscriptorActual().getId() << endl;
    cout << "Reproducciones: " << s.getSuscriptorActual().getReproducciones() << endl;
    cout << "Telefono: " << s.getSuscriptorActual().getTelefono() << endl;
    cout << "Tipo de suscripccion: " << s.getSuscriptorActual().getTipoSuscripcion() << endl << endl << endl;

    p.mostrarPlaylistDelSuscriptor(1);*/


    /*int posA = aa.buscarId(1);

    aa.leer(posA, a);

    cout << "Nombre: " << a.getNombre() << endl;
    cout << "Nacionalidad: " <<a.getNacionalidad()<< endl;
    cout << "ID: " <<a.getId()<< endl;
    cout << "DNI: " <<a.getDni()<< endl;
    cout << "Contrasenia: " <<a.getContrasenia()<< endl;
    cout << "Estado: " <<a.getEstado()<< endl;
    cout << "Reproducciones: " <<a.getReproducciones()<< endl;*/

    /*am.iniciarSesion();

    cout << "Nombre: " << am.getArtistaActual().getNombre() << endl;
    cout << "Nacionalidad: " <<am.getArtistaActual().getNacionalidad()<< endl;
    cout << "ID: " <<am.getArtistaActual().getId()<< endl;
    cout << "DNI: " <<am.getArtistaActual().getDni()<< endl;
    cout << "Contrasenia: " <<am.getArtistaActual().getContrasenia()<< endl;
    cout << "Estado: " <<am.getArtistaActual().getEstado()<< endl;
    cout << "Reproducciones: " <<am.getArtistaActual().getReproducciones()<< endl;*/

    /*int posG = ga.buscarId(1);

    ga.leer(posG, g);

    cout << "Estado: " << g.getEstado() << endl;
    cout << "ID: " <<g.getIdGenero()<< endl;
    cout << "Nombre: " <<g.getNombreGenero()<< endl;
    cout << "Reproducciones: " <<g.getReproduccionesGenero()<< endl;*/

    /*int posC = ca.buscarId(1);

    ca.leer(posC, c);

    cout << "Nombre: " << c.getNombreCancion() << endl;
    cout << "Estado: " << c.getEstado() << endl;
    cout << "Fecha: " << c.getFecha().toCSV() << endl;
    cout << "ID ARTISTA: " << c.getIdArtista() << endl;
    cout << "ID CANCION: " << c.getIdCancion() << endl;
    cout << "ID GENERO: " << c.getIdGenero() << endl;
    cout << "Reproducciones: " << c.getReproduccionesCancion() << endl;*/

    sm.iniciarSesion();

    pm.setSuscriptorActual(sm.getSuscriptorActual());

    pm.mostrarCancionesDePlaylist(1);

    /*int pos = pca.buscarPorId(1,1);

    pca.leer(pos,pc);

    cout << "ID CANCION: " << pc.getIdCancion() << endl;
    cout << "ID PLAYLIST: " << pc.getIdPlaylist() << endl;
    cout << "ESTADO: " << pc.getEstado() << endl;*/

    /*pc.setEstado(1);
    pc.setIdCancion(1);
    pc.setIdPlaylist(1);

    pca.guardar(pc);

    int pos = pca.buscarPorId(1,1);

    PlaylistCancion pcAux;

    pca.leer(pos, pcAux);

    cout << "ID CANCION: " << pcAux.getIdCancion() << endl;
    cout << "ID PLAYLIST: " << pcAux.getIdPlaylist() << endl;
    cout << "ESTADO: " << pcAux.getEstado() << endl;*/


    return 0;
}
