#include "ArtistaManager.h"
#include "MenuArtista.h"
#include <iostream>
#include <limits>
using namespace std;

MenuArtista::MenuArtista(ArtistaManager &am) : _am(am) {}

void MenuArtista::iniciar() {

    int opcion;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#             MENU ARTISTA             #" << endl;
        cout << "=======================================" << endl;
        cout << "1. Iniciar sesion\n";
        cout << "2. Registrarse\n";
        cout << "0. Volver\n";
        opcion = fg.leerIntSeguro("Opcion: ");

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;

            case 2:
                registrar();
                break;

            case 0:
                return;
        }

    } while (true);
}

void MenuArtista::iniciarSesion() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "#           INICIAR SESION            #" << endl;
    cout << "=======================================" << endl;
    string nombre, contra;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Contrasenia: ";
    getline(cin, contra);

    if (_am.iniciarSesion(nombre, contra)) {
        menuPrincipal();
    } else {
        cout << "\nDatos incorrectos.\n";
        system("pause");
    }
}

void MenuArtista::registrar() {
    system("cls");
    if (_am.registrarArtista()) {
        cout << "\nRegistro completado con exito.\n";
    } else {
        cout << "\nNo se pudo completar el registro.\n";
    }
    system("pause");
}

void MenuArtista::menuPrincipal() {

    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#          PANEL DEL ARTISTA          #" << endl;
        cout << "=======================================" << endl;

        cout << "Artista: " << _am.getArtistaActual().getNombre() << endl;
        cout << "1. Menu del perfil\n";
        cout << "2. Menu de canciones\n";
        cout << "0. Cerrar sesion\n";
        opcion = fg.leerIntSeguro("Opcion: ");

        switch (opcion) {

            case 1:
                menuPerfil();
                break;

                case 2:
                menuCanciones();
                break;

            case 0:
                _am.cerrarSesion();
                return;
        }

    } while (true);
}

void MenuArtista::menuPerfil() {

    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#               PERFIL                #" << endl;
        cout << "=======================================" << endl;

        cout << "1. Ver datos personales\n";
        cout << "2. Modificar nombre artistico\n";
        cout << "3. Modificar nacionalidad\n";
        cout << "4. Cambiar contrasenia\n";
        cout << "5. Eliminar cuenta\n";
        cout << "0. Volver\n";
        opcion = fg.leerIntSeguro("Opcion: ");

        switch (opcion) {
            case 1:
                verDatos();
                break;

            case 2:
                modificarNombre();
                break;

            case 3:
                modificarNacionalidad();
                break;

            case 4:
                modificarContrasenia();
                break;

            case 5:
                eliminarCuenta();
                return;

            case 0:
                return;
        }

    } while (true);
}

void MenuArtista::verDatos() {

    system("cls");
    Artista a = _am.getArtistaActual();

    cout << "Nombre: " << a.getNombre() << endl;
    cout << "DNI: " << a.getDni() << endl;
    cout << "Nacionalidad: " << a.getNacionalidad() << endl;
    cout << "Reproducciones: " << a.getReproducciones() << endl;

    system("pause");
}

void MenuArtista::modificarNombre() {

    system("cls");

    string nuevo;
    cout << "Nuevo nombre artistico: ";
    getline(cin, nuevo);

    if (_am.modificarNombre(nuevo))
        cout << "\nNombre actualizado!\n";
    else
        cout << "\nError al actualizar.\n";

    system("pause");
}

void MenuArtista::modificarNacionalidad() {

    system("cls");

    string nueva;
    cout << "Nueva nacionalidad: ";
    getline(cin, nueva);

    if (_am.modificarNacionalidad(nueva))
        cout << "\nNacionalidad actualizada!\n";
    else
        cout << "\nError.\n";

    system("pause");
}

void MenuArtista::modificarContrasenia() {

    system("cls");

    string nueva;
    cout << "Nueva contrasenia: ";
    getline(cin, nueva);

    if (_am.modificarContrasenia(nueva))
        cout << "\nContrasenia actualizada!\n";
    else
        cout << "\nError.\n";

    system("pause");
}

void MenuArtista::eliminarCuenta() {

    system("cls");

    cout << "¿Seguro que quiere eliminar su cuenta?\n";
    cout << "1. Si\n2. No\nOpcion: ";
    int op;
    op = fg.leerIntSeguro("Opcion: ");

    if (op == 1) {
        if (_am.eliminarCuenta())
            cout << "\nCuenta eliminada.\n";
        else
            cout << "\nError al eliminar.\n";

        system("pause");
    }
}

void MenuArtista::menuCanciones() {
    int opcion;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#            GESTOR CANCIONES         #" << endl;
        cout << "=======================================" << endl;
        cout << "1. Registrar nueva cancion\n";
        cout << "2. Modificar cancion existente\n";
        cout << "3. Borrar cancion\n";
        cout << "0. Volver\n";
        opcion = fg.leerIntSeguro("Opcion: ");

        switch(opcion) {
            case 1:
                registrarCancion();
                break;
            case 2:
                modificarCancion();
                break;
            case 3:
                borrarCancion();
                break;
            case 0:
                return;
        }

    } while(true);
}

void MenuArtista::registrarCancion() {
    system("cls");
    string nombre, genero;
    float duracion;

    cout << "Nombre de la cancion: ";
    getline(cin, nombre);

    duracion = fg.leerIntSeguro("Duracion (minutos): ");

    cout << "Genero: ";
    getline(cin, genero);

    Cancion c;
    c.setIdCancion(_ca.getNuevoId());
    c.setIdArtista(_am.getArtistaActual().getId());
    c.setNombreCancion(nombre);
    Fecha hoy;
    c.setFecha(hoy);
    c.setEstado(true);
    c.setDuracion(duracion);
    c.setGenero(genero);

    if (_ca.guardar(c))
        cout << "\nCancion registrada con exito.\n";
    else
        cout << "\nError al registrar cancion.\n";

    system("pause");
}

void MenuArtista::modificarCancion() {
    system("cls");

    string nombreOriginal, nuevoNombre, genero;
    float duracion;

    cout << "Nombre de la cancion a modificar: ";
    getline(cin, nombreOriginal);

    int pos = _ca.buscarPorNombre(_am.getArtistaActual().getId(), nombreOriginal);
    if(pos == -1){
        cout << "\nNo se encontro la cancion.\n";
        system("pause");
        return;
    }

    Cancion c;
    _ca.leer(pos, c);

    cout << "Nuevo nombre: ";
    getline(cin, nuevoNombre);

    duracion = fg.leerIntSeguro("Nueva duracion (minutos): ");

    cout << "Nuevo genero: ";
    getline(cin, genero);

    c.setNombreCancion(nuevoNombre);
    c.setDuracion(duracion);
    c.setGenero(genero);

    if(_ca.modificar(pos, c))
        cout << "\nCancion modificada con exito.\n";
    else
        cout << "\nError al modificar.\n";

    system("pause");
}

void MenuArtista::borrarCancion() {
    system("cls");

    string nombre;
    cout << "Nombre de la cancion a borrar: ";
    getline(cin, nombre);

    if(_ca.borrarCancion(_am.getArtistaActual().getId(), nombre))
        cout << "\nCancion eliminada.\n";
    else
        cout << "\nNo se encontro la cancion.\n";

    system("pause");
}
