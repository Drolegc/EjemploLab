// Conversa.h

#ifndef CONVERSA_H
#define CONVERSA_H

#include "Inmobiliaria.h"
#include "Interesado.h"
#include "Mensaje.h"
#include "Propiedad.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include <string>
using std::string;

class Conversa : public ICollectible {
public:
    Conversa();
    ~Conversa();

    // Enviar Mensaje (Usuario Interesado):
    bool esConvInteresado(string emailLogueado);
    int cantMensajes();
    ICollection* darUltimos5();

    void darAltaConversa(Propiedad* propiedad);
    void ingresarMensaje(string texto);

    void marcar(bool estaMarcada) { marcada = estaMarcada; }
    bool propEstaMarcada() { return marcada; }

private:
    bool marcada;
    IDictionary* mensajes;
    Inmobiliaria* inm;
    Interesado* inter;
    Propiedad* prop;
};

#endif
