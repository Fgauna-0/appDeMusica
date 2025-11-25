#include <iostream>
#include "ArtistaManager.h"

using namespace std;

ArtistaManager::ArtistaManager() :_repo("artistas.dat")
{
    _haySesion = false;
}

bool ArtistaManager::registrarArtista() {
    Artista a;
    string nombre, dni, pais, contrasenia;

    system("cls");
    cout << "=======================================" << endl;
    cout << "#         REGISTRAR ARTISTA           #" << endl;
    cout << "=======================================" << endl;

    cout << "Nombre artistico: ";
    getline(cin, nombre);

    if (_repo.buscarPorNombre(nombre) != -1) {
        cout << "Ya existe un artista con ese nombre.\n";
        return false;
    }

    cout << "DNI: ";
    getline(cin, dni);
    if (dni.size() < 7 || dni.size() > 9) {
        cout << "DNI invalido.\n";
        return false;
    }

    if (_repo.buscarPorDni(dni) != -1) {
        cout << "Ya existe un artista con ese DNI.\n";
        return false;
    }

    cout << "Nacionalidad: ";
    getline(cin, pais);

    cout << "Contrasenia: ";
    getline(cin, contrasenia);

    a.setId(_repo.getNuevoId());
    a.setNombre(nombre);
    a.setDni(dni);
    a.setNacionalidad(pais);
    a.setContrasenia(contrasenia);
    a.setEstado(true);
    a.setReproducciones(0);

    if (_repo.guardar(a)) {
        cout << "\nArtista registrado exitosamente!\n";
        return true;
    }
    else {
        cout << "\nError al guardar el artista.\n";
        return false;
    }
}

void ArtistaManager::mostrarArtistaPorId(int id){
    Artista a;

    int pos = _repo.buscarId(id);

    if(pos == -1){
        cout << "No existe Artista con ID " << id << endl;
        return;
    }

    if(_repo.leer(pos, a)){
        cout << a.toCSV() << endl;
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}

bool ArtistaManager::iniciarSesion(const std::string& nombre, const std::string& contrasenia) {
    Artista a;
    int total = _repo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        if (!_repo.leer(i, a)) continue;

        if (a.getNombre() == nombre && a.getContrasenia() == contrasenia && a.getEstado()) {
            cout << "Inicio de sesión exitoso!!. Bienvenido " << a.getNombre() << endl;
            _artistaActual = a;
            _haySesion = true;
            return true;
        }
    }

    cout << "Nombre o contraseña incorrectos. Vuelva a intentarlo." << endl;
    return false;
}


Artista& ArtistaManager::getArtistaActual(){
    return _artistaActual;
}

bool ArtistaManager::haySesion(){
    return _haySesion;
}

void ArtistaManager::cerrarSesion(){
    _haySesion = false;
    _artistaActual = Artista();
    cout << "Sesion cerrada" << endl;
}

bool ArtistaManager::modificarNombre(const std::string &nuevoNombre) {
    if (_artistaActual.getId() == 0) return false;


    if (_repo.buscarPorNombre(nuevoNombre) != -1) {
        return false;
    }

    _artistaActual.setNombre(nuevoNombre);
    int pos = _repo.buscarId(_artistaActual.getId());
    if (pos == -1) return false;

    return _repo.guardar(_artistaActual);
}

bool ArtistaManager::modificarNacionalidad(const std::string &nuevaNac) {
    if (_artistaActual.getId() == 0) return false;

    _artistaActual.setNacionalidad(nuevaNac);
    int pos = _repo.buscarId(_artistaActual.getId());
    if (pos == -1) return false;

    return _repo.guardar(_artistaActual);
}

bool ArtistaManager::modificarContrasenia(const std::string &nuevaPass) {
    if (_artistaActual.getId() == 0) return false;

    _artistaActual.setContrasenia(nuevaPass);
    int pos = _repo.buscarId(_artistaActual.getId());
    if (pos == -1) return false;

    return _repo.guardar(_artistaActual);
}


bool ArtistaManager::eliminarCuenta() {
    if (_artistaActual.getId() == 0) return false;
    int id = _artistaActual.getId();
    bool ok = _repo.borrarPorId(id);
    if (ok) {
        _artistaActual = Artista();
        _haySesion = false;
    }
    return ok;
}

vector<Artista> ArtistaManager::cargarTodos(){
    vector<Artista> v;
    int total = _repo.getCantidadRegistros();
    v.resize(total);
    for(int i=0;i<total;i++){
        _repo.leer(i, v[i]);
    }
    return v;
}

// -------- LISTADOS --------

void ArtistaManager::listarPorNombre(){
    auto v = cargarTodos();

    sort(v.begin(), v.end(), [](const Artista& a, const Artista& b){
        return a.getNombre() < b.getNombre();
    });

    for(auto &a : v){
        cout << a.toCSV() << endl;
    }
}

void ArtistaManager::listarPorNacionalidad(){
    auto v = cargarTodos();

    sort(v.begin(), v.end(), [](const Artista& a, const Artista& b){
        return a.getNacionalidad() < b.getNacionalidad();
    });

    for(auto &a : v){
        cout << a.toCSV() << endl;
    }
}

// helper interno: contar canciones de un artista
static int contarCancionesDeArtista(int idArtista){
    CancionArchivo repoCancion;
    Cancion c;
    int total = repoCancion.getCantidadRegistros();
    int count = 0;

    for(int i=0;i<total;i++){
        repoCancion.leer(i, c);
        if(c.getIdArtista() == idArtista && c.getEstado()){
            count++;
        }
    }
    return count;
}

void ArtistaManager::listarPorCantidadCanciones(){
    auto v = cargarTodos();

    sort(v.begin(), v.end(), [](const Artista& a, const Artista& b){
        return contarCancionesDeArtista(a.getId()) > contarCancionesDeArtista(b.getId());
    });

    for(auto &a : v){
        cout << a.getNombre()
             << " | " << a.getNacionalidad()
             << " | Canciones: " << contarCancionesDeArtista(a.getId())
             << endl;
    }
}

// -------- CONSULTAS --------

bool ArtistaManager::consultarPorPais(string pais){
    auto v = cargarTodos();
    if(v.empty()) return false;

    transform(pais.begin(), pais.end(), pais.begin(), ::tolower);
    bool encontro = false;

    for(auto &a : v){
        string nac = a.getNacionalidad();
        transform(nac.begin(), nac.end(), nac.begin(), ::tolower);

        if(nac.find(pais) != string::npos){
            cout << a.toCSV() << endl;
            encontro = true;
        }
    }
    return encontro;
}

bool ArtistaManager::consultarPorNombre(string nombreParcial){
    auto v = cargarTodos();
    if(v.empty()) return false;

    transform(nombreParcial.begin(), nombreParcial.end(), nombreParcial.begin(), ::tolower);
    bool encontro = false;

    for(auto &a : v){
        string nom = a.getNombre();
        transform(nom.begin(), nom.end(), nom.begin(), ::tolower);

        if(nom.find(nombreParcial) != string::npos){
            cout << a.toCSV() << endl;
            encontro = true;
        }
    }
    return encontro;
}


