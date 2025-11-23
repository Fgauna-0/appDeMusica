#include "MenuSuscriptor.h"
#include <iostream>
using namespace std;

MenuSuscriptor::MenuSuscriptor(SuscriptorManager& sm, CancionManager& cm, PlaylistManager& pm)
: _sm(sm), _cm(cm), _pm(pm){
}

void MenuSuscriptor::iniciar() {

    if(_sm.haySesion()) {

        //sincronizar el suscriptor actual
        _pm.setSuscriptorActual(_sm.getSuscriptorActual());
        _suscriptorActual = _sm.getSuscriptorActual();

        menuPrincipal();
    }
}

void MenuSuscriptor::menuPrincipal() {
    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#            MENU USUARIO              #" << endl;
        cout << "=======================================" << endl;
        cout << "-" << _suscriptorActual.getNombre() << endl;
        cout << "1. Buscar cancion\n";
        cout << "2. Modificar perfil\n";
        cout << "3. Crear Playlist\n";
        cout << "4. Modificar Playlist\n";
        cout << "5. Eliminar Playlist\n";
        cout << "6. Eliminar cuenta\n";
        cout << "0. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {

            case 1:
                menuBuscarCancion();
                break;

            case 2:
                //menuModificarPerfil();
                break;

            case 3:
                //_pm.crearPlaylist(_sm.getSuscriptorActual().getId());
                break;

            case 4:
                //menuModificarPlaylist();
                break;

            case 5: {
                /*int id;
                cout << "ID Playlist a eliminar: ";
                cin >> id; cin.ignore();
                _pm.eliminarPlaylist(id);*/
            } break;

            case 6:
                //_sm.eliminarCuenta();
                return;

            case 0:
                _sm.cerrarSesion();
                return;
        }

    } while (true);
}

void MenuSuscriptor::menuBuscarCancion() {
    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#          BUSCAR CANCION              #" << endl;
        cout << "=======================================" << endl;
        cout << "1. Buscar por nombre\n";
        cout << "2. Buscar por artista\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        cout << endl;

        if (opcion == 1) {
            buscarCancionesPorNombre();
        }

        else if (opcion == 2) {
            buscarCancionesPorArtista();
        }

    } while (opcion != 0);
}

void MenuSuscriptor::accionesSobreCancion(int idCancion) {
    if (idCancion == 0) return;

    system("cls");
    _cm.mostrarCancionPorId(idCancion);

    cout << endl;

    cout << "1. Reproducir\n";
    cout << "2. Agregar a playlist\n";
    cout << "0. Volver\n";
    int aux;
    cout << "Opcion: ";
    cin >> aux;
    cin.ignore();

    if (aux == 1) {
        system("cls");
        _cm.reproducirCancion(idCancion);
        system("pause");
    }
    else if (aux == 2) {
        system("cls");
        int idP;
        _pm.mostrarPlaylistDelSuscriptor(_suscriptorActual.getId());
        cout << "Opcion (ID playlist): ";
        cin >> idP;
        cin.ignore();
        _pm.agregarCancionAPlaylistPorIdPlaylistYIdCancion(idP,idCancion);
        cout << endl;
        system("pause");
    }
}

void MenuSuscriptor::buscarCancionesPorNombre(){

    string nombre;

    system("cls");

    cout << "==Buscar por nombre de cancion==" << endl << endl;

    cout << "Ingresar nombre: ";
    getline(cin, nombre);

    cout << endl;

    system("cls");

    cout << "==Canciones encontradas==" << endl << endl;

    _cm.mostrarCancionesPorNombre(nombre);

    int idCancion;
    cout << endl;
    cout << "ID de cancion para acciones (o 0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    accionesSobreCancion(idCancion);
}

void MenuSuscriptor::buscarCancionesPorArtista(){

    string nombre;

    system("cls");

    cout << "==Buscar por nombre de artista==" << endl;

    cout << "Ingrese artista: ";
    getline(cin, nombre);

    system("cls");

    cout << "==Canciones encontradas==" << endl << endl;

    _cm.mostrarCancionesPorArtista(nombre);

    int idCancion;
    cout << endl;
    cout << "ID de cancion para acciones (o 0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    accionesSobreCancion(idCancion);
}
