// InfoPropiedad.cpp

#include "InfoPropiedad.h"

InfoPropiedad::InfoPropiedad(int codigoProp, int cantidadAmbientes,
    int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
    Direccion direccion, double m2EdificadosProp, double precioVenta,
    double precioAlquiler, string emailInmob, int codigoZona)
    : dir {direccion}, emailInm {emailInmob}
{
    codProp = codigoProp;
    cantAmbs = cantidadAmbientes;
    cantDorms = cantidadDormitorios;
    cantBanios = cantidadBanios;
    hayGaraje = propTieneGaraje;
    m2Edif = m2EdificadosProp;
    precioV = precioVenta;
    precioA = precioAlquiler;
    codZ = codigoZona;
}
