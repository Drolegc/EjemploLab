// HoraSistema.h

#ifndef HORASISTEMA_H 
#define HORASISTEMA_H 

#include "FechaYHora.h"

class HoraSistema {
public:
    static HoraSistema* getInstance();
    HoraSistema(const HoraSistema&) = delete;
    HoraSistema& operator=(const HoraSistema&) = delete;
    ~HoraSistema() {}

    void setearFechaYHora(FechaYHora horaSist);
    FechaYHora darFechaYHora();

private:
    HoraSistema() {}
    static HoraSistema* instance;
    FechaYHora fyh;
};

#endif
