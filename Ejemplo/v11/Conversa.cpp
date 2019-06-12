// Conversa.cpp

#include "Conversa.h"
#include "DtMensaje.h"
#include "Sesion.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

Conversa::Conversa()
{
    mensajes = new OrderedDictionary();
    marcada = false;
}

Conversa::~Conversa()
{
    IIterator* it = mensajes->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    delete mensajes;
}

/* Devuelve verdadero si el email pasado por parametro
corresponde al interesado asociado a la Conversa, y falso
en caso contrario */
bool Conversa::esConvInteresado(string emailUsuario)
{
    bool res {false};
    if ((inter->darEmail()) == emailUsuario)
        res = true;
    return res;
}



/* Devuelve la cantidad de mensajes de la Conversa */
int Conversa::cantMensajes()
{
    return (mensajes->getSize());
}


/* Retorna una coleccion de DtMensaje con la informacion
de los cinco ultimos mensajes */
ICollection* Conversa::darUltimos5()
{
    ICollection* res = new List();

    OrderedDictionary* mensajesPtr =
            dynamic_cast<OrderedDictionary*>(mensajes);

    // getInverseIterator es una operacion de OrderedDictionary,
    // pero no de IDictionary
    IIterator* it = mensajesPtr->getInverseIterator();
    int contador = 0;
    while ((it->hasCurrent()) && (contador < 5)) {
        Mensaje* msj =
                dynamic_cast<Mensaje*>(it->getCurrent());
        DtMensaje* dt = new DtMensaje {msj->darDtMensaje()};
        res->add(dt);
        ++contador;
        it->next();
    }
    delete it;

    return res;
}

// Precondicion: La Propiedad propiedad es quien invoca
// la operacion, encargandose de agregar la Conversa
// a su coleccion
void Conversa::darAltaConversa(Propiedad* propiedad)
{
    inm = propiedad->darInmobiliaria();
    Sesion* ses = Sesion::getInstance();
    inter = dynamic_cast<Interesado*>(ses->darUsuario());
    prop = propiedad;

    inm->agregarConversa(this);
    inter->agregarConversa(this);
}

// Crea un nuevo mensaje, con fecha y hora actuales
// del sistema, y lo agrega a la coleccion
void Conversa::ingresarMensaje(string texto)
{
    Sesion* ses = Sesion::getInstance();
    string email {ses->darEmailUsuario()};
    Mensaje* msj = new Mensaje {texto, email};
    IntKey* numeroDeMensaje = new IntKey {(mensajes->getSize()) + 1};
    mensajes->add(numeroDeMensaje, msj);
}
