#include "MenuSuscriptor.h"
#include <iostream>
using namespace std;

MenuSuscriptor::MenuSuscriptor(SuscriptorManager& sm, CancionManager& cm, PlaylistManager& pm)
: _sm(sm), _cm(cm), _pm(pm){
}

void MenuSuscriptor::iniciar() {

    if(_sm.haySesion()) {

        //sincronizar el suscriptor actual
        _pm.setSuscriptorActual(_sm.getSuscriptorActual());

        menuPrincipal();
    }
}

void MenuSuscriptor::menuPrincipal() {
    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#            MENU USUARIO              #" << endl;
        cout << "=======================================" << endl;
        cout << "-" << _sm.getSuscriptorActual().getNombre() << endl;
        cout << "1. Buscar cancion\n";
        cout << "2. Perfil\n";
        cout << "3. Playlist\n";
        cout << "0. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {

            case 1:
                menuBuscarCancion();
                break;

            case 2:
                menuPerfil();
                break;

            case 3:
                menuPlaylist();
                break;
            case 0:
                _sm.cerrarSesion();
                _pm.setSuscriptorActual(Suscriptor());
                return;
        }

    } while (true);
}

void MenuSuscriptor::menuBuscarCancion() {
    int opcion;

    do {
        system("cls");

        cout << "=======================================" << endl;
        cout << "#          BUSCAR CANCION              #" << endl;
        cout << "=======================================" << endl;
        cout << "1. Buscar por nombre\n";
        cout << "2. Buscar por artista\n";
        cout << "3. Buscar por genero \n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        cout << endl;

        /*if (opcion == 1) {
            buscarCancionesPorNombre();
        }

        else if (opcion == 2) {
            buscarCancionesPorArtista();
        }*/
        switch(opcion){
        case 1:
        buscarCancionesPorNombre();
        break;
        case 2:
        buscarCancionesPorArtista();
        break;
        case 3:
        buscarCancionesPorGenero();
        break;
        case 0:
        return;
        break;
        default:
            cout << "Opcion incorrecta. \n";
        }



    } while (opcion != 0);
}

void MenuSuscriptor::accionesSobreCancion(int idCancion) {
    if (idCancion == 0) return;

    system("cls");
    _cm.mostrarCancionPorId(idCancion);

    cout << endl;

    cout << "1. Reproducir\n";
    cout << "2. Agregar a playlist\n";
    cout << "0. Volver\n";
    int opcion;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        system("cls");

        _cm.reproducirCancion(idCancion, _sm.getSuscriptorActual().getId());

        system("pause");
    }
    else if (opcion == 2) {
        system("cls");
        int idP;
        _pm.mostrarPlaylistDelSuscriptor(_sm.getSuscriptorActual().getId());
        cout << "Opcion (ID playlist): ";
        cin >> idP;
        cin.ignore();
        _pm.agregarCancionAPlaylistPorIdPlaylistYIdCancion(idP,idCancion);
        cout << endl;
        system("pause");
    }
}

void MenuSuscriptor::buscarCancionesPorNombre(){

    string nombre;

    system("cls");

    cout << "==Buscar por nombre de cancion==" << endl << endl;

    cout << endl;

    cout << "Ingresar nombre (0 para volver): ";
    getline(cin, nombre);

    if(nombre == "0") return;

    cout << endl;

    system("cls");

    cout << "==Canciones encontradas==" << endl << endl;

    if(!_cm.mostrarCancionesPorNombre(nombre)){
        system("pause");
        return;
    }

    int idCancion;
    cout << endl;
    cout << "ID de cancion para acciones (o 0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    accionesSobreCancion(idCancion);
}

void MenuSuscriptor::buscarCancionesPorArtista(){

    string nombre;

    system("cls");

    cout << "==Buscar por nombre de artista==" << endl;

    cout << endl;

    cout << "Ingrese artista (0 para volver): ";
    getline(cin, nombre);

    if(nombre == "0") return;

    system("cls");

    cout << "==Canciones encontradas==" << endl << endl;

    if(!_cm.mostrarCancionesPorArtista(nombre)){
        system("pause");
        return;
    }

    int idCancion;
    cout << endl;
    cout << "ID de cancion para acciones (o 0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    accionesSobreCancion(idCancion);
}

void MenuSuscriptor::menuPerfil(){



    int opcion;

    do{

    system("cls");

    cout << "=======================================" << endl;
    cout << "#               PERFIL                #" << endl;
    cout << "=======================================" << endl;

    cout << "1.Ver datos del perfil \n";
    cout << "2.Modificar perfil \n";
    cout << "3.Eliminar perfil \n";
    cout << "0.Volver \n";

    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion){
    case 1:
    verDatosDelPerfil();
    break;
    case 2:
    menuModificarPerfil();
    break;
    case 3:
    eliminarPerfil();
    break;
    case 0:
    return;
    break;
    default:
        cout << "Opcion incorrecta. \n";
    }
    }
    while(opcion != 0);

}

