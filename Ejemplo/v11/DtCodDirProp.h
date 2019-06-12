// DtCodDirProp.h

#ifndef DTCODDIRPROP_H
#define DTCODDIRPROP_H

#include "Direccion.h"
#include "interfaces/ICollectible.h"

struct DtCodDirProp : public ICollectible {
public:
    explicit DtCodDirProp(int codigo, Direccion direccion, bool enAlquiler,
                          bool enVenta);
    ~DtCodDirProp() {}

    int darCodigo();
    Direccion darDireccion();
    bool estaEnAlquiler();
    bool estaEnVenta();

private:
    int cod;
    Direccion dir;
    bool seAlquila;
    bool seVende;
};

#endif
