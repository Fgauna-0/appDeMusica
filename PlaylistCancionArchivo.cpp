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

    fseek(pFile, sizeof(PlaylistCancion) * pos, SEEK_SET);
    bool ok = fread(&registro, sizeof(PlaylistCancion), 1, pFile);

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

bool PlaylistCancionArchivo::existeRelacion(int idPlaylist, int idCancion){
    PlaylistCancion pc;
    int total = getCantidadRegistros();

    for(int i = 0; i < total; i++){
        leer(i, pc);
        if(pc.getIdPlaylist() == idPlaylist && pc.getIdCancion() == idCancion){
            return true;
        }
    }
    return false;
}

int PlaylistCancionArchivo::buscarPorId(int idCancion, int idPlaylist){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == NULL) return -1;
    PlaylistCancion playlist;

    int i = 0;
    while(fread(&playlist, sizeof(PlaylistCancion), 1, pFile)){
        if(playlist.getIdCancion() == idCancion && playlist.getIdPlaylist() == idPlaylist){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}
