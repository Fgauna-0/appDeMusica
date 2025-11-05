#pragma once

class PlaylistCancion
{
    public:
        PlaylistCancion();
        PlaylistCancion(int idPlaylist, int idCancion, bool estado);


        ///Getters
        int getIdPlaylist();
        int getIdCancion();
        bool getEstado();

        ///Setters
        void setIdPlaylist(int id);
        void setIdCancion(int id);
        void setEstado(bool estado);


    private:
        int _idPlaylist;
        int _idCancion;
        bool _estado;
};

