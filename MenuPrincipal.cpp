#include "MenuPrincipal.h"
#include "MenuArtista.h"
#include "ArtistaManager.h"


MenuPrincipal::MenuPrincipal(SuscriptorManager& sm, ArtistaManager& am, CancionManager& cm, PlaylistManager& pm)
: _sm(sm), _am(am), _cm(cm), _pm(pm)
{}

void MenuPrincipal::iniciar() {

    int opcion;

    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "#           MENU PRINCIPAL            #" << endl;
        cout << "=======================================" << endl;
        cout << "1. Suscriptor\n";
        cout << "2. Artista\n";
        cout << "3. Administrador\n";
        cout << "0. Salir\n";

        opcion = fg.leerIntSeguro("Opcion: ");

        switch(opcion) {
            case 1: {
                    MenuSuscriptor ms(_sm, _cm, _pm);
                    ms.iniciar();
                    }
                    break;


            case 2: {
                system("cls");

                cout << "=======================================" << endl;
                cout << "#               ARTISTA               #" << endl;
                cout << "=======================================" << endl;

                MenuArtista ma(_am);
                ma.iniciar();
                } break;

            case 3: {
                MenuAdministrador mad(_cm, _am, _sm, _pm);
                mad.iniciar();
            } break;

            case 0:
                // salir
                break;

            default:
                cout << "Opcion invalida." << endl;
                system("pause");
            }

        }while (opcion != 0);
}


