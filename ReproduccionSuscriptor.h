#pragma once

class ReproduccionSuscriptor
{
public:
    ReproduccionSuscriptor();

    int getIdSuscriptor();
    int getIdCancion();
    int getReproducciones();

    void setIdSuscriptor(int id);
    void setIdCancion(int id);
    void sumarReproduccion();

private:
    int _idSuscriptor;
    int _idCancion;
    int _reproducciones;
};

