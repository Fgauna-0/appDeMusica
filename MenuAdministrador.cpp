#include <iostream>
#include "MenuAdministrador.h"

using namespace std;

MenuAdministrador::MenuAdministrador(CancionManager &cm, ArtistaManager &am, SuscriptorManager &sm, PlaylistManager &pm)
: _cm(cm), _am(am), _sm(sm), _pm(pm) {}

void MenuAdministrador::iniciar() {
    int op;

    do {
        cout << "\n===== MENU ADMINISTRADOR =====\n";
        cout << "1) Listados\n";
        cout << "2) Consultas\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1: menuListados(); break;
        case 2: menuConsultas(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::menuListados() {
    int op;

    do {
        cout << "\n===== LISTADOS =====\n";
        cout << "1) Listado de Canciones\n";
        cout << "2) Listado de Artistas\n";
        cout << "3) Listado de Suscriptores\n";
        cout << "4) Listado de Playlists\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: listadoCanciones(); break;
        case 2: listadoArtistas(); break;
        case 3: listadoSuscriptores(); break;
        case 4: listadoPlaylists(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoCanciones() {
    int op;

    do {
        cout << "\n--- Listado de Canciones ---\n";
        cout << "1) Por título\n";
        cout << "2) Por fecha\n";
        cout << "3) Por género (alfabético)\n";
        cout << "4) Por artista (alfabético)\n";
        cout << "5) Por nacionalidad del artista\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: _cm.listarPorTitulo(); break;
        case 2: _cm.listarPorFecha(); break;
        case 3: _cm.listarPorGenero(); break;
        case 4: _cm.listarPorArtista(); break;
        case 5: _cm.listarPorNacionalidad(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoArtistas() {
    int op;

    do {
        cout << "\n--- Listado de Artistas ---\n";
        cout << "1) Por nombre\n";
        cout << "2) Por nacionalidad\n";
        cout << "3) Por cantidad de canciones\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: _am.listarPorNombre(); break;
        case 2: _am.listarPorNacionalidad(); break;
        case 3: _am.listarPorCantidadCanciones(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoSuscriptores() {
    int op;

    do {
        cout << "\n--- Listado de Suscriptores ---\n";
        cout << "1) Por apellido\n";
        cout << "2) Por edad\n";
        cout << "3) Por tipo de suscripción\n";
        cout << "4) Por fecha de alta\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: _sm.listarPorApellido(); break;
        case 2: _sm.listarPorEdad(); break;
        case 3: _sm.listarPorSuscripcion(); break;
        case 4: _sm.listarPorFechaAlta(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoPlaylists() {
    int op;

    do {
        cout << "\n--- Listado de Playlists ---\n";
        cout << "1) Por nombre\n";
        cout << "2) Por cantidad de canciones\n";
        cout << "3) Por usuario creador\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: _pm.listarPorNombre(); break;
        case 2: _pm.listarPorCantidad(); break;
        case 3: _pm.listarPorUsuario(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::menuConsultas() {
    int op;

    do {
        cout << "\n===== CONSULTAS =====\n";
        cout << "1) Consultas de Canciones\n";
        cout << "2) Consultas de Artistas\n";
        cout << "3) Consultas de Suscriptores\n";
        cout << "4) Consultas de Playlists\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1: consultaCanciones(); break;
        case 2: consultaArtistas(); break;
        case 3: consultaSuscriptores(); break;
        case 4: consultaPlaylists(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::consultaCanciones() {
    int op;
    string texto;
    int num;

    do {
        cout << "\n--- Consultas de Canciones ---\n";
        cout << "1) Por título\n";
        cout << "2) Por género\n";
        cout << "3) Por artista\n";
        cout << "4) Por año\n";
        cout << "5) Por país del artista\n";
        cout << "6) Por nombre del género\n";
        cout << "7) Por nombre del artista\n";
        cout << "0) Volver\n";
        cout << "Opción: ";
        cin >> op; cin.ignore();

        switch (op) {
        case 1:
            cout << "Título: ";
            getline(cin, texto);
            if(!_cm.consultarPorTitulo(texto)) cout << "Sin resultados.\n";
            break;

        case 2:
            cout << "ID género: ";
            cin >> num; cin.ignore();
            if(!_cm.consultarPorGenero(num)) cout << "Sin resultados.\n";
            break;

        case 3:
            cout << "ID artista: ";
            cin >> num; cin.ignore();
            if(!_cm.consultarPorArtista(num)) cout << "Sin resultados.\n";
            break;

        case 4:
            cout << "Año: ";
            cin >> num; cin.ignore();
            if(!_cm.consultarPorAnio(num)) cout << "Sin resultados.\n";
            break;

        case 5:
            cout << "País: ";
            getline(cin, texto);
            if(!_cm.consultarPorPais(texto)) cout << "Sin resultados.\n";
            break;

        case 6:
            cout << "Nombre del género: ";
            getline(cin, texto);
            _cm.consultarPorNombreGenero(texto);
            break;

        case 7:
            cout << "Nombre del artista: ";
            getline(cin, texto);
            _cm.consultarPorNombreArtista(texto);
            break;
        }
    } while (op != 0);
}