void MenuSuscriptor::menuModificarPerfil(){
    int opcion;

    system("cls");

    cout << "=======================================" << endl;
    cout << "#         MODIFICAR PERFIL             #" << endl;
    cout << "=======================================" << endl;

    cout << "1. Modificar nombre del perfil \n";
    cout << "2. Modificar tipo de suscripcion \n";
    cout << "0. Volver\n";
    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion){
        case 1:
        modificarNombre();
        break;
        case 2:
        modificarSuscripcion();
        break;
        case 0:
        return;
        break;
        default:
        cout << "Opcion incorrecta. \n";
        system("pause");
    }
}

void MenuSuscriptor::modificarNombre(){

    string nombre;

    system("cls");

    cout << "=======================================" << endl;
    cout << "#         MODIFICAR NOMBRE             #" << endl;
    cout << "=======================================" << endl;

    cout << "Ingrese el nuevo nombre(0 para volver): ";
    getline(cin,nombre);

    if(nombre == "0") return;
    cin.ignore();



    cout << endl;

    if(_sm.modificarNombre(nombre,_sm.getSuscriptorActual())){
        cout << "Nombre modificado exitosamente!. \n";
        cout << endl;
        system("pause");
    }
    else{
        cout <<"Ha ocurrido un error al modificar el nombre. \n";
        cout << endl;
        system("pause");
    }
}

void MenuSuscriptor::modificarSuscripcion(){

    int suscripcion;

    system("cls");

    cout << "=======================================" << endl;
    cout << "#        MODIFICAR SUSCRIPCION         #" << endl;
    cout << "=======================================" << endl;

    cout << "Suscripcion actual: " << _sm.getSuscriptorActual().tipoDeSuscripcionToCSV();

    cout << endl;
    cout << endl;

    cout << "Elija la suscripcion: " <<endl;
    cout << "1 - Gratuita (Limitada con publicidad) \n";
    cout << "2 - Premium (Ilimitada sin publicidad) \n";
    cout << "0 - Volver \n" << endl;
    cout << "Opcion: ";
    cin >> suscripcion;

    cin.ignore();

    if(suscripcion == 0) return;

    if(suscripcion == _sm.getSuscriptorActual().getTipoSuscripcion()){
        cout << "Ya tiene esta suscripcion. \n";
        cout << endl;
        system("pause");
        return;
    }

    if(_sm.modificarSuscripcion(suscripcion, _sm.getSuscriptorActual())){
        cout << "Suscripcion modificada! \n";
        system("pause");
        cout << endl;
        return;
    }else{
        cout << "Ha ocurrido un error  \n";
        system("pause");
        cout << endl;
        return;
    }
}

void MenuSuscriptor::menuCrearPlaylist(){

    int opcion;

    system("cls");

    cout << "=======================================" << endl;
    cout << "#          CREAR PLAYLIST              #" << endl;
    cout << "=======================================" << endl;

    cout << "1.Ver Playlists actuales" << endl;
    cout << "2.Crear Playlist" << endl;
    cout << "0.Volver" << endl;

    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();

    switch(opcion){
    case 1:
        verPlaylistsActuales();
    break;
    case 2:
        crearPlaylist();
    break;
    case 0:
    return;
    break;
    default:
        cout << "Opcion incorrecta. \n";

    }

}

bool MenuSuscriptor::verPlaylistsActuales(){

    system("cls");

    cout << "=======================================" << endl;
    cout << "#        PLAYLISTS ACTUALES            #" << endl;
    cout << "=======================================" << endl;
    if(_pm.mostrarPlaylistDelSuscriptor(_sm.getSuscriptorActual().getId())){
        return true;
    }


    return false;
}

void MenuSuscriptor::crearPlaylist(){

    system("cls");

    string nombre;

    cout << "=======================================" << endl;
    cout << "#            CREAR PLAYLIST            #" << endl;
    cout << "=======================================" << endl;
    cout << "-Ingrese el nombre de la playlist (0 para volver): " << endl;
    cout << "Nombre: ";
    getline(cin, nombre);

    if(nombre == "0") return;


    if(_pm.crearPlaylist(_sm.getSuscriptorActual().getId(),nombre)){
        cout << "Playlist creada exitosamente!! \n";
        system("pause");
    }
    else{
        cout << "Ha ocurrido un error. \n";
        system("pause");
    }


}

