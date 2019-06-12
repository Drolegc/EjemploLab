// DtDepartamento.cpp

#include "DtDepartamento.h"

DtDepartamento::DtDepartamento(string matricula, string nombre)
        : mat {matricula}, nom {nombre}
{
}

string DtDepartamento::darMatricula()
{
    return mat;
}

string DtDepartamento::darNombre()
{
    return nom;
}
