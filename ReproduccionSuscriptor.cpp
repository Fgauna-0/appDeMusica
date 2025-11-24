#include "ReproduccionSuscriptor.h"

ReproduccionSuscriptor::ReproduccionSuscriptor()
: _idSuscriptor(0), _idCancion(0), _reproducciones(0)
{
}

int ReproduccionSuscriptor::getIdSuscriptor() { return _idSuscriptor; }
int ReproduccionSuscriptor::getIdCancion() { return _idCancion; }
int ReproduccionSuscriptor::getReproducciones() { return _reproducciones; }

void ReproduccionSuscriptor::setIdSuscriptor(int id) {
    _idSuscriptor = id;
}

void ReproduccionSuscriptor::setIdCancion(int id) {
    _idCancion = id;
}

void ReproduccionSuscriptor::sumarReproduccion() {
    _reproducciones++;
}

