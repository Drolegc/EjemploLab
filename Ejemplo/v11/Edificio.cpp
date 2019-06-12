// Edificio.cpp

#include <stdexcept>

#include "Edificio.h"

Edificio::Edificio() : nom {"Edificio"}
{
    cantPisos = 1;
    gastosCom = 0.0;
}

Edificio::Edificio(string nombre, int cantidadPisos, double gastosComunes)
        : nom {nombre}
{
    if (cantidadPisos < 1 || gastosComunes < 0)
        throw std::invalid_argument("Valores invalidos");
    cantPisos = cantidadPisos;
    gastosCom = gastosComunes;
}

string Edificio::darNombre()
{
    return nom;
}

int Edificio::darCantidadPisos()
{
    return cantPisos;
}

double Edificio::darGastosComunes()
{
    return gastosCom;
}

void Edificio::modificarNombre(string nombre)
{
    nom = nombre;
}

void Edificio::modificarCantidadPisos(int cantidadPisos)
{
    cantPisos = cantidadPisos;
}

void Edificio::modificarGastosComunes(double gastosComunes)
{
    gastosCom = gastosComunes;
}

DtEdificio Edificio::darDtEdificio()
{
    DtEdificio res {nom, cantPisos, gastosCom};
    return res;    
}
