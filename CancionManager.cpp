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
        Artista a;
        Genero g;
        if(_repoArtista.leerPorId(c.getIdArtista(), a) && _repoGenero.leerPorId(c.getIdGenero(),g)){

           cout << "ID: " << c.getIdCancion() << " |Nombre: " << c.getNombreCancion() << " |Artista: " << a.getNombre() << " |Genero: " << g.getNombreGenero() << endl;

           }
    }
    else{
        cout << "Ha ocurrido un error" << endl;
    }
}

bool CancionManager::mostrarCancionesPorNombre(string nombre){

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

                    cout << "|ID: " << c.getIdCancion() << " |Cancion: " << c.getNombreCancion() << " |Artista: " << a.getNombre() << endl;

                    encontrado = true;
                    return encontrado;
                }
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron canciones con ese nombre.\n";
        return encontrado;
    }

    return encontrado;
}

bool CancionManager::mostrarCancionesPorArtista(string nombre){

    FuncionesGlobales f;
    string nombreArtistaMin = f.aMinuscula(nombre);

    Cancion c;
    Artista a;

    int totalArtistas = _repoArtista.getCantidadRegistros();
    int idBuscado = -1;


    for(int i = 0; i < totalArtistas; i++){
        if(_repoArtista.leer(i, a)){
            if(f.aMinuscula(a.getNombre()) == nombreArtistaMin && a.getEstado()){
                idBuscado = a.getId();
                break;
            }
        }
    }

    if(idBuscado == -1){
        cout << "No existe un artista con ese nombre.\n";
        return false;
    }

    int totalCanciones = _repo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < totalCanciones; i++) {
        if (_repo.leer(i, c)) {
            if (c.getIdArtista() == idBuscado && c.getEstado()) {

                cout << "|ID: " << c.getIdCancion() << " |Cancion: " << c.getNombreCancion() << " |Artista: " << a.getNombre() << endl;
                encontrado = true;
                return encontrado;
            }
        }
    }

    if(!encontrado){
        cout << "El artista no tiene canciones cargadas.\n";
        return encontrado;
    }

    return encontrado;
}

int CancionManager::reproducirCancion(int idCancion, int idUsuario)
{
    //Buscar canción
    int pos = _repo.buscarId(idCancion);
    if (pos == -1) {
        cout << "No existe una canción con ese ID.\n";
        return 0;
    }

    Cancion c;
    _repo.leer(pos, c);

    //Sumar reproduccion a la canción
    c.sumarReproduccion();
    _repo.modificar(pos, c);

    //Sumar reproduccion a la tabla del usuario (canciones escuchadas)
    int posRepro = _repoRepro.buscar(idUsuario, idCancion);
    ReproduccionSuscriptor rs;

    if (posRepro == -1) {
        rs.setIdSuscriptor(idUsuario);
        rs.setIdCancion(idCancion);
        rs.sumarReproduccion();
        _repoRepro.guardar(rs);
    }
    else {
        _repoRepro.leer(posRepro, rs);
        rs.sumarReproduccion();
        _repoRepro.modificar(posRepro, rs);
    }

    //Sumar reproduccion al ARTISTA
    int posArt = _repoArtista.buscarId(c.getIdArtista());
    if (posArt != -1) {
        Artista a;
        _repoArtista.leer(posArt, a);
        a.sumarReproduccion();
        _repoArtista.modificar(posArt, a);
    }

    //Sumar reproduccion al GÉNERO
    int posGen = _repoGenero.buscarId(c.getIdGenero());
    if (posGen != -1) {
        Genero g;
        _repoGenero.leer(posGen, g);
        g.sumarReproduccion();
        _repoGenero.modificar(posGen, g);
    }

    cout << "-REPRODUCIENDO: " << c.getNombreCancion() << endl;

    return 1; // cantidad de reproducciones que debe sumar el usuario
}

void CancionManager::mostrarMasEscuchadaPorUsuario(int idUsuario) {

    ReproduccionSuscriptor rs;
    int total = _repoRepro.getCantidadRegistros();

    int maxRepro = -1;
    int idCancionMax = -1;

    for (int i = 0; i < total; i++) {
        if (_repoRepro.leer(i, rs)) {
            if (rs.getIdSuscriptor() == idUsuario &&
                rs.getReproducciones() > maxRepro) {

                maxRepro = rs.getReproducciones();
                idCancionMax = rs.getIdCancion();
            }
        }
    }

    if (idCancionMax == -1) {
        cout << "El usuario no escucho ninguna cancion.\n";
        return;
    }

    int pos = _repo.buscarId(idCancionMax);
    Cancion c;
    _repo.leer(pos, c);

    cout << "Cancion mas escuchada por este usuario:\n";
    cout << c.getNombreCancion() << " (" << maxRepro << " reproducciones)" << endl;
}

