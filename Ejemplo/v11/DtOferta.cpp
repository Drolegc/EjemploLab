// DtOferta.cpp

#include "DtOferta.h"

DtOferta::DtOferta(TipoPropiedad tipoProp, TipoOferta oferta,
        int codigoPropiedad, double precioProp, int cantAmbientes,
        int cantDormitorios, int cantBanios, bool tieneGaraje,
        Direccion direc, double m2Edificados, double m2EspacioVerde,
        string nombreEdificio, int codigoZona, char letraIdDep)
        : tipoP {tipoProp}, tipoOf {oferta}, dir {direc},
        nombreEdif {nombreEdificio}
{
    codigoProp = codigoPropiedad;
    precio = precioProp;
    cantAmb = cantAmbientes;
    cantDorm = cantDormitorios;
    cantBan = cantBanios;
    hayGaraje = tieneGaraje;
    m2Edif = m2Edificados;
    m2EspVerde = m2EspacioVerde;
    codigoZ = codigoZona;
    letraDep = letraIdDep;
}
