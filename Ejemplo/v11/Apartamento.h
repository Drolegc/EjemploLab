// Apartamento.h

#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <string>
#include "Edificio.h"
#include "Propiedad.h"
#include "TipoPropiedad.h"
#include "interfaces/ICollectible.h"

class Apartamento : public Propiedad {
public:
    explicit Apartamento(Zona* z, int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion dir, double m2EdificadosProp, string nombreEdificio);
    Apartamento(const Apartamento&) = delete;
    Apartamento& operator=(const Apartamento&) = delete;
    ~Apartamento() {}

    double darM2Totales() { return darM2Edificados(); }

    TipoPropiedad darTipoProp() { return TipoPropiedad::apartamento; }

    ICollectible* darInfoPropiedad();

private:
    Edificio* edificio;
};

#endif
