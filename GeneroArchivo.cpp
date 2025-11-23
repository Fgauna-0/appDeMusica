#include "GeneroArchivo.h"

GeneroArchivo::GeneroArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo){
}

bool GeneroArchivo::guardar(Genero& genero){
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (archivo == NULL) return false;

    bool ok = fwrite(&genero, sizeof(Genero), 1, archivo);
    fclose(archivo);
    return ok;
}

bool GeneroArchivo::leer(int pos, Genero &registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Genero), SEEK_SET);
    bool ok = fread(&registro, sizeof(Genero), 1, p);
    fclose(p);
    return ok;
}

int GeneroArchivo::getCantidadRegistros(){
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == NULL) return 0;

    fseek(archivo, 0, SEEK_END);
    int total = ftell(archivo) / sizeof(Genero);
    fclose(archivo);
    return total;
}

int GeneroArchivo::buscarId(int id){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Genero genero;

    int i = 0;
    while(fread(&genero, sizeof(Genero), 1, pFile)){
        if(genero.getIdGenero() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

int GeneroArchivo::getNuevoId(){

    return getCantidadRegistros() + 1;

}

bool GeneroArchivo::eliminarGenero(int idGenero){
    Genero g;
    leer(buscarId(idGenero), g);

    if(g.getEstado()){
        g.setEstado(false);
        return true;
    }

    return false;
}
