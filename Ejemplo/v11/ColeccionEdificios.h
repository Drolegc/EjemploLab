// ColeccionEdificios.h

#ifndef COLECCIONEDIFICIOS_H
#define COLECCIONEDIFICIOS_H

#include <string>
using std::string;
#include "interfaces/IDictionary.h"
#include "interfaces/ICollection.h"
#include "Edificio.h"

class ColeccionEdificios {
public:
    static ColeccionEdificios* getInstance();
    ColeccionEdificios(const ColeccionEdificios&) = delete;
    ColeccionEdificios& operator=(const ColeccionEdificios&) = delete;
    ~ColeccionEdificios();

    void agregarEdificio(Edificio* e);
    bool existeEdificio(string nombre);

    ICollection* darDataEdificios();
    Edificio* darEdificio(string nombreEdificio);

private:
    ColeccionEdificios();
    static ColeccionEdificios* instance;
    IDictionary* edificios;
 
};

#endif
