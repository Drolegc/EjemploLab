// InfoC.h

#ifndef INFOC_H
#define INFOC_H

#include "InfoPropiedad.h"
#include <string>
using std::string;

struct InfoC : public InfoPropiedad {
public:
    explicit InfoC(int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion direccion, double m2EdificadosProp, double precioVenta,
            double precioAlquiler, string emailInmob, int codigoZona,
            double m2EspacioVerde);
    ~InfoC() {}

    double darM2EspacioVerde() { return m2EspVerde; }
    double darM2Totales();

private:
    double m2EspVerde;
};

#endif
