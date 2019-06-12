// Direccion.cpp

#include "Direccion.h"

Direccion::Direccion(string calle, string numero) : c {calle}, n {numero}
{
}

string Direccion::darCalle()
{
    return c;
}

string Direccion::darNumero()
{
    return n;
}
