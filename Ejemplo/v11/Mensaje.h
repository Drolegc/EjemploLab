// Mensaje.h

#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
using std::string;

#include "interfaces/ICollectible.h"

#include "FechaYHora.h"
#include "DtMensaje.h"
#include <string>
using std::string;

class Mensaje : public ICollectible {
public:
    Mensaje() {}
    explicit Mensaje(string texto, string email);
    Mensaje(const Mensaje&) = delete;
    Mensaje& operator=(const Mensaje&) = delete;
    ~Mensaje() {}

    FechaYHora darFechaYHora();
    string darTexto();
    string darEmailEmisor();

    DtMensaje darDtMensaje();

private:
    FechaYHora fyh;
    string t;
    string emailEmisor;
};

#endif
