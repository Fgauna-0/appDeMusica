#include <iostream>
#include "MenuAdministrador.h"

using namespace std;

MenuAdministrador::MenuAdministrador(CancionManager &cm, ArtistaManager &am, SuscriptorManager &sm, PlaylistManager &pm)
: _cm(cm), _am(am), _sm(sm), _pm(pm) {}

void MenuAdministrador::iniciar() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#         MENU ADMINISTRADOR           #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Listados\n";
        cout << "2) Consultas\n";
        cout << "3) Agregar Genero \n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1: menuListados(); break;
        case 2: menuConsultas(); break;
        case 3: agregarGenero(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::menuListados() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#               LISTADOS              #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Listado de Canciones\n";
        cout << "2) Listado de Artistas\n";
        cout << "3) Listado de Suscriptores\n";
        cout << "4) Listado de Playlists\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

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
        system("cls");
        cout << "=======================================" << endl;
        cout << "#       LISTADO DE CANCIONES          #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por titulo\n";
        cout << "2) Por fecha\n";
        cout << "3) Por genero (alfabetico)\n";
        cout << "4) Por artista (alfabetico)\n";
        cout << "5) Por nacionalidad del artista\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1: system("cls");_cm.listarPorTitulo(); system("pause"); break;
        case 2: system("cls");_cm.listarPorFecha(); system("pause"); break;
        case 3: system("cls");_cm.listarPorGenero(); system("pause"); break;
        case 4: system("cls");_cm.listarPorArtista(); system("pause"); break;
        case 5: system("cls");_cm.listarPorNacionalidad(); system("pause"); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoArtistas() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#          LISTADO DE ARTISTA          #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por nombre\n";
        cout << "2) Por nacionalidad\n";
        cout << "3) Por cantidad de canciones\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1: system("cls"); _am.listarPorNombre();system("pause"); break;
        case 2: system("cls");_am.listarPorNacionalidad();system("pause"); break;
        case 3: system("cls");_am.listarPorCantidadCanciones();system("pause"); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoSuscriptores() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#       LISTADO DE SUSCRIPTORES       #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por apellido\n";
        cout << "3) Por tipo de suscripcion\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1:system("cls"); _sm.listarPorApellido(); system("pause"); break;
        case 2:system("cls"); _sm.listarPorTipoSuscripcion(); system("pause"); break;
        }
    } while (op != 0);
}

void MenuAdministrador::listadoPlaylists() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#         LISTADO DE PLAYLIS          #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por nombre\n";
        cout << "2) Por cantidad de canciones\n";
        cout << "3) Por usuario creador\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1: system("cls");_pm.listarPorNombre(); system("pause");break;
        case 2: system("cls");_pm.listarPorCantidadCanciones(); system("pause");break;
        case 3: system("cls");_pm.listarPorUsuario(); system("pause");break;
        }
    } while (op != 0);
}

void MenuAdministrador::menuConsultas() {
    int op;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#            MENU CONSULTAS           #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Consultas de Canciones\n";
        cout << "2) Consultas de Artistas\n";
        cout << "3) Consultas de Suscriptores\n";
        cout << "4) Consultas de Playlists\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch (op) {
        case 1: consultaCanciones(); break;
        case 2: consultarArtistas(); break;
        case 3: consultarSuscriptores(); break;
        case 4: consultarPlaylists(); break;
        }
    } while (op != 0);
}

void MenuAdministrador::consultaCanciones() {
    int op;
    string texto;
    int num;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#         CONSULTA DE CANCIONES       #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por titulo\n";
        cout << "2) Por anio\n";
        cout << "3) Por país del artista\n";
        cout << "4) Por nombre del genero\n";
        cout << "5) Por nombre del artista\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");


        switch (op) {
        case 1:
            system("cls");
            cout << "Titulo: ";
            getline(cin, texto);
            if(!_cm.consultarPorTitulo(texto)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Anio: ";
            cin >> num; cin.ignore();
            if(!_cm.consultarPorAnio(num)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Pais: ";
            getline(cin, texto);
            if(!_cm.consultarPorPais(texto)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Nombre del genero: ";
            getline(cin, texto);
            _cm.consultarPorNombreGenero(texto);
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "Nombre del artista: ";
            getline(cin, texto);
            _cm.consultarPorNombreArtista(texto);
            system("pause");
            break;
        }
    } while (op != 0);
}

void MenuAdministrador::consultarArtistas() {
    int op;
    string texto;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#         CONSULTA DE ARTISTA         #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por nombre\n";
        cout << "2) Por nacionalidad\n";
        cout << "3) Por cantidad de canciones\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");;

        switch(op){
        case 1:
            system("cls");
            cout << "Nombre: ";
            getline(cin, texto);
            if(!_am.consultarPorNombre(texto)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Nacionalidad: ";
            getline(cin, texto);
            if(!_am.consultarPorPais(texto)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 3:
            system("cls");
            _am.listarPorCantidadCanciones();
            system("pause");
            break;

        }
    }
    while(op != 0);
}

void MenuAdministrador::consultarSuscriptores() {
    int op;
    int num;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#       CONSULTA DE SUSCRIPTORES       #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por tipo de suscripcion\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch(op){
        case 1:
            system("cls");
            cout << "Tipo de suscripcion (1,2): ";
            cin >> num; cin.ignore();
            if(!_sm.consultarPorTipoSuscripcion(num)) cout << "Sin resultados.\n";
            system("pause");
            break;
        }
    }
    while(op != 0);
}

void MenuAdministrador::consultarPlaylists() {
    int op;
    int num;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#         CONSULTA DE PLAYLITS         #" << endl;
        cout << "=======================================" << endl;
        cout << "1) Por usuario (ID Suscriptor)\n";
        cout << "2) Por cantidad mínima de canciones\n";
        cout << "0) Volver\n";
        op = fg.leerIntSeguro("Opcion: ");

        switch(op){
        case 1:
            system("cls");
            cout << "ID Usuario: ";
            cin >> num; cin.ignore();
            if(!_pm.consultarPorUsuario(num)) cout << "Sin resultados.\n";
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Cantidad minima de canciones: ";
            cin >> num; cin.ignore();
            if(!_pm.consultarPorCantidadCanciones(num)) cout << "Sin resultados.\n";
            system("pause");
            break;

        }
    }
    while(op != 0);
}

void MenuAdministrador::agregarGenero(){
    system("cls");
    GeneroManager gm;
    gm.agregarGenero();
    system("pause");
}

