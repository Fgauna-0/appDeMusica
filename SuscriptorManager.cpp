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

    cout << endl <<"Ingresar Nombre de usuario: ";
    getline(cin, nombre);

    if(_repo.buscarPorNombre(nombre) != -1){
        cout << "Ya existe un usuario con ese nombre, elija otro.. \n";
    }

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
        cout << "Telefono invalido. \n";
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
    tipoSuscripcion = fg.leerIntSeguro("Opcion: ");

    cout << endl;

    if(tipoSuscripcion != 1 && tipoSuscripcion != 2){
        cout << "Opcion invalida" << endl;
        return;
    }

    cout << "Ingresar Contrasenia: ";
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

    cout << endl;

    if(_repo.guardar(s)){
        cout << "Registro completado exitosamente!" << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }


}

bool SuscriptorManager::iniciarSesion(){

    Suscriptor s;
    string nombre;
    string contrasenia;
    int total = _repo.getCantidadRegistros();

    cout << "Ingresar Nombre de usuario: ";
    getline(cin, nombre);

    cout << endl;

    cout << "Ingresar contrasenia: ";
    getline(cin, contrasenia);

    for(int i = 0; i < total; i++){
        _repo.leer(i, s);
        if(s.getNombre() == nombre && s.getContrasenia() == contrasenia && s.getEstado()){
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

    if(_repo.buscarPorNombre(nombre) != -1){
        return false;
    }

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

vector<Suscriptor> SuscriptorManager::cargarTodos(){
    vector<Suscriptor> v;
    int total = _repo.getCantidadRegistros();
    v.resize(total);
    for(int i=0;i<total;i++){
        _repo.leer(i, v[i]);
    }
    return v;
}

// -------- LISTADOS --------

void SuscriptorManager::listarPorApellido(){
    auto v = cargarTodos();

    sort(v.begin(), v.end(), [](const Suscriptor& a, const Suscriptor& b){
        return a.getApellido() < b.getApellido();
    });

    for(auto &s : v){
        cout << s.toCSV() << endl;
    }
}

void SuscriptorManager::listarPorTipoSuscripcion(){
    auto v = cargarTodos();

    sort(v.begin(), v.end(), [](const Suscriptor& a, const Suscriptor& b){
        return a.getTipoSuscripcion() < b.getTipoSuscripcion();
    });

    for(auto &s : v){
        cout << s.toCSV() << endl;
    }
}

// -------- CONSULTAS --------

bool SuscriptorManager::consultarPorTipoSuscripcion(int tipo){
    auto v = cargarTodos();
    if(v.empty()) return false;

    bool encontro=false;
    for(auto &s : v){
        if(s.getTipoSuscripcion()==tipo){
            cout << s.toCSV() << endl;
            encontro=true;
        }
    }
    return encontro;
}


