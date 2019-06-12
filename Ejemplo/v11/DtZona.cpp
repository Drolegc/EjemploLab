// DtZona.cpp

#include "DtZona.h"

DtZona::DtZona(int codigo, string nombre) : nom {nombre}
{
    cod = codigo;
}

int DtZona::darCodigo()
{
    return cod;
}

string DtZona::darNombre()
{
    return nom;
}
