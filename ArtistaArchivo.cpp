#include "ArtistaArchivo.h"

ArtistaArchivo::ArtistaArchivo(std::string nombreArchivo)
:_nombreArchivo(nombreArchivo){

}

bool ArtistaArchivo::guardar(Artista& artista){
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (archivo == NULL) return false;

    bool ok = fwrite(&artista, sizeof(Artista), 1, archivo);
    fclose(archivo);
    return ok;
}

bool ArtistaArchivo::leer(int pos, Artista &registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Artista), SEEK_SET);
    bool ok = fread(&registro, sizeof(Artista), 1, p);
    fclose(p);
    return ok;
}

bool ArtistaArchivo::leerPorId(int id, Artista &registro){
    int pos = buscarId(id);
    if(leer(pos,registro)){
        return true;
    }
    return false;
}

int ArtistaArchivo::getCantidadRegistros(){
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == NULL) return 0;

    fseek(archivo, 0, SEEK_END);
    int total = ftell(archivo) / sizeof(Artista);
    fclose(archivo);
    return total;
}

int ArtistaArchivo::buscarId(int id){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Artista artista;

    int i = 0;
    while(fread(&artista, sizeof(Artista), 1, pFile)){
        if(artista.getId() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

int ArtistaArchivo::getNuevoId(){

    return getCantidadRegistros() + 1;

}

bool ArtistaArchivo::eliminarArtista(Artista &registro){
    if(registro.getEstado()){
        registro.setEstado(false);
        return true;
    }

    return false;
}

int ArtistaArchivo::buscarPorNombre(std::string nombre){

    FuncionesGlobales f;
    Artista a;
    int total = getCantidadRegistros();

    for(int i = 0; i < total; i++){
        leer(i, a);
        if(f.aMinuscula(a.getNombre()) == f.aMinuscula(nombre)){
            return i;
        }
    }
    return -1;
}

int ArtistaArchivo::buscarPorDni(std::string dni){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return -1;
    }
    Artista artista;

    int i = 0;

    while(fread(&artista, sizeof(Artista), 1, pFile)){
        if(artista.getDni() == dni){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;

}

bool ArtistaArchivo::modificar(int pos, Artista& registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, sizeof(Artista) * pos, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Artista), 1, p);

    fclose(p);
    return ok;
}
