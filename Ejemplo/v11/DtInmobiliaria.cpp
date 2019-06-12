// DtInmobiliaria.cpp

#include "DtInmobiliaria.h"


DtInmobiliaria::DtInmobiliaria(string email, string nombre,
        Direccion ubicacion) : mail {email}, nom {nombre}, dir {ubicacion}
{
}

string DtInmobiliaria::darEmail()
{
    return mail;
}

string DtInmobiliaria::darNombre()
{
    return nom;
}

Direccion DtInmobiliaria::darUbicacion()
{
    return dir;
}
