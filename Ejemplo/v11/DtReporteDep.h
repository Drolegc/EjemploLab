// DtReporteDep.h

#ifndef DTREPORTEDEP_H
#define DTREPORTEDEP_H

#include "interfaces/ICollectible.h"

struct DtReporteDep : public ICollectible {
public:
    DtReporteDep(char letraId, int cantC, int cantA);
    ~DtReporteDep() {}

    char darLetraIdentificadora() { return letraIdentificadora; }
    int darCantCasas() { return cantCasas; }
    int darCantApartamentos() { return cantApartamentos; }

private:
    char letraIdentificadora;
    int cantCasas;
    int cantApartamentos;
};

#endif
