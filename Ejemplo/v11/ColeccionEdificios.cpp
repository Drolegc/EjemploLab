// ColeccionEdificios.cpp

#include "ColeccionEdificios.h"
#include "StringKey.h"
#include "interfaces/IIterator.h"
#include "collections/OrderedDictionary.h"
#include "collections/List.h"

ColeccionEdificios* ColeccionEdificios::instance {nullptr};

ColeccionEdificios::ColeccionEdificios()
{
    edificios = new OrderedDictionary();
}

ColeccionEdificios* ColeccionEdificios::getInstance()
{
    if (instance == nullptr)
        instance = new ColeccionEdificios();
    return instance;
}

ColeccionEdificios::~ColeccionEdificios()
{
    IIterator* it = edificios->getIterator();
    while (it->hasCurrent()) {
        Edificio* temp = dynamic_cast<Edificio*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete edificios;
    instance = nullptr;
}

void ColeccionEdificios::agregarEdificio(Edificio* e)
{
    StringKey* sk = new StringKey {e->darNombre()};
    edificios->add(sk, e);
}

bool ColeccionEdificios::existeEdificio(string nombre)
{
    bool res {false};
    StringKey* sk = new StringKey {nombre};
    if (edificios->member(sk))
        res = true;
    delete sk;
    return res;
}

ICollection* ColeccionEdificios::darDataEdificios()
{
    List* res = new List();
    IIterator* it = edificios->getIterator();
    while (it->hasCurrent()) {
        Edificio* e = dynamic_cast<Edificio*>(it->getCurrent());
        DtEdificio* dt = new DtEdificio {e->darNombre(), e->darCantidadPisos(), 
                      e->darGastosComunes()};
        res->add(dt);
        it->next();
    }
    delete it;
    return res;
}



Edificio* ColeccionEdificios::darEdificio(string nombreEdificio)
{
    Edificio* res {nullptr};
    StringKey* sk = new StringKey {nombreEdificio};
    if (edificios->member(sk))
        res = dynamic_cast<Edificio*>(edificios->find(sk));
    delete sk;
    return res;
}
