#include "MenuPrincipal.h"
#include "MenuArtista.h"
#include "ArtistaManager.h"


MenuPrincipal::MenuPrincipal()
{
    //ctor
}

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
                int opcAux;

                system("cls");
                cout << "=======================================" << endl;
                cout << "#              USUARIO                #" << endl;
                cout << "=======================================" << endl;

                cout << "1. Iniciar sesion \n";
                cout << "2. Registrarse \n";
                cout << "0. Volver \n";

                opcAux = fg.leerIntSeguro("Opcion: ");

                if(opcAux == 1){
                    system("cls");
                    cout << "=======================================" << endl;
                    cout << "#           INICIAR SESION            #" << endl;
                    cout << "=======================================" << endl;

                    if(_sm.iniciarSesion()){
                        MenuSuscriptor ms(_sm,_cm,_pm);
                        ms.iniciar();
                    }
                }
                else if(opcAux == 2){
                    system("cls");
                    _sm.registrarSuscriptor();
                    system("pause");
                }

                break;
            }

            case 2: {
                system("cls");

                cout << "=======================================" << endl;
                cout << "#               ARTISTA               #" << endl;
                cout << "=======================================" << endl;

                MenuArtista ma(_am);
                ma.iniciar();
                } break;

            case 3: {
                // menu admin
            } break;

            case 0:
                // salir
                break;

            default:
                cout << "Opcion invalida." << endl;
                system("pause");
        }

    } while (opcion != 0);
}
