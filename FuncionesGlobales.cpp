#include "FuncionesGlobales.h"

using namespace std;

FuncionesGlobales::FuncionesGlobales()
{
    //ctor
}

std::string FuncionesGlobales::aMinuscula(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int FuncionesGlobales::leerIntSeguro(const string& mensaje) {
    int valor;

    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        // entrada inválida
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrada invalida. Ingrese un numero.\n";
    }
}
