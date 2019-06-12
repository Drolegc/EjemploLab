// InfoC.cpp

#include "InfoC.h"

InfoC::InfoC(int codigoProp, int cantidadAmbientes, int cantidadDormitorios,
        int cantidadBanios, bool propTieneGaraje, Direccion direccion,
        double m2EdificadosProp, double precioVenta, double precioAlquiler,
        string emailInmob, int codigoZona, double m2EspacioVerde)
        : InfoPropiedad(codigoProp, cantidadAmbientes, cantidadDormitorios,
        cantidadBanios, propTieneGaraje, direccion, m2EdificadosProp,
        precioVenta, precioAlquiler, emailInmob, codigoZona)
{
    m2EspVerde = m2EspacioVerde;
}

double InfoC::darM2Totales()
{
    return (darM2Edif() + m2EspVerde);
}
