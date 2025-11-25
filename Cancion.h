#pragma once
#include <string>
#include "Fecha.h"
using namespace std;

class Cancion
{
public:
    Cancion();
    Cancion(int idCancion, string nombreCancion, int idArtista, int idGenero,
            bool estado, int reproducciones, Fecha fecha, float duracion, string genero);

    /// Getters
    int getIdCancion() const;
    int getIdArtista() const;
    int getIdGenero() const;
    int getReproduccionesCancion() const;
    string getNombreCancion() const;
    bool getEstado() const;
    Fecha getFecha() const;
    float getDuracion() const;
    string getGenero() const;

    /// Setters
    void setIdCancion(int id);
    void setIdArtista(int id);
    void setIdGenero(int id);
    void setReproduccionesCancion(int reproducciones);
    void setNombreCancion(string nombre);
    void setEstado(bool estado);
    void setFecha(Fecha fecha);
    void setDuracion(float duracion);
    void setGenero(const string &genero);

    /// Comportamientos
    void sumarReproduccion();
    string toCSV();

private:
    int _idCancion;
    int _idArtista;
    int _idGenero;
    int _reproduccionesCancion;
    char _nombreCancion[51];
    bool _estado;
    Fecha _fechaPublicacion;
    float _duracion;
    char _genero[31];
};



