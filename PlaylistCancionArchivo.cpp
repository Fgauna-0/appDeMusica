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

    for (int i = 0; i < total; i++) {
        leer(i, pc);
        if (pc.getEstado() &&
            pc.getIdPlaylist() == idPlaylist &&
            pc.getIdCancion() == idCancion) {
                return true;
        }
    }
    return false;
}

int PlaylistCancionArchivo::buscarPorId(int idCancion, int idPlaylist){

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return -1;

    PlaylistCancion pc;
    int pos = 0;

    while (fread(&pc, sizeof(PlaylistCancion), 1, pFile)) {
        if (pc.getIdCancion() == idCancion &&
            pc.getIdPlaylist() == idPlaylist) {

            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

bool PlaylistCancionArchivo::modificar(int pos, PlaylistCancion& registro){

    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, sizeof(PlaylistCancion) * pos, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(PlaylistCancion), 1, p);

    fclose(p);
    return ok;
}
