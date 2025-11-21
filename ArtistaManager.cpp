#include <iostream>
#include "ArtistaManager.h"

using namespace std;

ArtistaManager::ArtistaManager()
{
    //ctor
}

void ArtistaManager::registrarArtista(){

    Artista a;
    ArtistaArchivo archivo;
    string nombre;
    string dni;
    string pais;
    string contrasenia;

    cout << "=======================================" << endl;
    cout << "#         REGISTRAR ARTISTA           #" << endl;
    cout << "=======================================" << endl;

    cout << "Ingresar DNI: ";
    getline(cin, dni);

    cout << "Ingresar Nombre: ";
    getline(cin, nombre);

    cout << "Ingresar Pais: ";
    getline(cin, pais);

    cout << "Ingresar Contrasenia: ";
    getline(cin, contrasenia);

    a.setId(archivo.getCantidadRegistros() + 1);
    a.setDni(dni);
    a.setNombre(nombre);
    a.setNacionalidad(pais);
    a.setContrasenia(contrasenia);
    a.setEstado(true);
    a.setReproducciones(0);

    if(archivo.guardar(a)){
        cout << "Artista registrado exitosamente!" << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }

}

void ArtistaManager::mostrarArtistaPorId(int id){
    ArtistaArchivo archivo;
    Artista a;

    int pos = archivo.buscarId(id);

    if(archivo.leer(pos, a)){
        cout << a.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}

bool ArtistaManager::iniciarSesion(){

    Artista a;
    string dni;
    string contrasenia;
    int total = _repo.getCantidadRegistros();

    cout << "=======================================" << endl;
    cout << "#      INICIAR SESSION - ARTISTA       #" << endl;
    cout << "=======================================" << endl;

    cout << "Ingresar DNI: ";
    getline(cin, dni);

    cout << "Ingresar contrasenia: ";
    getline(cin, contrasenia);

    for(int i = 0; i < total; i++){
        _repo.leer(i, a);
        if(a.getDni() == dni && a.getContrasenia() == contrasenia && a.getEstado()){
            cout << "Inicio de session exitoso!!. " << "Bienvenido " << a.getNombre() << endl;
            _artistaActual = a;
            _haySesion = true;
            return true;
        }
    }

    cout << "DNI o contrasenia incorrecto. Vuelva a intentarlo." << endl;
    return false;
}

Artista ArtistaManager::getArtistaActual(){
    return _artistaActual;
}

bool ArtistaManager::getHaySesion(){
    return _haySesion;
}
