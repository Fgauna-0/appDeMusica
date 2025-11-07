#include "PlaylistCancionArchivo.h"

PlaylistCancionArchivo::PlaylistCancionArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo){

}

bool PlaylistCancionArchivo::guardar(PlaylistCancion& registro){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr){
        return false;
    }

    bool resultado = fwrite(&registro, sizeof(PlaylistCancion), 1 , pFile);

    fclose(pFile);

    return resultado;
}

bool PlaylistCancionArchivo::leer(int pos, PlaylistCancion& registro){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return false;
    }

    PlaylistCancion playlistCancion;

    fseek(pFile, sizeof(PlaylistCancion) * pos, SEEK_SET);
    bool ok = fread(&playlistCancion, sizeof(PlaylistCancion), 1, pFile);

    fclose(pFile);

    return ok;
}

int PlaylistCancionArchivo::getCantidadRegistros(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL){
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile) / sizeof(PlaylistCancion);
    fclose(pFile);
    return cantidadRegistros;
}
