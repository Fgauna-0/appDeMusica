#ifndef MENUARTISTA_H_INCLUDED
#define MENUARTISTA_H_INCLUDED
#include "Artista.h"
#include "ArtistaArchivo.h"
#include "ArtistaManager.h"
#include "CancionArchivo.h"
#include "GeneroManager.h"

class MenuArtista {

public:
    MenuArtista(ArtistaManager &am);
    void iniciar();

private:

    void menuPrincipal();
    void menuPerfil();
    void menuCanciones();

    void verDatos();
    void modificarNombre();
    void modificarNacionalidad();
    void modificarContrasenia();

    void registrarCancion();
    void modificarCancion();
    void borrarCancion();

    void eliminarCuenta();

    void registrar();
    void iniciarSesion();

    ArtistaManager &_am;
    CancionArchivo _ca{"canciones.dat"};
    FuncionesGlobales fg;
};





#endif // MENUARTISTA_H_INCLUDED
