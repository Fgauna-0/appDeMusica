#pragma once
#include <string>



class Playlist
{
    public:
        Playlist();
        Playlist(int idPlaylist, int idSuscriptor, int reproducciones, std::string nombre, bool estado);

        ///Getters
        int getIdPlaylist();
        int getIdSuscriptor();
        int getReproducciones();
        std::string getNombrePlaylist();
        bool getEstado();

        ///Setters
        void setIdPlaylist(int id);
        void setIdSuscriptor(int idSuscriptor);
        void setReproducciones(int reproducciones);
        void setNombrePlaylist(std::string nombre);
        void setEstado(bool estado);
        void sumarReproduccion();

    protected:

    private:
        int _idPlaylist;
        int _idSuscriptor;
        int _reproducciones;
        char _nombrePlaylist[51];
        bool _estado;
};

