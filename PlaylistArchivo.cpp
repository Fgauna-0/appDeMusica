#include "PlaylistArchivo.h"

PlaylistArchivo::PlaylistArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo){

}

bool PlaylistArchivo::guardar(Playlist& registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return 0;
    bool ok = fwrite(&registro, sizeof(Playlist), 1, p);
    fclose(p);
    return ok;
}

bool PlaylistArchivo::leer(int pos, Playlist& registro){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Playlist), SEEK_SET);
    bool ok = fread(&registro, sizeof(Playlist), 1, p);
    fclose(p);
    return ok;
}

int PlaylistArchivo::getCantidadRegistros(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == NULL) return 0;
    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile) / sizeof(Playlist);
    fclose(pFile);
    return cantidadRegistros;
}

int PlaylistArchivo::buscarPorId(int id){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL) return -1;
    Playlist playlist;

    int i = 0;
    while(fread(&playlist, sizeof(Playlist), 1, pFile)){
        if(playlist.getIdPlaylist() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

