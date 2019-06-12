// Departamento.cpp

#include <stdexcept>
#include "Departamento.h"
#include "DtZona.h"
#include "interfaces/IIterator.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"


Departamento::Departamento(string matricula, string nombre)
        : mat(matricula), nom(nombre)
{
    zonasDep = new OrderedDictionary();
}

Departamento::~Departamento()
{
    IIterator* it = zonasDep->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    delete zonasDep;
}

string Departamento::darMatricula()
{
    return mat;
}

string Departamento::darNombre()
{
    return nom;
}

DtDepartamento* Departamento::darDtDepartamento()
{
    DtDepartamento* res = new DtDepartamento(mat, nom);
    return res;
}



int Departamento::altaOferta(DtOferta dtOf)
{
    int res {0};
    IntKey* ik = new IntKey {dtOf.darCodigoZ()};
    if (zonasDep->member(ik)) {
        Zona* z = dynamic_cast<Zona*>(zonasDep->find(ik));
        res = z->altaOferta(dtOf);
    }
    else {
        delete ik;
        throw std::invalid_argument("No existe una zona con ese codigo");
    }
    delete ik;
    return res;
}



ICollection* Departamento::zonas()
{
    List* res = new List();
    IIterator* it = zonasDep->getIterator();
    while (it->hasCurrent()) {
        Zona* z = dynamic_cast<Zona*>(it->getCurrent());
        DtZona* dtZ = dynamic_cast<DtZona*>(z->darDtZona());
        res->add(dtZ);
        it->next();
    }
    delete it;
    return res;
}

void Departamento::crearZona(int codigo, string nombre)
{
    Zona* z = new Zona {codigo, nombre};
    IntKey* ik = new IntKey {codigo};
    zonasDep->add(ik, z);
}

bool Departamento::existeZona(int codigo)
{
    bool res {false};
    IntKey* ik = new IntKey {codigo};
    if (zonasDep->member(ik)) {
        res = true;
    }
    delete ik;
    return res;
}

bool Departamento::eliminarPropiedad(int codigoProp)
{
    bool fueEliminada {false};
    IIterator* it = zonasDep->getIterator();
    while (it->hasCurrent() && (!fueEliminada)) {
        Zona* z = dynamic_cast<Zona*>(it->getCurrent());
        fueEliminada = z->eliminarPropiedad(codigoProp, mat.front());
        it->next();
    }
    delete it;
    return fueEliminada;
}



// Funcion auxiliar
// Precondicion: zonasDep->member(clave)
Zona* Departamento::hallarZona(int codigoZ)
{
    IntKey* clave = new IntKey {codigoZ};
    Zona* res = dynamic_cast<Zona*>(zonasDep->find(clave));
    delete clave;
    return res;
}



/* Devuelve una coleccion de DtCodDirProp
con codigo y direccion de todas las
propiedades que hay en cierta zona.
Precondicion: existeZona(codigoZ) */
ICollection* Departamento::listarPropsZona(int codigoZ)
{
    ICollection* res {nullptr};
    Zona* z = hallarZona(codigoZ);
    res = z->listarCodDirProps();
    return res;
}

ICollectible* Departamento::seleccionarPropiedad(int codigoZ, int codigoProp)
{
    Zona* z = hallarZona(codigoZ);
    return (z->seleccionarPropiedad(codigoProp));
}

/* Devuelve una coleccion con los datos de todas
las propiedades que hay en el departamento */
ICollection* Departamento::listarProps()
{
    ICollection* res = new List();
    IIterator* it = zonasDep->getIterator();
    while (it->hasCurrent()) {
        Zona* z = dynamic_cast<Zona*>(it->getCurrent());
        ICollection* propsZ = z->listarProps();
        IIterator* it2 = propsZ->getIterator();
        while (it2->hasCurrent()) {
            res->add(it2->getCurrent());
            it2->next();
        }
        delete it2;
        delete propsZ;
        it->next();
    }
    delete it;
    return res;
 
}



// Enviar Mensaje (Usuario Interesado):

// Ya se chequeo la existencia de la zona en ControladorPropiedades
ICollection* Departamento::elegirZona(int codigoZ)
{
    Zona* z = hallarZona(codigoZ);
    ICollection* res {nullptr};
    res = z->darDtProps();
    return res;
}



ICollection* Departamento::elegirPropConv(int codigoZ, int codProp)
{
    Zona* z = hallarZona(codigoZ);
    ICollection* res {nullptr};
    res = z->elegirPropConv(codProp);
    return res;
}



void Departamento::ingresarMensaje(string texto, int codZ, int codProp)
{
    Zona* z = hallarZona(codZ);
    z->ingresarMensaje(texto, codProp);
}