void CancionManager::mostrarTodasLasCanciones(){

    Cancion c;
    Artista a;

    int total = _repo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        if (_repo.leer(i, c) && c.getEstado()) {

            int posArt = _repoArtista.buscarId(c.getIdArtista());
            string nombreArtista = "(Desconocido)";

            if (posArt != -1 && _repoArtista.leer(posArt, a)) {
                nombreArtista = a.getNombre();
            }

            cout << c.getIdCancion()
                 << " - " << c.getNombreCancion()
                 << " | " << nombreArtista << endl;
        }
    }
}

bool CancionManager::mostrarCancionesPorGenero(string nombre){

    FuncionesGlobales f;
    string nombreGeneromin = f.aMinuscula(nombre);

    Cancion c;
    Genero g;

    int totalArtistas = _repoArtista.getCantidadRegistros();
    int idBuscado = -1;


    for(int i = 0; i < totalArtistas; i++){
        if(_repoGenero.leer(i, g)){
            if(f.aMinuscula(g.getNombreGenero()) == nombreGeneromin && g.getEstado()){
                idBuscado = g.getIdGenero();
                break;
            }
        }
    }

    if(idBuscado == -1){
        cout << "No existe un artista con ese nombre.\n";
        return false;
    }

    int totalCanciones = _repo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < totalCanciones; i++) {
        if (_repo.leer(i, c)) {
            if (c.getIdGenero() == idBuscado && c.getEstado()) {

                cout << "|ID: " << c.getIdCancion() << " |Cancion: " << c.getNombreCancion() << " |Genero: " << g.getNombreGenero() << endl;
                encontrado = true;
                return encontrado;
            }
        }
    }

    if(!encontrado){
        cout << "El artista no tiene canciones cargadas.\n";
        return encontrado;
    }

    return encontrado;
}

vector<Cancion> CancionManager::cargarTodas(){
    vector<Cancion> v;
    int total = _repo.getCantidadRegistros();
    v.resize(total);

    for(int i = 0; i < total; i++){
        _repo.leer(i, v[i]);
    }

    return v;
}

void CancionManager::mostrar(const Cancion& c){

    ArtistaArchivo repoArtista;
    Artista art;
    repoArtista.leerPorId(c.getIdArtista(),art);


    GeneroArchivo repoGenero;
    Genero gen;
    repoGenero.leerPorId(c.getIdGenero(), gen);

    cout << "ID: " << c.getIdCancion() << endl;
    cout << "Titulo: " << c.getNombreCancion() << endl;
    cout << "Fecha: " << c.getFecha().toCSV() << endl;
    cout << "Genero: " << gen.getNombreGenero() << endl;
    cout << "Artista: " << art.getNombre() << endl;
    cout << "Pais del artista: " << art.getNacionalidad() << endl;
    cout << "------------------------------\n";
}


void CancionManager::listarPorTitulo(){
    FuncionesGlobales f;
    auto v = cargarTodas();

    sort(v.begin(), v.end(), [](Cancion a, Cancion b){

    return a.getNombreCancion() < b.getNombreCancion();}

    );
    for(auto &c : v) mostrar(c);
}

void CancionManager::listarPorFecha(){
    auto v = cargarTodas();

    sort(v.begin(), v.end(), [](Cancion a, Cancion b){

    Fecha fa = a.getFecha();
    Fecha fb = b.getFecha();

    if(fa.getAnio() != fb.getAnio())
        return fa.getAnio() < fb.getAnio();

    if(fa.getMes() != fb.getMes())
        return fa.getMes() < fb.getMes();

    return fa.getDia() < fb.getDia();
});
    for(auto &c : v) mostrar(c);
}

void CancionManager::listarPorGenero(){
    auto canciones = cargarTodas();


    GeneroArchivo repoGenero;
    int totalGeneros = repoGenero.getCantidadRegistros();

    map<int, string> mapGeneros;
    Genero g;

    for(int i = 0; i < totalGeneros; i++){
        repoGenero.leer(i, g);
        mapGeneros[g.getIdGenero()] = g.getNombreGenero();
    }

    // Ordenar por nombre del género
    sort(canciones.begin(), canciones.end(),
        [&](const Cancion& a, const Cancion& b){

            string genA = mapGeneros[a.getIdGenero()];
            string genB = mapGeneros[b.getIdGenero()];

            return genA < genB;
        }
    );

    // Mostrar
    for(auto &c : canciones) mostrar(c);
}

