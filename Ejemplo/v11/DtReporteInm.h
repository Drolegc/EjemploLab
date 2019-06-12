// DtReporteInm.h

#ifndef DTREPORTEINM_H
#define DTREPORTEINM_H

#include "DtInmobiliaria.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"

struct DtReporteInm : public ICollectible {
public:
    explicit DtReporteInm(DtInmobiliaria dtInm, ICollection* repD,
            ICollection* repZ);
    void eliminarColeccion(ICollection* coleccion);
    ~DtReporteInm();

    DtInmobiliaria darDtInm() { return dtInmob; }
    ICollection* darRepDeps() { return reporteDeps; }
    ICollection* darRepZonas() { return reporteZonas; }
    
private:
    DtInmobiliaria dtInmob;
    ICollection* reporteDeps;
    ICollection* reporteZonas;
};

#endif
