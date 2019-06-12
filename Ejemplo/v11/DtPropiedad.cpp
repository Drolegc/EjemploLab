// DtPropiedad.cpp

#include "DtPropiedad.h"

DtPropiedad::DtPropiedad()
{
    cod = 0;
    cantMsjs = 0;
}

DtPropiedad::DtPropiedad(int codigo, Direccion direccion,
        int cantMensajesEnviados) : dir {direccion}
{
    cod = codigo;
    cantMsjs = cantMensajesEnviados;
}

int DtPropiedad::darCodigo()
{
    return cod;
}

Direccion DtPropiedad::darDireccion()
{
    return dir;
}

int DtPropiedad::darCantMensajes()
{
    return cantMsjs;
}
