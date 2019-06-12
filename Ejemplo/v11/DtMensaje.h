// DtMensaje.h

#ifndef DT_MENSAJE_H
#define DT_MENSAJE_H

#include <string>
using std::string;

#include "FechaYHora.h"
#include "interfaces/ICollectible.h"

struct DtMensaje : public ICollectible {
public:
    DtMensaje() {}
    explicit DtMensaje(FechaYHora fechaYHora, string texto, string email);
    ~DtMensaje() {}

    FechaYHora darFechaYHora();
    string darTexto();
    string darEmisor();

private:
    FechaYHora fyh;
    string t;
    string emailEmisor;
};

#endif
