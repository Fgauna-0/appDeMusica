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
    GeneroManager g;

    int pos = archivo.buscarId(idArtista);
    archivo.leer(pos, a);


    cout << "=======================================" << endl;
    cout << "#           AGREGAR CANCION            #" << endl;
    cout << "=======================================" << endl;
    cout << "ARTISTA - " << a.getNombre() << endl << endl;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << endl << "Ingresar la Fecha de publicacion: " << endl;
    f.cargarFecha();

    cout << endl << "Indique el genero" << endl << endl;
    g.listarGeneros();

    cout << endl << "ID del genero: ";
    cin >> idGenero;

    c.setIdCancion(_repo.getCantidadRegistros() + 1);
    c.setNombreCancion(nombre);
    c.setFecha(f);
    c.setIdArtista(idArtista);
    c.setIdGenero(idGenero);
    c.setEstado(true);
    c.setReproduccionesCancion(0);

    if(_repo.guardar(c)){
        cout << "Cancion guardada exitosamente!" << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}

void CancionManager::mostrarCancionPorId(int id){
    Cancion c;

    int pos = _repo.buscarId(id);

    if(_repo.leer(pos, c)){
        cout << c.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}
