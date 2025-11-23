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
    GeneroArchivo ga;

    int pos = archivo.buscarId(idArtista);

    if(pos == -1){
        cout << "No existe Artista con ID " << idArtista << endl;
        return;
    }

    archivo.leer(pos, a);


    cout << "=======================================" << endl;
    cout << "#           AGREGAR CANCION            #" << endl;
    cout << "=======================================" << endl;
    cout << "ARTISTA - " << a.getNombre() << endl << endl;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << endl << "Ingresar la Fecha de publicacion: " << endl;
    if(!f.cargarFecha()){
        cout << "Fecha invalida";
        return;
    }

    if(ga.getCantidadRegistros() == 0){
        cout << "No existen generos para clasificar la cancion.";
        return;
    }

    cout << endl << "Indique el genero" << endl << endl;
    g.listarGeneros();

    cout << endl << "ID del genero: ";
    cin >> idGenero;

    c.setIdCancion(_repo.getNuevoId());
    c.setNombreCancion(nombre);
    c.setFecha(f);
    c.setIdArtista(idArtista);
    c.setIdGenero(idGenero);
    c.setEstado(true);
    c.setReproduccionesCancion(0);

    cout << endl;

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

    if(pos == -1){
        cout << "No existe Cancion con ID " << id << endl;
        return;
    }

    if(_repo.leer(pos, c)){
        cout << c.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}

void CancionManager::mostrarCancionesPorNombre(string nombre){

    FuncionesGlobales f;
    string nombreMin = f.aMinuscula(nombre);

    Cancion c;
    Artista a;

    int total = _repo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < total; i++) {
        if (_repo.leer(i, c)) {
            if (f.aMinuscula(c.getNombreCancion()) == nombreMin) {

                int posArtista = _repoArtista.buscarId(c.getIdArtista());
                if (posArtista != -1 && _repoArtista.leer(posArtista, a)) {

                    cout << "|Cancion: " << c.getNombreCancion() << " |Artista: " << a.getNombre() << endl;

                    encontrado = true;
                }
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron canciones con ese nombre.\n";
    }
}
