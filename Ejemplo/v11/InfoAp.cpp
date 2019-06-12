// InfoAp.cpp

#include "InfoAp.h"

InfoAp::InfoAp(int codigoProp, int cantidadAmbientes, int cantidadDormitorios,
        int cantidadBanios, bool propTieneGaraje, Direccion direccion,
        double m2EdificadosProp, double precioVenta, double precioAlquiler,
        string emailInmob, int codigoZona, string nombreEdificio)
        : InfoPropiedad(codigoProp, cantidadAmbientes, cantidadDormitorios,
        cantidadBanios, propTieneGaraje, direccion, m2EdificadosProp,
        precioVenta, precioAlquiler, emailInmob, codigoZona),
        nomEdif {nombreEdificio}
{
}

double InfoAp::darM2Totales()
{
    return (darM2Edif());
}
