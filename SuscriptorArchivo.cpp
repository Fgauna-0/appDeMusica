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

bool SuscriptorArchivo::leer(int pos, Suscriptor& registro){

    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Suscriptor), SEEK_SET);
    bool ok = fread(&registro, sizeof(Suscriptor), 1, p);
    fclose(p);
    return ok;
}

bool SuscriptorArchivo::leerPorId(int id, Suscriptor& registro){
    int pos = buscarId(id);
    if(leer(pos,registro)){
        return true;
    }
    return false;
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

int SuscriptorArchivo::getNuevoId(){

    return getCantidadRegistros() + 1;

}

int SuscriptorArchivo::buscarPorDni(std::string dni){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Suscriptor suscriptor;

    int i = 0;

    while(fread(&suscriptor, sizeof(Suscriptor), 1, pFile)){
        if(suscriptor.getDni() == dni){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;

}

int SuscriptorArchivo::buscarPorEmail(std::string email){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Suscriptor suscriptor;

    int i = 0;

    while(fread(&suscriptor, sizeof(Suscriptor), 1, pFile)){
        if(suscriptor.getEmail() == email){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

bool SuscriptorArchivo::modificar(int pos, Suscriptor& registro){

    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, sizeof(Suscriptor) * pos, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Suscriptor), 1, p);

    fclose(p);
    return ok;
}
