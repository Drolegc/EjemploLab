// ControladorUsuarios.h

#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include <string>
using std::string;

#include "Direccion.h"
#include "Usuario.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

class ControladorUsuarios {
public:
    static ControladorUsuarios* getInstance();

    ~ControladorUsuarios();

    ControladorUsuarios(const ControladorUsuarios&) = delete;
    ControladorUsuarios operator=(const ControladorUsuarios&) = delete;

    // Operaciones de sesion:

    bool ingresarEmail(string email);
    bool ingresarContrasenia(string contrasenia);
    void registrarContrasenia(string contrasenia);
    bool ingrVerifiContrasenia(string contrasenia);

    bool esPrimeraSesion(string email);

    void cerrarSesion();

    // Chequear quien esta logueado:

    bool sesionAdmin();
    bool sesionInm();
    bool sesionInt();

    // Operaciones de creacion de usuarios:

    void crearAdministrador(string email, string contrasenia);
    void altaInteresado(string nombre, string apellido, int edad,
                                                        string email);
    void altaInmobiliaria(string nombre, Direccion direccion, string email);
    void aceptarAltaInmob();
    void cancelar();

    // Obtener Reporte de Inmobiliarias:
    ICollection* obtenerReporteInmobiliarias();

    // Operaciones de manejo de la coleccion:

    bool existeUsuario(string email);

private:
    ControladorUsuarios();

    void agregarUsuario(Usuario* u);
    void removerUsuario(Usuario* u);
    void asignarSesion(Usuario* u);
    void verificarUnicidadEmail(string email);
    void chequearNombreInmob(string nombre);
    void liberarMemoria();

    static ControladorUsuarios* instance;
    IDictionary* usuarios;
    string emailGuardado;
    string contraseniaGuardada;
    string nombreGuardado;
    Direccion direccionGuardada;
};

#endif
