// InfoAp.h

#ifndef INFOAP_H
#define INFOAP_H

#include "InfoPropiedad.h"
#include <string>
using std::string;

struct InfoAp : public InfoPropiedad {
public:
    explicit InfoAp(int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion direccion, double m2EdificadosProp, double precioVenta,
            double precioAlquiler, string emailInmob, int codigoZona,
            string nombreEdificio);
    ~InfoAp() {}

    string darNombreEdificio() { return nomEdif; }
    double darM2Totales();

private:
    string nomEdif;
};

#endif
