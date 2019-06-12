// Usuario.cpp

#include "Usuario.h"

Usuario::Usuario(string email)
        : e {email}
{
}

Usuario::Usuario(string email, string contrasenia) : e {email},
                                                     contra {contrasenia}
{
}

bool Usuario::confDeContra(string contrasenia)
{
    return (contra == contrasenia);
}

void Usuario::modificarContrasenia(string contrasenia)
{
    contra = contrasenia;
}

string Usuario::darEmail()
{
    return e;
}

string Usuario::darContrasenia()
{
    return contra;
}
