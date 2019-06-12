// Sesion.h

#ifndef SESION_H
#define SESION_H

#include <string>
using std::string;

#include "Usuario.h"

class Sesion {
public:
    static Sesion* getInstance();
    Sesion(const Sesion&) = delete;
    Sesion& operator=(const Sesion&) = delete;
    ~Sesion();

    void asignarSesion(Usuario* u);
    Usuario* darUsuario();
    string darEmailUsuario();
    bool haySesionActiva();

    void desvincularUsuario();
 
private:
    Sesion();
    static Sesion* instance;
    Usuario* usuario;
};

#endif
