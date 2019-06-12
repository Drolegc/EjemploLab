// DtOferta.h

#ifndef DTOFERTA_H
#define DTOFERTA_H

#include "Direccion.h"
#include "TipoPropiedad.h"
#include "TipoOferta.h"
#include <string>
using std::string;

struct DtOferta {
public:
    explicit DtOferta(TipoPropiedad tipoProp, TipoOferta oferta,
        int codigoPropiedad, double precioProp, int cantAmbientes,
        int cantDormitorios, int cantBanios, bool tieneGaraje,
        Direccion direc, double m2Edificados, double m2EspacioVerde,
        string nombreEdificio, int codigoZona, char letraIdDep);
    ~DtOferta() {}

    TipoPropiedad darTipoP() { return tipoP; }
    TipoOferta darTipoOf() { return tipoOf; }
    int darCodigoP() { return codigoProp; }
    double darPrecio() { return precio; }
    int darCantAmbientes() { return cantAmb; }
    int darCantDormitorios() { return cantDorm; }
    int darCantBanios() { return cantBan; }
    bool darHayGaraje() { return hayGaraje; }
    Direccion darDireccion() { return dir; }
    double darM2Edif() { return m2Edif; }
    double darM2EspVerde() { return m2EspVerde; }
    string darNombreEdif() { return nombreEdif; }
    int darCodigoZ() { return codigoZ; }
    char darLetraDep() { return letraDep; }

private:
    TipoPropiedad tipoP;
    TipoOferta tipoOf;
    int codigoProp;
    double precio;
    int cantAmb;
    int cantDorm;
    int cantBan;
    bool hayGaraje;
    Direccion dir;
    double m2Edif;
    double m2EspVerde;
    string nombreEdif;
    int codigoZ;
    char letraDep;
};

#endif
