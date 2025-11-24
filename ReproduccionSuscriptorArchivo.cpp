#include "ReproduccionSuscriptorArchivo.h"
#include <cstdio>

ReproduccionSuscriptorArchivo::ReproduccionSuscriptorArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {}

bool ReproduccionSuscriptorArchivo::guardar(ReproduccionSuscriptor& registro) {
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;

    bool ok = fwrite(&registro, sizeof(ReproduccionSuscriptor), 1, p);
    fclose(p);
    return ok;
}

bool ReproduccionSuscriptorArchivo::modificar(int pos, ReproduccionSuscriptor& registro) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(ReproduccionSuscriptor), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(ReproduccionSuscriptor), 1, p);
    fclose(p);
    return ok;
}

bool ReproduccionSuscriptorArchivo::leer(int pos, ReproduccionSuscriptor& registro) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(ReproduccionSuscriptor), SEEK_SET);
    bool ok = fread(&registro, sizeof(ReproduccionSuscriptor), 1, p);
    fclose(p);
    return ok;
}

int ReproduccionSuscriptorArchivo::buscar(int idSuscriptor, int idCancion) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return -1;

    ReproduccionSuscriptor reg;
    int pos = 0;

    while (fread(&reg, sizeof(ReproduccionSuscriptor), 1, p)) {
        if (reg.getIdSuscriptor() == idSuscriptor &&
            reg.getIdCancion() == idCancion) {

            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

int ReproduccionSuscriptorArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;

    fseek(p, 0, SEEK_END);
    int total = ftell(p) / sizeof(ReproduccionSuscriptor);
    fclose(p);
    return total;
}