void CancionManager::listarPorArtista(){
    auto canciones = cargarTodas();


    ArtistaArchivo repoArtista;
    int totalArtistas = repoArtista.getCantidadRegistros();

    map<int, string> mapArtistas;
    Artista a;

    for(int i = 0; i < totalArtistas; i++){
        repoArtista.leer(i, a);
        mapArtistas[a.getId()] = a.getNombre();
    }

    // Ordenar comparando el nombre del artista
    sort(canciones.begin(), canciones.end(),
        [&](const Cancion& c1, const Cancion& c2){

            string art1 = mapArtistas[c1.getIdArtista()];
            string art2 = mapArtistas[c2.getIdArtista()];

            return art1 < art2;
        }
    );

    // Mostrar
    for(auto &c : canciones) mostrar(c);
}

void CancionManager::listarPorNacionalidad(){
    auto canciones = cargarTodas();


    ArtistaArchivo repoArtista;
    int totalArtistas = repoArtista.getCantidadRegistros();

    map<int, string> mapNacionalidad;
    Artista a;

    for(int i = 0; i < totalArtistas; i++){
        repoArtista.leer(i, a);
        mapNacionalidad[a.getId()] = a.getNacionalidad();
    }

    // Ordenar comparando la nacionalidad del artista
    sort(canciones.begin(), canciones.end(),
        [&](const Cancion& c1, const Cancion& c2){

            string nac1 = mapNacionalidad[c1.getIdArtista()];
            string nac2 = mapNacionalidad[c2.getIdArtista()];

            return nac1 < nac2;
        }
    );

    // Mostrar
    for(auto &c : canciones) mostrar(c);
}

void CancionManager::consultarPorNombreGenero(string nombreGenero){
    auto canciones = cargarTodas();

    if (canciones.empty()) {
        cout << "No hay canciones cargadas.\n";
        return;
    }

    transform(nombreGenero.begin(), nombreGenero.end(), nombreGenero.begin(), ::tolower);

    GeneroArchivo repoGenero;
    int totalGeneros = repoGenero.getCantidadRegistros();
    map<int, string> mapGeneros;
    Genero g;

    for (int i = 0; i < totalGeneros; i++) {
        repoGenero.leer(i, g);
        string nombre = g.getNombreGenero();
        transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
        mapGeneros[g.getIdGenero()] = nombre;
    }


    for (auto &c : canciones) {
        string nombreGen = mapGeneros[c.getIdGenero()];

        if (nombreGen.find(nombreGenero) != string::npos) {
            mostrar(c);
        }
    }
}


void CancionManager::consultarPorNombreArtista(string nombreArtista){
    auto canciones = cargarTodas();

    if (canciones.empty()) {
        cout << "No hay canciones cargadas.\n";
        return;
    }

    transform(nombreArtista.begin(), nombreArtista.end(), nombreArtista.begin(), ::tolower);


    ArtistaArchivo repoArtista;
    int totalArtistas = repoArtista.getCantidadRegistros();
    map<int, string> mapArtistas;
    Artista a;

    for (int i = 0; i < totalArtistas; i++) {
        repoArtista.leer(i, a);

        string nombre = a.getNombre();
        transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);

        mapArtistas[a.getId()] = nombre;
    }


    for (auto &c : canciones) {
        string nombreArt = mapArtistas[c.getIdArtista()];

        if (nombreArt.find(nombreArtista) != string::npos) {
            mostrar(c);
        }
    }
}


void CancionManager::consultarPorAnio(int anio){
    auto canciones = cargarTodas();

    for (auto &c : canciones) {
        if (c.getFecha().getAnio() == anio) {
            mostrar(c);
        }
    }
}

void CancionManager::consultarPorPais(string pais) {
    auto canciones = cargarTodas();

    if (canciones.empty()) {
        cout << "No hay canciones cargadas.\n";
        return;
    }

    transform(pais.begin(), pais.end(), pais.begin(), ::tolower);

    ArtistaArchivo repoArtista;
    Artista a;

    for (auto &c : canciones) {
        if (repoArtista.leerPorId(c.getIdArtista(), a)) {

            string nac = a.getNacionalidad();
            transform(nac.begin(), nac.end(), nac.begin(), ::tolower);

            if (nac.find(pais) != string::npos) {
                mostrar(c);
            }
        }
    }
}



bool CancionManager::consultarPorTitulo(string titulo){
    auto canciones = cargarTodas();

    if (canciones.empty()) {
        return false;
    }

    transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);

    bool encontro = false;

    for (auto &c : canciones) {
        string nombre = c.getNombreCancion();


        transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);

        // Buscar coincidencia
        if (nombre.find(titulo) != string::npos) {
            mostrar(c);
            encontro = true;
        }
    }

    return encontro;
}



