#pragma once
#include <string>

using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int d, int m, int a);

        ///Getters
        int getDia() const;
        int getMes() const;
        int getAnio() const;

        ///Setters
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        ///Comportamientos
        bool esBisiesto(int a);
        bool fechaValida(int d, int m, int a);
        void cargarFecha();
        string toCSV();

        ///Comparaciones
        bool operator==(const Fecha& otra);
        bool operator<(const Fecha& otra);

    private:
        int _dia;
        int _mes;
        int _anio;
};