void MenuSuscriptor::verDatosDelPerfil(){

    system("cls");

    cout << "=======================================" << endl;
    cout << "#         DATOS DEL PERFIL             #" << endl;
    cout << "=======================================" << endl;

    cout << "Nombre: " << _sm.getSuscriptorActual().getNombre() << endl;
    cout << "Apellido: " << _sm.getSuscriptorActual().getApellido() << endl;
    cout << "DNI: " << _sm.getSuscriptorActual().getDni() << endl;
    cout << "Email: " << _sm.getSuscriptorActual().getEmail() << endl;
    cout << "Tipo de suscripcion: " << _sm.getSuscriptorActual().tipoDeSuscripcionToCSV() << endl;
    cout << "Escuchaste: " << _sm.getSuscriptorActual().getReproducciones() << " cancion/nes"  << endl;
    cout << "Cancion mas escuchada: ";
    _cm.mostrarMasEscuchadaPorUsuario(_sm.getSuscriptorActual().getId());

    cout << endl;

    system("pause");


}

void MenuSuscriptor::menuPlaylist(){

    int opcion;

    do{

        system("cls");

        cout << "=======================================" << endl;
        cout << "#              PLAYLISTS              #" << endl;
        cout << "=======================================" << endl;

        cout << "1.Ver playlists \n";
        cout << "2.Ver canciones de playlist \n";
        cout << "3.Crear playlist \n";
        cout << "4.Eliminar playlist \n";
        cout << "5.Agregar cancion a playlist \n";
        cout << "6.Eliminar cancion de playlist \n";
        cout << "7.Reproducir playlist \n";
        cout << "0.Volver \n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch(opcion){
        case 1:
        verPlaylistsActuales();
        system("pause");
        break;
        case 2:
        verCancionesDePlaylist();
        system("pause");
        break;
        case 3:
        crearPlaylist();
        system("pause");
        break;
        case 4:
        eliminarPlaylist();
        system("pause");
        break;
        case 5:
        agregarCancionAPlaylist();
        system("pause");
        break;
        case 6:
        eliminarCancionDePlaylist();
        system("pause");
        break;
        case 7:
        reproducirPlaylist();
        system("pause");
        break;
        case 0:
        return;
        break;
        default:
            cout << "Opcion incorrecta \n";
            return;
        }

    }while(opcion != 0);

}

void MenuSuscriptor::verCancionesDePlaylist(){

    int idPlaylist;

    if(!verPlaylistsActuales()) return;

    cout << "Ingrese el id de la playlist que quiera ver(0 para volver): \n";
    cout << "Opcion: ";
    cin >> idPlaylist;


    if(idPlaylist == 0) return;

    cin.ignore();

    system("cls");

    _pm.mostrarCancionesDePlaylist(idPlaylist);

    cout << endl;

    system("pause");
}

void MenuSuscriptor::eliminarPlaylist(){

    int id;

    cout << "=======================================" << endl;
    cout << "#         ELIMINAR PLAYLIST            #" << endl;
    cout << "=======================================" << endl;

    verPlaylistsActuales();

    cout << "Ingrese el ID de la playlist a eliminar (0 para volver): ";
    cin >> id;

    if(id == 0) return;

    cin.ignore();



    _pm.eliminarPlaylist(id);

    system("pause");

}

void MenuSuscriptor::agregarCancionAPlaylist(){

    system("cls");

    cout << "=======================================" << endl;
    cout << "#      AGREGAR CANCION A PLAYLIST      #" << endl;
    cout << "=======================================" << endl;

    //Mostrar playlists del usuario
    if(!_pm.mostrarPlaylistDelSuscriptor(_sm.getSuscriptorActual().getId())) return;

    int idPlaylist;
    cout << "\nIngrese ID de playlist (0 para volver): ";
    cin >> idPlaylist;
    cin.ignore();

    if (idPlaylist == 0) return;


    system("cls");

    cout << "=======================================" << endl;
    cout << "#          CANCIONES DISPONIBLES       #" << endl;
    cout << "=======================================" << endl;

    _cm.mostrarTodasLasCanciones();

    int idCancion;
    cout << "\nIngrese ID de cancion (0 para volver): ";
    cin >> idCancion;

    if (idCancion == 0) return;

    cin.ignore();



    //Agregar canción a playlist
    if (_pm.agregarCancionAPlaylistPorIdPlaylistYIdCancion(idPlaylist, idCancion)) {
        cout << "\nCancion agregada correctamente!\n";
    } else {
        cout << "\nNo se pudo agregar la cancion.\n";
    }

    system("pause");
}

