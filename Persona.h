#pragma once
#include<string>


class Persona
{
    public:
        Persona();
        Persona(int id, std::string dni, std::string nombre, bool estado, int reproducciones);

        ///Getters
        int getId();
        std::string getDni();
        std::string getNombre();
        bool getEstado();
        int getReproducciones();

        ///Setters
        void setId(int id);
        void setDni(std::string dni);
        void setNombre(std::string nombre);
        void setEstado(bool estado);
        void setReproducciones(int reproducciones);

        ///
        std::string toCSV();

    protected:
        int _id;
        int _reproducciones;
        char _dni[9];
        char _nombre[21];
        bool _estado;


};


