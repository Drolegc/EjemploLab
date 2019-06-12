// Mensaje.cpp

#include "Mensaje.h"
#include "HoraSistema.h"

Mensaje::Mensaje(string texto, string email)
        : t {texto}, emailEmisor {email}
{
    HoraSistema* hs = HoraSistema::getInstance();
    fyh = hs->darFechaYHora();
}

FechaYHora Mensaje::darFechaYHora()
{
    return fyh;
}

string Mensaje::darTexto()
{
    return t;
}

DtMensaje Mensaje::darDtMensaje()
{
    DtMensaje res {fyh, t, emailEmisor};
    return res;
}

string Mensaje::darEmailEmisor()
{
    return emailEmisor;
}
