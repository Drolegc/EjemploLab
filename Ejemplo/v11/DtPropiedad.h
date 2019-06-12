// DtPropiedad.h

#ifndef DT_PROPIEDAD_H
#define DT_PROPIEDAD_H

#include <string>
using std::string;

#include "Direccion.h"
#include "interfaces/ICollectible.h"

struct DtPropiedad : public ICollectible {
public:
    DtPropiedad();
    explicit DtPropiedad(int codigo, Direccion direccion,
                         int cantMensajesEnviados);
    ~DtPropiedad() {}

    int darCodigo();
    Direccion darDireccion();
    int darCantMensajes();

private:
    int cod;
    Direccion dir;
    int cantMsjs;
};

#endif
