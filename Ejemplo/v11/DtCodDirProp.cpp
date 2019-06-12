// DtCodDirProp.cpp

#include "DtCodDirProp.h"

DtCodDirProp::DtCodDirProp(int codigo, Direccion direccion, bool enAlquiler,
        bool enVenta) : dir {direccion}
{
    cod = codigo;
    seAlquila = enAlquiler;
    seVende = enVenta;
}

int DtCodDirProp::darCodigo()
{
    return cod;
}

Direccion DtCodDirProp::darDireccion()
{
    return dir;
}

bool DtCodDirProp::estaEnAlquiler()
{
    return seAlquila;
}

bool DtCodDirProp::estaEnVenta()
{
    return seVende;
}
