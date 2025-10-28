#pragma once
#include <string>

using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int d, int m, int a);

        ///Getters
        int getDia();
        int getMes();
        int getAnio();

        ///Setters
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);

        ///Comportamientos
        bool esBisiesto(int a);
        bool fechaValida(int d, int m, int a);
        string toCSV();

        ///Comparaciones
        bool operator==(const Fecha& otra);
        bool operator<(const Fecha& otra);

    private:
        int _dia;
        int _mes;
        int _anio;
};

