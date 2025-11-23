#include <iostream>
#include "GeneroManager.h"

using namespace std;

GeneroManager::GeneroManager()
{
    //ctor
}

void GeneroManager::agregarGenero(){

    Genero g;
    std::string nombre;

    cout << "=======================================" << endl;
    cout << "#           AGREGAR GENERO             #" << endl;
    cout << "=======================================" << endl;
    cout << "Ingresar nombre: ";
    getline(cin, nombre);

    cout << endl;

    g.setIdGenero(_repo.getNuevoId());
    g.setReproduccionesGenero(0);
    g.setEstado(true);
    g.setNombreGenero(nombre);

    if(_repo.guardar(g)) cout << "Se agrego exitosamente!" << endl;
    else cout << "Ha ocurrido un error" << endl;

}

void GeneroManager::mostrarGeneroPorId(int id){

    Genero g;

    int pos = _repo.buscarId(id);

    if(pos == -1){
        cout << "No existe Genero con ID " << id << endl;
        return;
    }

    if(_repo.leer(pos, g)){
        cout << g.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }


}

void GeneroManager::listarGeneros(){

    Genero g;
    int total = _repo.getCantidadRegistros();

    if(total == 0){
        cout << "No hay generos disponibles";
        return;
    }

    cout << "-Generos disponibles-" << endl;

    for(int i=0; i < total; i++){
        if(_repo.leer(i,g) && g.getEstado()){
            cout << g.getIdGenero() << ". " << g.getNombreGenero() << endl;
        }

    }

}

