#include <iostream>
#include <cstring>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
:_dia(0), _mes(0), _anio(0){

}

Fecha::Fecha(int d, int m, int a){

    if(fechaValida(d,m,a)){
        setDia(d);
        setMes(m);
        setAnio(a);
    }else{
        setDia(-1);
        setMes(-1);
        setAnio(-1);
    }
}

///Getters
int Fecha::getDia() const { return _dia; }

int Fecha::getMes()const { return _mes; }

int Fecha::getAnio()const { return _anio; }



///Setters
void Fecha::setDia(int d){
    _dia = d;
}

void Fecha::setMes(int m){
    _mes = m;
}

void Fecha::setAnio(int a){
    _anio = a;
}


///
bool Fecha::cargarFecha(){
    int dia, mes, anio;

    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;

    if(fechaValida(dia, mes, anio)){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
        return true;
    }

    // Fecha inválida
    setDia(-1);
    setMes(-1);
    setAnio(-1);
    return false;
}



bool Fecha::esBisiesto(int a){
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

bool Fecha::fechaValida(int d, int m, int a){
    if(m < 1 || m > 12 || d < 1 || a < 1) return false;

    int diasMes[] = {31, (esBisiesto(a) ? 29:28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return d <= diasMes[m - 1];
}

bool Fecha::operator==(const Fecha& otra){
    return (_dia == otra._dia && _mes == otra._mes && _anio == otra._anio);
}

bool Fecha::operator<(const Fecha& otra){
    if(_anio != otra._anio) return _anio < otra._anio;
    if(_mes != otra._mes) return _mes < otra._mes;
    return _dia < otra._dia;
}



/// MOSTRAMOS O EXPORTAMOS TEXTO
string Fecha::toCSV(){
    return to_string(_dia) +
    "/" + to_string(_mes) +
    "/" + to_string(_anio);
}
