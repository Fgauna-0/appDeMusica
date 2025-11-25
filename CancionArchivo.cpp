#include "CancionArchivo.h"
#include <cstdio>
#include <cstring>

CancionArchivo::CancionArchivo(const std::string& nombreArchivo)
: _nombreArchivo(nombreArchivo){}

bool CancionArchivo::guardar(Cancion& cancion) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (!archivo) return false;
    bool ok = fwrite(&cancion, sizeof(Cancion), 1, archivo) == 1;
    fclose(archivo);
    return ok;
}

int CancionArchivo::getCantidadRegistros() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return 0;
    fseek(archivo, 0, SEEK_END);
    int total = ftell(archivo) / sizeof(Cancion);
    fclose(archivo);
    return total;
}

bool CancionArchivo::leer(int pos, Cancion &registro) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (!p) return false;
    fseek(p, pos * sizeof(Cancion), SEEK_SET);
    bool ok = fread(&registro, sizeof(Cancion), 1, p) == 1;
    fclose(p);
    return ok;
}

bool CancionArchivo::leerPorId(int id, Cancion &registro){
    int pos = buscarId(id);
    if(pos == -1) return false;
    return leer(pos, registro);
}

int CancionArchivo::buscarId(int id){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(!pFile) return -1;

    Cancion c;
    int i = 0;
    while(fread(&c, sizeof(Cancion), 1, pFile) == 1){
        if(c.getIdCancion() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

int CancionArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}

int CancionArchivo::buscarPorNombre(int idArtista, const std::string& nombre) {
    FuncionesGlobales f;
    Cancion c;
    int total = getCantidadRegistros();

    for(int i = 0; i < total; i++){
        if(!leer(i, c)) continue;
        // comparo nombre y artista
        if(c.getIdArtista() == idArtista &&
           f.aMinuscula(c.getNombreCancion()) == f.aMinuscula(nombre)) {
            return i;
        }
    }
    return -1;
}

bool CancionArchivo::modificar(int pos, Cancion& registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if(!p) return false;

    fseek(p, sizeof(Cancion) * pos, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Cancion), 1, p) == 1;
    fclose(p);
    return ok;
}

bool CancionArchivo::borrarCancion(int idArtista, const std::string& nombreCancion){
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if(!archivo) return false;

    FILE* temp = fopen("temp_canciones.dat", "wb");
    if(!temp) { fclose(archivo); return false; }

    Cancion c;
    bool encontrada = false;

    while(fread(&c, sizeof(Cancion), 1, archivo) == 1){
        if(!(c.getIdArtista() == idArtista && c.getNombreCancion() == nombreCancion)){
            fwrite(&c, sizeof(Cancion), 1, temp);
        } else {
            encontrada = true;
        }
    }

    fclose(archivo);
    fclose(temp);

    if(encontrada){
        remove(_nombreArchivo.c_str());
        rename("temp_canciones.dat", _nombreArchivo.c_str());
    } else {
        remove("temp_canciones.dat");
    }

    return encontrada;
}

