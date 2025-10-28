#pragma once
#include <string>
#include "Fecha.h"
using namespace std;


class Cancion
{
    public:
        Cancion();
        Cancion(int idCancion, string nombreCancion, int idArtista, int idGenero, bool estado, int reproducciones, Fecha fecha);

        ///Getters
        int getIdCancion();
        int getIdArtista();
        int getIdGenero();
        int getReproduccionesCancion();
        string getNombreCancion();
        bool getEstado();
        Fecha getFecha();

        ///Setters
        void setIdCancion(int id);
        void setIdArtista(int id);
        void setIdGenero(int id);
        void setReproduccionesCancion(int reproducciones);
        void setNombreCancion(string nombre);
        void setEstado(bool estado);
        void setFecha(Fecha fecha);

        ///Comportamientos
        string toCSV();

    protected:

    private:
        int _idCancion;
        int _idArtista;
        int _idGenero;
        int _reproduccionesCancion;
        char _nombreCancion[51];
        bool _estado;
        Fecha _fechaPublicacion;

};


