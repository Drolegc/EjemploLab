

#include "ReporteZona.h"

ReporteZona::ReporteZona(int codigoZ, TipoPropiedad tp) {
    this->codigo=codigoZ;
    if (tp == TipoPropiedad::casa){
        this->cantCasas = 1;
        this->cantApartamentos = 0;
    } else if (tp == TipoPropiedad::apartamento){
        this->cantApartamentos = 1;
        this->cantCasas = 0;
    }
}



ReporteZona::~ReporteZona() {
}

int ReporteZona::getCodigo(){
    return this->codigo;
}

int ReporteZona::getCantCasas(){
    return this->cantCasas;
}

int ReporteZona::getCantApartamentos(){
    return this->cantApartamentos;
}

void ReporteZona::setCodigo(int codigop){
    this->codigo=codigop;
}

void ReporteZona::setCantApartamentos(int cantApartamentosp){
    this->cantApartamentos=cantApartamentosp;
}

void ReporteZona::setCantCasas(int cantCasasp){
    this->cantCasas=cantCasasp;
}

void ReporteZona::sumarUno(TipoPropiedad tp)
{
    if (tp == TipoPropiedad::casa)
        ++cantCasas;
    else if (tp == TipoPropiedad::apartamento)
        ++cantApartamentos;
}

void ReporteZona::restarUno(TipoPropiedad tp)
{
    if (tp == TipoPropiedad::casa)
        --cantCasas;
    else if (tp == TipoPropiedad::apartamento)
        --cantApartamentos;
}

ICollectible* ReporteZona::darData()
{
    DtReporteZ* res = new DtReporteZ {codigo, cantCasas, cantApartamentos};
    return res;
}
