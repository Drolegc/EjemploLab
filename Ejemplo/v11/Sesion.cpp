// Sesion.cpp

#include "Sesion.h"

Sesion* Sesion::instance {nullptr};

Sesion::Sesion()
{
    usuario = nullptr;
}

// Sesion no es la encargada de eliminar usuario
Sesion::~Sesion()
{
    instance = nullptr;
}

Sesion* Sesion::getInstance()
{
    if (instance == nullptr)
        instance = new Sesion();
    return instance;
}

void Sesion::asignarSesion(Usuario* u)
{
    usuario = u;
}

string Sesion::darEmailUsuario()
{
    string res;
    if (usuario != nullptr)
        res = usuario->darEmail();
    return res;
}

Usuario* Sesion::darUsuario()
{
    return usuario;
}

bool Sesion::haySesionActiva()
{
    return (usuario != nullptr);
}

void Sesion::desvincularUsuario()
{
    usuario = nullptr;
}
