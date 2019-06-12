// Alquiler.cpp

#include <stdexcept>
#include "Alquiler.h"

Alquiler::Alquiler(double precioAlquiler)
{
    if (precioAlquiler < 0)
        throw std::invalid_argument("Precio no valido");
    precio = precioAlquiler;
}
