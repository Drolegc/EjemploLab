// FechaYHora.h

#ifndef FECHAYHORA_H
#define FECHAYHORA_H

#include "interfaces/OrderedKey.h"

struct FechaYHora : public OrderedKey {
public:
    FechaYHora();
    explicit FechaYHora(int dia, int mes, int anio, int hora, int minuto);
    ~FechaYHora() {}

    int darDia();
    int darMes();
    int darAnio();
    int darHora();
    int darMinuto();

    ComparisonRes compare(OrderedKey* k) const;

private:
    int dd;
    int mm;
    int aa;
    int h;
    int m;
};

#endif
