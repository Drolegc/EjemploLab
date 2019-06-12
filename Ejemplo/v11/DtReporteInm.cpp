// DtReporteInm.cpp

#include "DtReporteInm.h"

// Las colecciones ingresadas como parametros comparten memoria con
// las de DtReporteInm. Quien las crea es responsable de eliminarlas 
DtReporteInm::DtReporteInm(DtInmobiliaria dtInm, ICollection* repD,
                           ICollection* repZ) : dtInmob {dtInm}
{
    reporteDeps = repD;
    reporteZonas = repZ;
}



DtReporteInm::~DtReporteInm()
{
}
