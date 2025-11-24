#include "MenuPrincipal.h"



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
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: {

                int opcAux;

                system("cls");
                cout << "=======================================" << endl;
                cout << "#              USUARIO                #" << endl;
                cout << "=======================================" << endl;

                cout << "1.Iniciar sesion \n";
                cout << "2.Registrarse \n";
                cout << "0.Volver \n";
                cout << "Opcion: ";

                cin >> opcAux;

                cin.ignore();

                    if(opcAux == 1){
                        system("cls");
                        cout << "=======================================" << endl;
                        cout << "#           INICIAR SESION             #" << endl;
                        cout << "=======================================" << endl;

                        if(_sm.iniciarSesion()){
                            MenuSuscriptor ms(_sm,_cm,_pm);
                            ms.iniciar();
                        }
                    }else if(opcAux == 2){
                        system("cls");
                        _sm.registrarSuscriptor();
                        system("pause");
                    }

                    break;
                }
            break;

            case 2: {
                //menu artista
            } break;
            case 3: {
                //menu admin
            } break;
        }

    } while (opcion != 0);
}
