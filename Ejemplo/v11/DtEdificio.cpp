// DtEdificio.cpp

#include "DtEdificio.h"

DtEdificio::DtEdificio()
{
    cantPisos = 1;
    gastosCom = 0;    
}

DtEdificio::DtEdificio(string nombre, int cantidadPisos, double gastosComunes)
        : nom {nombre}
{
    cantPisos = cantidadPisos;
    gastosCom = gastosComunes;
}

string DtEdificio::darNombre()
{
    return nom;
}

int DtEdificio::darCantidadPisos()
{
    return cantPisos;
}

double DtEdificio::darGastosComunes()
{
    return gastosCom;
}
