#include <cstring>
#include "Cancion.h"

using namespace std;

Cancion::Cancion()
: _idCancion(0), _idArtista(0), _idGenero(0), _reproduccionesCancion(0), _estado(false),
  _fechaPublicacion(), _duracion(0)
{
    strcpy(_nombreCancion, "");
    strcpy(_genero, "");
}

Cancion::Cancion(int idCancion, string nombreCancion, int idArtista, int idGenero,
                 bool estado, int reproducciones, Fecha fecha, float duracion, string genero)
{
    setIdCancion(idCancion);
    setNombreCancion(nombreCancion);
    setIdArtista(idArtista);
    setIdGenero(idGenero);
    setEstado(estado);
    setReproduccionesCancion(reproducciones);
    setFecha(fecha);
    setDuracion(duracion);
    setGenero(genero);
}

/// Getters
int Cancion::getIdCancion() const { return _idCancion; }
int Cancion::getIdArtista() const { return _idArtista; }
int Cancion::getIdGenero() const { return _idGenero; }
int Cancion::getReproduccionesCancion() const { return _reproduccionesCancion; }

string Cancion::getNombreCancion() const {
    string nombre(_nombreCancion);
    while(!nombre.empty() && nombre.back() == ' ')
        nombre.pop_back();
    return nombre;
}

bool Cancion::getEstado() const { return _estado; }
Fecha Cancion::getFecha() const { return _fechaPublicacion; }
float Cancion::getDuracion() const { return _duracion; }

string Cancion::getGenero() const {
    string g(_genero);
    while(!g.empty() && g.back() == ' ')
        g.pop_back();
    return g;
}

/// Setters
void Cancion::setIdCancion(int id) { _idCancion = id; }
void Cancion::setIdArtista(int id) { _idArtista = id; }
void Cancion::setIdGenero(int id) { _idGenero = id; }
void Cancion::setReproduccionesCancion(int reproducciones) { _reproduccionesCancion = reproducciones; }

void Cancion::setNombreCancion(string nombre){
    strncpy(_nombreCancion, nombre.c_str(), sizeof(_nombreCancion) - 1);
    _nombreCancion[sizeof(_nombreCancion)-1] = '\0';
}

void Cancion::setEstado(bool estado){ _estado = estado; }
void Cancion::setFecha(Fecha fecha){ _fechaPublicacion = fecha; }
void Cancion::setDuracion(float duracion){ _duracion = duracion; }

void Cancion::setGenero(const string &genero){
    strncpy(_genero, genero.c_str(), sizeof(_genero) - 1);
    _genero[sizeof(_genero)-1] = '\0';
}

/// Comportamientos
void Cancion::sumarReproduccion(){ _reproduccionesCancion++; }

string Cancion::toCSV(){
    return to_string(_idCancion) + "," + string(_nombreCancion) + "," +
           to_string(_idArtista) + "," + to_string(_idGenero) + "," +
           to_string(_estado) + "," + to_string(_reproduccionesCancion) + "," +
           _fechaPublicacion.toCSV() + "," + to_string(_duracion) + "," + _genero;
}

