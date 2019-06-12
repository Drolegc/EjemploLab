// DtMensaje.cpp

#include "DtMensaje.h"

DtMensaje::DtMensaje(FechaYHora fechaYHora, string texto, string email)
        : fyh {fechaYHora}, t {texto}, emailEmisor {email}
{
}

FechaYHora DtMensaje::darFechaYHora()
{
    return fyh;
}

string DtMensaje::darTexto()
{
    return t;
}

string DtMensaje::darEmisor()
{
    return emailEmisor;
}
