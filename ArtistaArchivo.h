#pragma once
#include <string>
#include "Artista.h"
#include "FuncionesGlobales.h"


class ArtistaArchivo
{
    public:
        ArtistaArchivo(const std::string& nombreArchivo = "artistas.dat");
        bool guardar(Artista& artista);
        bool leer(int pos, Artista &registro);
        bool leerPorId(int id, Artista &registro);
        int getCantidadRegistros();
        int buscarId(int id);
        int getNuevoId();
        int buscarPorDni(const std::string &dni);
        bool modificar(int pos, Artista& registro);
        int contarRegistros();
        bool borrar(int id);
        bool borrarPorId(int id);

        bool nombreExiste(const std::string& nombreArtista);
        bool guardarNombre(const std::string& nombreArtista, int& idGenerado);
        bool completarDatos(int idArtista, const std::string& nacionalidad, const std::string& dni, const std::string& contrasenia);
        bool iniciarSesion(const std::string& nombre, const std::string& contrasenia, int& idEncontrado);
        bool modificarNombreArtista(int idArtista, const std::string& nombreOriginal, const std::string& nuevoNombre);
        bool modificarNacionalidad(int idArtista, const std::string& nacionalidadOriginal, const std::string& nuevaNacionalidad);
        bool modificarContrasenia(int idArtista, const std::string& contraseniaOriginal, const std::string& nuevaContrasenia);
        bool borrarArtista(int idArtista, const std::string& nombre);
        int buscarPorNombre(const std::string &nombre);



    private:
        std::string _nombreArchivo;
};