void MenuSuscriptor::eliminarCancionDePlaylist(){

    system("cls");

    cout << "=======================================" << endl;
    cout << "#      ELIMINAR CANCION DE PLAYLIST    #" << endl;
    cout << "=======================================" << endl;

    //Mostrar playlists del usuario
    if(!_pm.mostrarPlaylistDelSuscriptor(_sm.getSuscriptorActual().getId())) return;

    int idPlaylist;
    cout << "\nIngrese ID de playlist (0 para volver): ";
    cin >> idPlaylist;
    cin.ignore();

    if (idPlaylist == 0) return;

    system("cls");

    //Mostrar canciones de esa playlist
    _pm.mostrarCancionesDePlaylist(idPlaylist);

    int idCancion;
    cout << "\nID de cancion a eliminar (0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    if (idCancion == 0) return;

    //Llamar al manager para eliminar la relacion
    if (_pm.eliminarCancionDePlaylist(idPlaylist, idCancion)) {
        cout << "\nCancion eliminada correctamente!\n";
    } else {
        cout << "\nNo se pudo eliminar la cancion.\n";
    }

    system("pause");
}

void MenuSuscriptor::reproducirPlaylist()
{
    int id;

    if(!verPlaylistsActuales()) return;

    cout << endl;
    cout << "Elija la playlist a reproducir (ID).\n";
    cout << "0 para volver.\n";
    cout << "Opcion: ";
    cin >> id;

    if (id == 0) return;

    cin.ignore();
    system("cls");

    PlaylistArchivo repoPlaylist;
    Playlist pl;
    int posPl = repoPlaylist.buscarPorId(id);

    if (posPl == -1 || !repoPlaylist.leer(posPl, pl)) {
        cout << "No existe la playlist.\n";
        return;
    }

    if (pl.getIdSuscriptor() != _sm.getSuscriptorActual().getId()) {
        cout << "No podes reproducir una playlist que no es tuya.\n";
        return;
    }

    if (!pl.getEstado()) {
        cout << "La playlist esta deshabilitada.\n";
        return;
    }

    cout << "=======================================\n";
    cout << "  REPRODUCIENDO PLAYLIST: " << pl.getNombrePlaylist() << "\n";
    cout << "=======================================\n";

    PlaylistCancionArchivo repoPlaylistCancion;
    CancionArchivo repoCancion;

    int totalRel = repoPlaylistCancion.getCantidadRegistros();
    PlaylistCancion rel;
    bool hay = false;

    int idUser = _sm.getSuscriptorActual().getId();

    for (int i = 0; i < totalRel; i++) {

        if (!repoPlaylistCancion.leer(i, rel)) continue;
        if (!rel.getEstado()) continue;
        if (rel.getIdPlaylist() != id) continue;

        int posCanc = repoCancion.buscarId(rel.getIdCancion());
        if (posCanc == -1) continue;

        Cancion c;
        if (!repoCancion.leer(posCanc, c)) continue;
        if (!c.getEstado()) continue;

        hay = true;

        int incremento = _cm.reproducirCancion(c.getIdCancion(), idUser);

        for (int j = 0; j < incremento; j++) {
            _sm.sumarReproduccionAlSuscriptor();    // ← CORRECTO
        }
    }

    if (!hay) {
        cout << "\nNo hay canciones activas en esta playlist.\n";
        return;
    }

    pl.sumarReproduccion();
    repoPlaylist.modificar(posPl, pl);

    cout << "\nFin de reproduccion de playlist.\n";
    system("pause");
}

void MenuSuscriptor::eliminarPerfil(){

    int opcion;

    cout << "=======================================" << endl;
    cout << "#          ELIMINAR PERFIL            #" << endl;
    cout << "=======================================" << endl;

    cout << "¿Esta seguro que desesa eliminar su cuenta?" << endl;
    cout << "1.Si \n";
    cout << "2.No \n";

    cout << "Opcion: ";
    cin >> opcion;

    cout << endl;

    if(opcion == 1){
        if(_sm.eliminarCuenta(_sm.getSuscriptorActual())){
            cout << "Cuenta eliminada..." << endl;
            system("Pause");
            return;
        }
    }else if(opcion == 2){
        cout << "Decidio no eliminar la cuenta! \n";
        system("Pause");
        return;
    }

    cout << "Opcion incorrecta. \n";
    system("Pause");
    return;
}

void MenuSuscriptor::buscarCancionesPorGenero(){

    string genero;

    system("cls");

    cout << "==Buscar por genero==" << endl;

    cout << endl;

    cout << "Ingrese genero (0 para volver): ";
    getline(cin, genero);

    if(genero == "0") return;

    system("cls");

    cout << "==Canciones encontradas==" << endl << endl;

    if(!_cm.mostrarCancionesPorArtista(genero)){
        system("pause");
        return;
    }

    int idCancion;
    cout << endl;
    cout << "ID de cancion para acciones (o 0 para volver): ";
    cin >> idCancion;
    cin.ignore();

    accionesSobreCancion(idCancion);


}

