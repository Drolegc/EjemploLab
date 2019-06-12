// Venta.cpp

#include <stdexcept>
#include "Venta.h"

Venta::Venta(double valor) {
    if (valor < 0)
        throw std::invalid_argument("Valor no valido");
    val = valor;
}
