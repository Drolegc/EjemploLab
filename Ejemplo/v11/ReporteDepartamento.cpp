

#include "ReporteDepartamento.h"

ReporteDepartamento::ReporteDepartamento(char letraIdentificadorap, TipoPropiedad tp) {
    this->letraIdentificadora=letraIdentificadorap;
    if (tp == TipoPropiedad::casa){
        this->cantCasas = 1;
        this->cantApartamentos = 0;
    } else if (tp == TipoPropiedad::apartamento){
        this->cantApartamentos = 1;
        this->cantCasas = 0;
    }
}    

ReporteDepartamento::ReporteDepartamento(const ReporteDepartamento& orig) {
}

ReporteDepartamento::~ReporteDepartamento() {
}

char ReporteDepartamento::getLetraIdentificadora(){
    return this->letraIdentificadora;
}

int ReporteDepartamento::getCantCasas(){
    return this->cantCasas;
}

int ReporteDepartamento::getCantApartamentos(){
    return this->cantApartamentos;
}

void ReporteDepartamento::setCantApartamentos(int cantApartamentosp){
    this->cantApartamentos=cantApartamentosp;
}

void ReporteDepartamento::setCantCasas(int cantCasasp){
    this->cantCasas=cantCasasp;
}

void ReporteDepartamento::sumarUno(TipoPropiedad tp)
{
    if (tp == TipoPropiedad::casa)
        ++cantCasas;
    else if (tp == TipoPropiedad::apartamento)
        ++cantApartamentos;
}

void ReporteDepartamento::restarUno(TipoPropiedad tp)
{
    if (tp == TipoPropiedad::casa)
        --cantCasas;
    else if (tp == TipoPropiedad::apartamento)
        --cantApartamentos;
}

ICollectible* ReporteDepartamento::darData()
{
    DtReporteDep* res = new DtReporteDep {letraIdentificadora, cantCasas,
                                          cantApartamentos};
    return res;
}
