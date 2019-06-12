// InfoPropiedad.h

#ifndef INFOPROPIEDAD_H
#define INFOPROPIEDAD_H

#include "Direccion.h"
#include "interfaces/ICollectible.h"
#include <string>
using std::string;

struct InfoPropiedad : public ICollectible {
public:
    explicit InfoPropiedad(int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion direccion, double m2EdificadosProp, double precioVenta,
            double precioAlquiler, string emailInmob, int codigoZona);
    virtual ~InfoPropiedad() {}

    int darCodigo() { return codProp; }
    int darCantAmb() { return cantAmbs; }
    int darCantDorm() { return cantDorms; }
    int darCantBanios() { return cantBanios; }
    bool darHayGaraje() { return hayGaraje; }
    Direccion darDir() { return dir; }
    double darM2Edif() { return m2Edif; }
    /* precio negativo significa que semejante oferta no existe
    (por ejemplo, si darPrecioV retorna un valor negativo,
    entonces la propiedad no esta en venta) */
    double darPrecioV() { return precioV; }
    double darPrecioA() { return precioA; }
    string darEmailInm() { return emailInm; }
    int darCodZ() { return codZ; }

    virtual double darM2Totales() = 0;

private:
    int codProp;
    int cantAmbs;
    int cantDorms;
    int cantBanios;
    bool hayGaraje;
    Direccion dir;
    double m2Edif;
    double precioV;
    double precioA;
    string emailInm;
    int codZ;
};

#endif
