// DtReporteZ.h

#ifndef DTREPORTEZ_H
#define DTREPORTEZ_H

#include "interfaces/ICollectible.h"

struct DtReporteZ : public ICollectible {
public:
    DtReporteZ(int codigoZona, int cantC, int cantA);
    ~DtReporteZ() {}

    int darCodigoZ() { return codigoZ; }
    int darCantCasas() { return cantCasas; }
    int darCantApartamentos() { return cantApartamentos; }

private:
    int codigoZ;
    int cantCasas;
    int cantApartamentos;
};

#endif
