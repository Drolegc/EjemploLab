// Inmobiliaria.cpp

#include "Inmobiliaria.h"
#include "IntKey.h"
#include "LetraIdentificadora.h"
#include "ReporteDepartamento.h"
#include "ReporteZona.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

Inmobiliaria::Inmobiliaria()
{
    conversaciones = new List();
    props = new OrderedDictionary();
    reportesDep = new OrderedDictionary();
    reportesZ = new OrderedDictionary();
}

Inmobiliaria::Inmobiliaria(string email, string nombre,
        Direccion ubicacion) : Usuario(email), nom {nombre},
        dir {ubicacion}
{
    conversaciones = new List();
    props = new OrderedDictionary();
    reportesDep = new OrderedDictionary();
    reportesZ = new OrderedDictionary();
}

Inmobiliaria::~Inmobiliaria()
{
    delete conversaciones;
    delete props;

    IIterator* it = reportesDep->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    delete reportesDep;

    IIterator* it2 = reportesZ->getIterator();
    while (it2->hasCurrent()) {
        ICollectible* temp = it2->getCurrent();
        it2->next();
        delete temp;
    }
    delete it2;
    delete reportesZ;
}

void Inmobiliaria::agregarConversa(Conversa* c)
{
    conversaciones->add(c);
}



void Inmobiliaria::agregarPropiedad(Propiedad* p, char letraDep)
{
    IntKey* clave = new IntKey {p->darCodigo()};
    props->add(clave, p);

    TipoPropiedad tipoProp;
    Apartamento* ptrAp = dynamic_cast<Apartamento*>(p);
    if (ptrAp != nullptr)
        tipoProp = TipoPropiedad::apartamento;
    else
        tipoProp = TipoPropiedad::casa;

    int codigoZ {p->darCodigoZona()};
    LetraIdentificadora* claveRepD = new LetraIdentificadora {letraDep};
    IntKey* claveReporteZ = new IntKey {codigoZ};

    if (reportesZ->member(claveReporteZ)) {
        ReporteZona* repZ = 
            dynamic_cast<ReporteZona*>(reportesZ->find(claveReporteZ));
        repZ->sumarUno(tipoProp);
        delete claveReporteZ;
    }
    else {
        ReporteZona* reporteZ =
                new ReporteZona {p->darCodigoZona(), tipoProp};
        reportesZ->add(claveReporteZ, reporteZ);
    }

    if (reportesDep->member(claveRepD)) {
        ReporteDepartamento* repD =
            dynamic_cast<ReporteDepartamento*>(reportesDep->find(claveRepD));
        repD->sumarUno(tipoProp);
        delete claveRepD;
    }
    else {
        ReporteDepartamento* reporteDep =
                new ReporteDepartamento {letraDep, tipoProp};
        reportesDep->add(claveRepD, reporteDep);
    }
}



void Inmobiliaria::modificarNombre(string nombre)
{
    nom = nombre;
}

void Inmobiliaria::modificarUbicacion(Direccion ubicacion)
{
    dir = ubicacion;
}

string Inmobiliaria::darNombre()
{
    return nom;
}

Direccion Inmobiliaria::darUbicacion()
{
    return dir;
}

DtInmobiliaria Inmobiliaria::darDtInmobiliaria()
{
    DtInmobiliaria res {darEmail(), nom, dir};
    return res;
}

ICollection* Inmobiliaria::reportarPorDepartamento()
{
    ICollection* res = new List();
    IIterator* it = reportesDep->getIterator();
    while (it->hasCurrent()) {
        ReporteDepartamento* rep =
                dynamic_cast<ReporteDepartamento*>(it->getCurrent());
        ICollectible* dtRep = rep->darData();
        res->add(dtRep);
        it->next();
    }
    delete it;
    return res;
}

ICollection* Inmobiliaria::reportarPorZona()
{
    ICollection* res = new List();
    IIterator* it = reportesZ->getIterator();
    while (it->hasCurrent()) {
        ReporteZona* rep =
                dynamic_cast<ReporteZona*>(it->getCurrent());
        ICollectible* dtRep = rep->darData();
        res->add(dtRep);
        it->next();
    }
    delete it;
    return res;
}



ICollectible* Inmobiliaria::darReporteCompleto()
{
    DtInmobiliaria dtInm {darDtInmobiliaria()};
    ICollection* porDep = reportarPorDepartamento();
    ICollection* porZ = reportarPorZona();
    DtReporteInm* resultado = new DtReporteInm {dtInm, porDep, porZ};
    return resultado;
}


/* Precondicion: Existen reportes cuyas claves se corresponden
con letraDep y codZona */
void Inmobiliaria::restarDeReporte(char letraDep, int codZona,
                                   TipoPropiedad tipoProp)
{
    LetraIdentificadora* claveRepD =
            new LetraIdentificadora {letraDep};
    IntKey* claveRepZ = new IntKey {codZona};
    ReporteDepartamento* repD =
            dynamic_cast<ReporteDepartamento*>(reportesDep->find(claveRepD));
    ReporteZona* repZ =
            dynamic_cast<ReporteZona*>(reportesZ->find(claveRepZ));
    delete claveRepD;
    delete claveRepZ;
    repD->restarUno(tipoProp);
    repZ->restarUno(tipoProp);
}
