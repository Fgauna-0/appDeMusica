#pragma once
#include <string>



class Playlist
{
    public:
        Playlist();

        ///Getters
        int getIdPlaylist();
        int getIdSuscriptor();
        int getIdCancion();
        int getReproducciones();
        std::string getNombrePlaylist();
        bool getEstado();

        ///Setters
        void setIdPlaylist(int id);
        void setIdSuscriptor(int idSuscriptor);
        void setIdCancion(int idCancion);
        void setReproducciones(int reproducciones);
        void setNombrePlaylist(std::string nombre);
        void setEstado(bool estado);

    protected:

    private:
        int _idPlaylist;
        int _idSuscriptor;
        int _idCancion;
        int _reproducciones;
        char _nombrePlaylist[21];
        bool _estado;
};

