#pragma once
#include "CancionManager.h"
#include "ArtistaManager.h"
#include "SuscriptorManager.h"
#include "PlaylistManager.h"

class MenuAdministrador {
public:
    MenuAdministrador(CancionManager &cm, ArtistaManager &am, SuscriptorManager &sm, PlaylistManager &pm);

    void iniciar();

private:
    CancionManager &_cm;
    ArtistaManager &_am;
    SuscriptorManager &_sm;
    PlaylistManager &_pm;
    FuncionesGlobales fg;

    void menuListados();
    void menuConsultas();

    void listadoCanciones();
    void listadoArtistas();
    void listadoSuscriptores();
    void listadoPlaylists();

    void consultaCanciones();
    void consultarArtistas();
    void consultarSuscriptores();
    void consultarPlaylists();
};

