// Casa.h

#ifndef CASA_H
#define CASA_H

#include <string>
#include "Propiedad.h"
#include "TipoPropiedad.h"
#include "interfaces/ICollectible.h"

class Casa : public Propiedad {
public:
    explicit Casa(Zona* z, int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion dir, double m2EdificadosProp, double m2EspacioVerde);
    Casa(const Casa&) = delete;
    Casa& operator=(const Casa&) = delete;
    ~Casa() {}


    double darM2EspacioVerde() { return m2EspVerde; }
    double darM2Totales();

    TipoPropiedad darTipoProp() { return TipoPropiedad::casa; }

    ICollectible* darInfoPropiedad();

private:
    double m2EspVerde;
};

#endif
