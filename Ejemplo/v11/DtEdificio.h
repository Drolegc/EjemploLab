// DtEdificio.h

#ifndef DT_EDIFICIO_H
#define DT_EDIFICIO_H

#include <string>
using std::string;
#include "interfaces/ICollectible.h"

struct DtEdificio : public ICollectible {
public:
    DtEdificio();
    explicit DtEdificio(string nombre, int cantidadPisos, double gastosComunes);
    ~DtEdificio() {}

    string darNombre();
    int darCantidadPisos();
    double darGastosComunes();   

private:
    string nom;
    int cantPisos;
    double gastosCom; 
};

#endif
