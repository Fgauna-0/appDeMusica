#include "ArtistaArchivo.h"
#include <cstdio>
#include <cstring>

ArtistaArchivo::ArtistaArchivo(const std::string& nombreArchivo)
: _nombreArchivo(nombreArchivo) {
}

bool ArtistaArchivo::guardar(Artista &a) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (!archivo) return false;
    bool ok = fwrite(&a, sizeof(Artista), 1, archivo);
    fclose(archivo);
    return ok;
}


int ArtistaArchivo::getCantidadRegistros() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return 0;

    fseek(archivo, 0, SEEK_END);
    int total = ftell(archivo) / sizeof(Artista);
    fclose(archivo);
    return total;
}

bool ArtistaArchivo::leer(int pos, Artista &registro) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return false;

    fseek(archivo, pos * sizeof(Artista), SEEK_SET);
    bool ok = fread(&registro, sizeof(Artista), 1, archivo);
    fclose(archivo);
    return ok;
}

bool ArtistaArchivo::leerPorId(int id, Artista &registro) {
    int pos = buscarId(id);
    if (pos == -1) return false;

    return leer(pos, registro);
}

int ArtistaArchivo::buscarId(int id) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return -1;

    Artista a;
    int i = 0;
    while (fread(&a, sizeof(Artista), 1, archivo)) {
        if (a.getId() == id) {
            fclose(archivo);
            return i;
        }
        i++;
    }
    fclose(archivo);
    return -1;
}

int ArtistaArchivo::getNuevoId() {
    return getCantidadRegistros() + 1;
}

int ArtistaArchivo::buscarPorNombre(const std::string &nombre) {
    Artista a;
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        if (!leer(i, a)) continue;
        if (a.getNombre() == nombre && a.getEstado()) {
            return i;
        }
    }
    return -1;
}


bool ArtistaArchivo::modificar(int pos, Artista &registro) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (!archivo) return false;

    fseek(archivo, pos * sizeof(Artista), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Artista), 1, archivo);
    fclose(archivo);
    return ok;
}

bool ArtistaArchivo::borrar(int id) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return false;

    FILE* temp = fopen("temp_artistas.dat", "wb");
    if (!temp) { fclose(archivo); return false; }

    Artista a;
    bool encontrada = false;

    while (fread(&a, sizeof(Artista), 1, archivo) == 1) {
        if (a.getId() != id) {
            fwrite(&a, sizeof(Artista), 1, temp);
        } else {
            encontrada = true;
        }
    }

    fclose(archivo);
    fclose(temp);

    if (encontrada) {
        remove(_nombreArchivo.c_str());
        rename("temp_artistas.dat", _nombreArchivo.c_str());
    } else {
        remove("temp_artistas.dat");
    }

    return encontrada;
}

int ArtistaArchivo::buscarPorDni(const std::string &dni) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return -1;

    Artista a;
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        if (!leer(i, a)) continue;
        if (a.getDni() == dni) {
            fclose(archivo);
            return i;
        }
    }
    fclose(archivo);
    return -1;
}
bool ArtistaArchivo::borrarPorId(int id) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (!archivo) return false;

    FILE* temp = fopen("temp_artistas.dat", "wb");
    if (!temp) { fclose(archivo); return false; }

    Artista a;
    bool encontrada = false;
    int total = getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        if (!leer(i, a)) continue;
        if (a.getId() != id) {
            fwrite(&a, sizeof(Artista), 1, temp);
        } else {
            encontrada = true;
        }
    }

    fclose(archivo);
    fclose(temp);

    if (encontrada) {
        remove(_nombreArchivo.c_str());
        rename("temp_artistas.dat", _nombreArchivo.c_str());
    } else {
        remove("temp_artistas.dat");
    }

    return encontrada;
}

