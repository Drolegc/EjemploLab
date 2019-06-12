// FechaYHora.cpp

#include <stdexcept>
#include "FechaYHora.h"

FechaYHora::FechaYHora()
{
    dd = 1;
    mm = 1;
    aa = 1;
    h = 0;
    m = 0;
}

FechaYHora::FechaYHora(int dia, int mes, int anio, int hora, int minuto)
{
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1)
        throw std::invalid_argument("Fecha invalida");
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
        throw std::invalid_argument("Hora no valida");
    dd = dia;
    mm = mes;
    aa = anio;
    h = hora;
    m = minuto;
}

int FechaYHora::darDia()
{
    return dd;
}

int FechaYHora::darMes()
{
    return mm;
}

int FechaYHora::darAnio()
{
    return aa;
}

int FechaYHora::darHora()
{
    return h;
}

int FechaYHora::darMinuto()
{
    return m;
}

ComparisonRes FechaYHora::compare(OrderedKey* k) const
{
    FechaYHora* fyh = dynamic_cast<FechaYHora*>(k);
    if (fyh == nullptr)
        throw std::invalid_argument("Invalid key k");

    if ((aa == fyh->aa) && (mm == fyh->mm) && (dd == fyh->dd)
                && (h == fyh->h) && (m == fyh->m))
        return EQUAL;
    else if ((aa > fyh->aa) || ((aa == fyh->aa) && (mm > fyh->mm))
                || ((aa == fyh->aa) && (mm == fyh->mm) && (dd > fyh->dd))
                || ((aa == fyh->aa) && (mm == fyh->mm) && (dd == fyh->dd)
                   && (h > fyh->h))
                || ((aa == fyh->aa) && (mm == fyh->mm) && (dd == fyh->dd)
                   && (h == fyh->h) && (m > fyh->m)))
        return GREATER;
    else
        return LESSER;
}
