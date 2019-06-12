// DtInmobiliaria.h

#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
using std::string;

#include "Direccion.h"

struct DtInmobiliaria {
public:
    explicit DtInmobiliaria(string email, string nombre, Direccion ubicacion);
    ~DtInmobiliaria() {}

    string darEmail();
    string darNombre();
    Direccion darUbicacion();

private:
    string mail;
    string nom;
    Direccion dir;    
};

#endif
