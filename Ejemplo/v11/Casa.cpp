// Casa.cpp

#include "Casa.h"
#include "InfoPropiedad.h"
#include "InfoC.h"

Casa::Casa(Zona* z, int codigoProp, int cantidadAmbientes,
        int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
        Direccion dir, double m2EdificadosProp, double m2EspacioVerde)
        : Propiedad(z, codigoProp, cantidadAmbientes, cantidadDormitorios,
        cantidadBanios, propTieneGaraje, dir, m2EdificadosProp)
{
    m2EspVerde = m2EspacioVerde;
}



double Casa::darM2Totales()
{
    return (darM2Edificados() + m2EspVerde);
}



ICollectible* Casa::darInfoPropiedad()
{
    double valor {-1};
    double precioAlq {-1};
    if (darVenta() != nullptr)
        valor = (darVenta())->darValor();
    if (darAlquiler() != nullptr)
        precioAlq = (darAlquiler())->darPrecioAlquiler();
    InfoPropiedad* infoP = new InfoC {darCodigo(), darCantAmbientes(),
            darCantDormitorios(), darCantBanios(), propTieneGaraje(),
            darDireccion(), darM2Edificados(), valor,
            precioAlq, (darInmobiliaria())->darEmail(),
            (darZona())->darCodigo(), m2EspVerde};
    return infoP;
}
