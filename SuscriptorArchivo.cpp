#include "SuscriptorArchivo.h"
#include <iostream>

SuscriptorArchivo::SuscriptorArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {

}

bool SuscriptorArchivo::guardar(Suscriptor suscriptor){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr){
        return false;
    }

    bool resultado = fwrite(&suscriptor, sizeof(Suscriptor), 1 , pFile);

    fclose(pFile);

    return resultado;
}

Suscriptor SuscriptorArchivo::leer(int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return Suscriptor();
    }

    Suscriptor suscriptor;

    fseek(pFile, sizeof(Suscriptor) * pos, SEEK_SET);
    fread(&suscriptor, sizeof(Suscriptor), 1, pFile);

    fclose(pFile);

    return suscriptor;
}

int SuscriptorArchivo::buscarId(int id){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Suscriptor suscriptor;

    int i = 0;
    while(fread(&suscriptor, sizeof(Suscriptor), 1, pFile)){
        if(suscriptor.getId() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}


int SuscriptorArchivo::getCantidadRegistros(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile) / sizeof(Suscriptor);
    fclose(pFile);
    return cantidadRegistros;
}
