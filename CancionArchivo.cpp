#include "CancionArchivo.h"

CancionArchivo::CancionArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo){

}

bool CancionArchivo::guardar(Cancion& cancion) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (archivo == NULL) return false;

    bool ok = fwrite(&cancion, sizeof(Cancion), 1, archivo);
    fclose(archivo);
    return ok;
}

int CancionArchivo::getCantidadRegistros() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == NULL) return 0;

    fseek(archivo, 0, SEEK_END);
    int total = ftell(archivo) / sizeof(Cancion);
    fclose(archivo);
    return total;
}

bool CancionArchivo::leer(int pos, Cancion &registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Cancion), SEEK_SET);
    bool ok = fread(&registro, sizeof(Cancion), 1, p);
    fclose(p);
    return ok;
}

bool CancionArchivo::leerPorId(int id, Cancion &registro){
    int pos = buscarId(id);
    if(leer(pos,registro)){
        return true;
    }
    return false;
}

int CancionArchivo::buscarId(int id){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Cancion cancion;

    int i = 0;
    while(fread(&cancion, sizeof(Cancion), 1, pFile)){
        if(cancion.getIdCancion() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

int CancionArchivo::getNuevoId(){

    return getCantidadRegistros() + 1;

}

int CancionArchivo::buscarPorNombre(std::string nombre){

    FuncionesGlobales f;
    Cancion c;
    int total = getCantidadRegistros();

    for(int i = 0; i < total; i++){
        leer(i, c);
        if(f.aMinuscula(c.getNombreCancion()) == f.aMinuscula(nombre)){
            return i;
        }
    }
    return -1;
}

bool CancionArchivo::modificar(int pos, Cancion& registro){

    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, sizeof(Cancion) * pos, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Cancion), 1, p);

    fclose(p);
    return ok;

}
