#include "FuncionesGlobales.h"

FuncionesGlobales::FuncionesGlobales()
{
    //ctor
}

std::string FuncionesGlobales::aMinuscula(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
