#include <iostream>
#include "GeneroManager.h"

using namespace std;

GeneroManager::GeneroManager()
{
    //ctor
}

void GeneroManager::agregarGenero(){

    GeneroArchivo archivo;
    Genero g;
    std::string nombre;

    cout << "=======================================" << endl;
    cout << "#           AGREGAR GENERO             #" << endl;
    cout << "=======================================" << endl;
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    g.setIdGenero(archivo.getCantidadRegistros() + 1);
    g.setReproduccionesGenero(0);
    g.setEstado(true);
    g.setNombreGenero(nombre);

    if(archivo.guardar(g)) cout << "Se creo exitosamente!" << endl;
    else cout << "Ha ocurrido un error" << endl;

}

void GeneroManager::mostrarGeneroPorId(int id){

    GeneroArchivo archivo;
    Genero g;

    int pos = archivo.buscarId(id);

    if(archivo.leer(pos, g)){
        cout << g.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }


}

void GeneroManager::listarGeneros(){

    GeneroArchivo archivo;
    Genero g;
    int total = archivo.getCantidadRegistros();

    cout << "=======================================" << endl;
    cout << "#         GENEROS DISPONIBLES          #" << endl;
    cout << "=======================================" << endl;
    for(int i=0; i < total; i++){
        if(archivo.leer(i,g) && g.getEstado()){
            cout << g.getIdGenero() << ". " << g.getNombreGenero() << endl;
        }

    }

}

