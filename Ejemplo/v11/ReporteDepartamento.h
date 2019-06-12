#ifndef REPORTEDEPARTAMENTO_H
#define REPORTEDEPARTAMENTO_H

#include "TipoPropiedad.h"
#include "DtReporteDep.h"
#include "interfaces/ICollectible.h"

class ReporteDepartamento : public ICollectible {
public:
    ReporteDepartamento(char letraIdentificadorap, TipoPropiedad tp);
    ReporteDepartamento(const ReporteDepartamento& orig);
    virtual ~ReporteDepartamento();
    char getLetraIdentificadora();
    int getCantCasas();
    int getCantApartamentos();
    void setCantCasas(int cantCasasp);
    void setCantApartamentos(int cantApartamentosp);
    void sumarUno(TipoPropiedad tp);
    void restarUno(TipoPropiedad tp);
    ICollectible* darData();

private:
    char letraIdentificadora;
    int cantCasas;
    int cantApartamentos;
};

#endif /* REPORTEDEPARTAMENTO_H */

