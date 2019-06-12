

#ifndef REPORTEZONA_H
#define REPORTEZONA_H

#include "TipoPropiedad.h"
#include "DtReporteZ.h"
#include "interfaces/ICollectible.h"

class ReporteZona : public ICollectible {
public:
    ReporteZona(int codigop, TipoPropiedad tp);
    
    virtual ~ReporteZona();
    int getCodigo();
    int getCantCasas();
    int getCantApartamentos();
    void setCodigo(int codigop);
    void setCantCasas(int cantCasasp);
    void setCantApartamentos(int cantApartamentosp);
    void sumarUno(TipoPropiedad tp);
    void restarUno(TipoPropiedad tp);
    ICollectible* darData();
private:
    int codigo;
    int cantCasas;
    int cantApartamentos;
};

#endif /* REPORTEZONA_H */
