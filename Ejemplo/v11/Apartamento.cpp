// Apartamento.cpp

#include "Apartamento.h"
#include "ColeccionEdificios.h"
#include "InfoPropiedad.h"
#include "InfoAp.h"


Apartamento::Apartamento(Zona* z, int codigoProp, int cantidadAmbientes,
        int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
        Direccion dir, double m2EdificadosProp, string nombreEdificio)
        : Propiedad(z, codigoProp, cantidadAmbientes, cantidadDormitorios,
        cantidadBanios, propTieneGaraje, dir, m2EdificadosProp)
{
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();
    Edificio* e = ce->darEdificio(nombreEdificio);
    edificio = e;
}



ICollectible* Apartamento::darInfoPropiedad()
{
    double valor {-1};
    double precioAlq {-1};
    if (darVenta() != nullptr)
        valor = (darVenta())->darValor();
    if (darAlquiler() != nullptr)
        precioAlq = (darAlquiler())->darPrecioAlquiler();
    InfoPropiedad* infoP = new InfoAp {darCodigo(), darCantAmbientes(),
            darCantDormitorios(), darCantBanios(), propTieneGaraje(),
            darDireccion(), darM2Edificados(), valor,
            precioAlq, (darInmobiliaria())->darEmail(),
            (darZona())->darCodigo(), edificio->darNombre()};
    return infoP;
}


