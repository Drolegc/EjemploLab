// Zona.cpp

#include <stdexcept>
#include "Zona.h"
#include "TipoOferta.h"
#include "TipoPropiedad.h"
#include "Apartamento.h"
#include "Casa.h"
#include "DtZona.h"
#include "IntKey.h"
#include "InfoPropiedad.h"
#include "DtCodDirProp.h"
#include "collections/OrderedDictionary.h"
#include "collections/List.h"
#include "interfaces/IIterator.h"

Zona::Zona(int codigo, string nombre) : nom {nombre}
{
    cod = codigo;
    propiedades = new OrderedDictionary();
}

Zona::~Zona()
{
    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
        Propiedad* temp = 
                dynamic_cast<Propiedad*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete propiedades;
}

ICollectible* Zona::darDtZona()
{
    DtZona* res = new DtZona {cod, nom};
    return res;
}

int Zona::altaOferta(DtOferta dtOf)
{
    Propiedad* p {nullptr};
    if (dtOf.darTipoP() == TipoPropiedad::apartamento) {
        p = new Apartamento {this, dtOf.darCodigoP(), dtOf.darCantAmbientes(),
            dtOf.darCantDormitorios(), dtOf.darCantBanios(),
            dtOf.darHayGaraje(), dtOf.darDireccion(), dtOf.darM2Edif(),
            dtOf.darNombreEdif()};
    }
    else if (dtOf.darTipoP() == TipoPropiedad::casa) {
        p = new Casa {this, dtOf.darCodigoP(), dtOf.darCantAmbientes(),
            dtOf.darCantDormitorios(), dtOf.darCantBanios(),
            dtOf.darHayGaraje(), dtOf.darDireccion(), dtOf.darM2Edif(),
            dtOf.darM2EspVerde()};
    }

    if (dtOf.darTipoOf() == TipoOferta::alquiler)
        p->altaAlquiler(dtOf.darPrecio(), dtOf.darLetraDep());
    else
        p->altaVenta(dtOf.darPrecio(), dtOf.darLetraDep());
    IntKey* ik = new IntKey {dtOf.darCodigoP()};
    propiedades->add(ik, p);
    return (dtOf.darCodigoP());
}

bool Zona::eliminarPropiedad(int codigoProp, char letraDep)
{
    bool fueEliminada {false};
    IntKey* ik = new IntKey {codigoProp};
    if (propiedades->member(ik)) {
        Propiedad* p = dynamic_cast<Propiedad*>(propiedades->find(ik));
        p->marcar(true, letraDep, cod);
        fueEliminada = true;
    }
    delete ik;
    return fueEliminada;
}

/* Retorna una coleccion con codigo y direccion de todas
las propiedades de la zona */
ICollection* Zona::listarCodDirProps()
{
    ICollection* res = new List();
    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
        Propiedad* prop = dynamic_cast<Propiedad*>(it->getCurrent());
        if (!(prop->propEstaMarcada())) {
            DtCodDirProp* dt = 
                   dynamic_cast<DtCodDirProp*>(prop->darCodDir());
            res->add(dt);
        }
        it->next();
    }
    delete it;
    return res;
}



bool Zona::existePropiedad(int codProp)
{
    bool res {false};
    IntKey* clave = new IntKey {codProp};
    if (propiedades->member(clave)) {
        Propiedad* prop = dynamic_cast<Propiedad*>(propiedades->find(clave));
        if (!(prop->propEstaMarcada()))
            res = true;
    }
    delete clave;
    return res;
}



Propiedad* Zona::hallarPropiedad(int codProp)
{
    IntKey* clave = new IntKey {codProp};
    Propiedad* prop = dynamic_cast<Propiedad*>(propiedades->find(clave));
    delete clave;
    return prop;
}



ICollectible* Zona::seleccionarPropiedad(int codigoProp)
{
    if (!existePropiedad(codigoProp))
        throw std::invalid_argument("No existe propiedad con ese codigo");

    Propiedad* prop = hallarPropiedad(codigoProp);

    ICollectible* infoProp = prop->darInfoPropiedad();
    InfoPropiedad* res = dynamic_cast<InfoPropiedad*>(infoProp);
    return res; 
}

/* Retorna una coleccion con los datos de todas las propiedades
de la zona */
ICollection* Zona::listarProps()
{
    ICollection* res = new List();
    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
        Propiedad* prop = dynamic_cast<Propiedad*>(it->getCurrent());
        if (!(prop->propEstaMarcada())) {
            InfoPropiedad* info = 
                    dynamic_cast<InfoPropiedad*>(prop->darInfoPropiedad());
            res->add(info);
        }
        it->next();
    }
    delete it;
    return res;
}

// Enviar Mensaje (Usuario Interesado):

ICollection* Zona::darDtProps()
{
    ICollection* res = new List();
    IIterator* it = propiedades->getIterator();
    while (it->hasCurrent()) {
        Propiedad* prop = dynamic_cast<Propiedad*>(it->getCurrent());
        if (!(prop->propEstaMarcada())) {
            ICollectible* dtProp = prop->darDtPropiedad();
            res->add(dtProp);
        }
        it->next();
    }
    delete it;
    return res;
}



ICollection* Zona::elegirPropConv(int codProp)
{
    ICollection* res {nullptr};
    if (!existePropiedad(codProp))
        throw std::invalid_argument("No existe propiedad con ese codigo");
    Propiedad* prop = hallarPropiedad(codProp);
    res = prop->ultimos5Msj();
    return res;
}



void Zona::ingresarMensaje(string texto, int codProp)
{
    if (!existePropiedad(codProp))
        throw std::invalid_argument("No existe propiedad con ese codigo");
    Propiedad* prop = hallarPropiedad(codProp);
    prop->ingresarMensaje(texto);
}
