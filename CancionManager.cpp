#include <iostream>
#include "CancionManager.h"

using namespace std;

CancionManager::CancionManager()
{
    //ctor
}

void CancionManager::agregarCancion(int idArtista){

    Cancion c;
    Fecha f;
    string nombre;
    int idGenero;
    Artista a;
    ArtistaArchivo archivo;

    int pos = archivo.buscarId(idArtista);
    archivo.leer(pos, a);


    cout << "=======================================" << endl;
    cout << "#           AGREGAR CANCION            #" << endl;
    cout << "=======================================" << endl;
    cout << "ARTISTA - " << a.getNombre() << endl;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese la Fecha de publicacion: " << endl;
    f.cargarFecha();



}
