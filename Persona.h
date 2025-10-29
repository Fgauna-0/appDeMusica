#pragma once
#include<string>


class Persona
{
    public:
        Persona();
        Persona(int id, std::string dni, std::string nombre, bool estado, int reproducciones, std::string contrasenia);

        ///Getters
        int getId() const;
        std::string getDni() const;
        std::string getNombre() const;
        std::string getContrasenia() const;
        bool getEstado() const;
        int getReproducciones() const;

        ///Setters
        void setId(int id);
        void setDni(std::string dni);
        void setNombre(std::string nombre);
        void setContrasenia(std::string contrasena);
        void setEstado(bool estado);
        void setReproducciones(int reproducciones);

        ///Otros
        std::string toCSV();

    protected:
        int _id;
        int _reproducciones;
        char _dni[9];
        char _nombre[21];
        char _contrasenia[21];
        bool _estado;


};


