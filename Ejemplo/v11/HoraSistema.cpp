// HoraSistema.cpp

#include "HoraSistema.h"

HoraSistema* HoraSistema::instance {nullptr};

HoraSistema* HoraSistema::getInstance()
{
    if (instance == nullptr)
        instance = new HoraSistema();
    return instance;
}

void HoraSistema::setearFechaYHora(FechaYHora horaSist)
{
    fyh = horaSist;
}

FechaYHora HoraSistema::darFechaYHora()
{
    return fyh;
}
