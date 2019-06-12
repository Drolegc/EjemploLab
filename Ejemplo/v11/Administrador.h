// Administrador.h

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
using std::string;

#include "Usuario.h"

class Administrador : public Usuario {
public:
    Administrador() {}
    explicit Administrador(string email, string contrasenia);
    Administrador(const Administrador&) = delete;
    Administrador& operator=(const Administrador&) = delete;
    ~Administrador() {}

};

#endif
