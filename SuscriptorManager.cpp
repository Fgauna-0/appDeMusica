#include <iostream>
#include "SuscriptorManager.h"

using namespace std;

SuscriptorManager::SuscriptorManager()
{
    //ctor
}

void SuscriptorManager::registrarSuscriptor(){

    Suscriptor s;
    string dni, nombre, apellido, email, telefono, contrasenia;
    int tipoSuscripcion;
    Fecha fecha;

    cout << "=======================================" << endl;
    cout << "#            CREAR CUENTA             #" << endl;
    cout << "=======================================" << endl;

    cout << endl << "Ingresar DNI: ";
    getline(cin, dni);

    if (dni.size() != 8) {
        cout << "DNI invalido. \n";
        return;
    }

    if (_repo.buscarPorDni(dni) != -1) {
        cout << "Ya existe un suscriptor con ese DNI.\n";
        return;
    }

    cout << endl <<"Ingresar Nombre: ";
    getline(cin, nombre);

    cout << endl << "Ingresar Apellido: ";
    getline(cin, apellido);

    cout << endl <<"Ingresar Email: ";
    getline(cin, email);

    if (_repo.buscarPorEmail(email) != -1) {
        cout << "Ya existe una cuenta con ese email.\n";
        return;
    }

    cout << endl <<"Ingresar Telefono: " ;
    getline(cin, telefono);

    if (telefono.size() != 10) {
        cout << "DNI invalido. \n";
        return;
    }

    cout << endl <<"Ingresar fecha de nacimiento: " << endl;

    if(!fecha.cargarFecha()){
        cout << "Fecha invalida";
        return;
    }

    cout << endl << "Ingresar el tipo de suscripcion: " << endl;
    cout << "==========================================" << endl;
    cout << "1. Gratuita - Acceso limitado y publicidad." << endl;
    cout << "2. Premium - Acceso ilimitado y sin publicidad." << endl;
    cout << "==========================================" << endl;
    cout << "Opcion: ";
    cin >> tipoSuscripcion;

    if(tipoSuscripcion != 1 && tipoSuscripcion != 2){
        cout << "Opcion invalida" << endl;
        return;
    }

    cout << "Ingresar Contrasenia: ";
    cin.ignore();
    getline(cin,contrasenia);

    cout << endl;

    s.setId(_repo.getNuevoId());
    s.setDni(dni);
    s.setNombre(nombre);
    s.setApellido(apellido);
    s.setEmail(email);
    s.setTelefono(telefono);
    s.setTipoSuscripcion(tipoSuscripcion);
    s.setContrasenia(contrasenia);
    s.setFechaNacimiento(fecha);
    s.setReproducciones(0);
    s.setEstado(true);

    if(_repo.guardar(s)){
        cout << "Registro completado exitosamente!" << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }


}

bool SuscriptorManager::iniciarSesion(){

    Suscriptor s;
    string dni;
    string contrasenia;
    int total = _repo.getCantidadRegistros();

    cout << "Ingresar DNI: ";
    getline(cin, dni);

    cout << endl;

    cout << "Ingresar contrasenia: ";
    getline(cin, contrasenia);

    for(int i = 0; i < total; i++){
        _repo.leer(i, s);
        if(s.getDni() == dni && s.getContrasenia() == contrasenia && s.getEstado()){
            cout << endl;
            cout << "Inicio de session exitoso!!. " << "Bienvenido " << s.getNombre() << endl;
            system("pause");
            cout << endl;
            _suscriptorActual = s;
            _haySesion = true;
            return true;
        }
    }

    cout << endl;

    cout << "DNI o contrasenia incorrecto. Vuelva a intentarlo." << endl;
    system("pause");
    cout << endl;
    return false;
}

void SuscriptorManager::cerrarSesion(){
    _haySesion = false;
    _suscriptorActual = Suscriptor();
    cout << "Sesion cerrada";
}

bool SuscriptorManager::haySesion(){
    return _haySesion;
}

Suscriptor& SuscriptorManager::getSuscriptorActual(){
    return _suscriptorActual;
}

bool SuscriptorManager::modificarNombre(std::string nombre, Suscriptor& registro){
    int pos = _repo.buscarId(registro.getId());
    registro.setNombre(nombre);

    if(_repo.modificar(pos,registro)){
        return true;
    }

    return false;
}

bool SuscriptorManager::modificarSuscripcion(int suscripcion, Suscriptor& registro){
    int pos = _repo.buscarId(registro.getId());
    registro.setTipoSuscripcion(suscripcion);

    if(_repo.modificar(pos,registro)){
        return true;
    }

    return false;
}

void SuscriptorManager::sumarReproduccionAlSuscriptor()
{
    _suscriptorActual.sumarReproduccion();

    int pos = _repo.buscarId(_suscriptorActual.getId());
    if (pos != -1) {
        _repo.modificar(pos, _suscriptorActual);
    }
}

bool SuscriptorManager::eliminarCuenta(Suscriptor& registro){
    int pos = _repo.buscarId(_suscriptorActual.getId());

    _suscriptorActual.setEstado(false);

    if(pos != -1){
        if(_repo.modificar(pos, _suscriptorActual)){
            return true;
        }
    }

    return false;
}

