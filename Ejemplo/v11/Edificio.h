// Edificio.h

#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
using std::string;

#include "interfaces/ICollectible.h"

#include "DtEdificio.h"

class Edificio : public ICollectible {
public:
    Edificio();
    explicit Edificio(string nombre, int cantidadPisos, double gastosComunes);
    Edificio(const Edificio&) = delete;
    Edificio& operator=(const Edificio&) = delete;
    ~Edificio() {}

    string darNombre();
    int darCantidadPisos();
    double darGastosComunes();

    void modificarNombre(string nombre);
    void modificarCantidadPisos(int cantidadPisos);
    void modificarGastosComunes(double gastosComunes);

    DtEdificio darDtEdificio();

private:
    string nom;
    int cantPisos;
    double gastosCom;
};

#endif
