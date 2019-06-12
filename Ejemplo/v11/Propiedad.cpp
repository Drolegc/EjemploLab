// Propiedad.cpp

#include "Propiedad.h"
#include "DtCodDirProp.h"
#include "DtPropiedad.h"
#include "Sesion.h"
#include "collections/List.h"

Propiedad::Propiedad(Zona* z, int codigoProp, int cantidadAmbientes,
        int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
        Direccion dir, double m2EdificadosProp)
        : zona {z}, direccion {dir},
        alquiler {nullptr}, inm {nullptr}, venta {nullptr}
{
    codigo = codigoProp;
    cantAmbientes = cantidadAmbientes;
    cantDormitorios = cantidadDormitorios;
    cantBanios = cantidadBanios;
    tieneGaraje = propTieneGaraje;
    m2Edificados = m2EdificadosProp;
    marcada = false;

    conversas = new List();
}



void Propiedad::setearAlquiler(Alquiler* alq)
{
    alquiler = alq;
}



void Propiedad::setearVenta(Venta* vent)
{
    venta = vent;
}



void Propiedad::setearInmobiliaria(Inmobiliaria* inmobiliaria, char letraDep)
{
    inm = inmobiliaria;
    inm->agregarPropiedad(this, letraDep);
}



/* Precondicion: Hay un usuario inmobiliaria logueado en el
sistema */
void Propiedad::setearInmobiliaria(char letraDep)
{
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*>(s->darUsuario());
    setearInmobiliaria(inmo, letraDep);
}



void Propiedad::altaVenta(double valor, char letraDep) {
    Venta* ven = new Venta {valor};
    setearVenta(ven);
    setearInmobiliaria(letraDep);
}



void Propiedad::altaAlquiler(double precioAlquiler, char letraDep) {
    Alquiler* alq = new Alquiler {precioAlquiler};
    setearAlquiler(alq);
    setearInmobiliaria(letraDep);
}



ICollectible* Propiedad::darCodDir()
{
    bool seAlquila {false};
    bool seVende {false};
    if (alquiler != nullptr)
        seAlquila = true;
    if (venta != nullptr)
        seVende = true;
    DtCodDirProp* dt = new DtCodDirProp {darCodigo(), darDireccion(),
            seAlquila, seVende};
    return dt;
}



DtInmobiliaria Propiedad::darDtInmobiliaria()
{
    return inm->darDtInmobiliaria();    
}



Propiedad::~Propiedad()
{
    delete alquiler;
    delete venta;
    IIterator* it = conversas->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    delete conversas;
}



string Propiedad::darEmailLogueado()
{
    Sesion* s = Sesion::getInstance();
    string emailLogueado = s->darEmailUsuario();
    return emailLogueado;
}



ICollectible* Propiedad::darDtPropiedad()
{
    int cantMsjs = 0;

    string emailLogueado {darEmailLogueado()};

    IIterator* it = conversas->getIterator();
    bool encontrada {false};
    while ((it->hasCurrent()) && (!encontrada)) {
        Conversa* c = dynamic_cast<Conversa*>(it->getCurrent());
        if (c->esConvInteresado(emailLogueado)) {
            encontrada = true;
            cantMsjs = c->cantMensajes();
        }
        it->next();
    }
    delete it;

    DtPropiedad* res = new DtPropiedad(codigo, direccion, cantMsjs);
    return res;
}



ICollection* Propiedad::ultimos5Msj()
{
    ICollection* res {nullptr};

    string emailLogueado {darEmailLogueado()};

    bool encontrada {false};
    IIterator* it = conversas->getIterator();
    while ((it->hasCurrent()) && (!encontrada)) {
        Conversa* conv = dynamic_cast<Conversa*>(it->getCurrent());
        if (conv->esConvInteresado(emailLogueado)) {
            encontrada = true;
            res = conv->darUltimos5();
        }
        it->next();
    }
    delete it;
    return res;
}


/* Agrega un nuevo mensaje a la conversa del usuario logueado.
Si la conversa aun no existe, la crea. 
Precondicion: ControladorUsuarios::sesionInt() */
void Propiedad::ingresarMensaje(string texto)
{
    string emailLogueado {darEmailLogueado()};
    bool encontrada {false};
    IIterator* it = conversas->getIterator();
    while ((it->hasCurrent()) && (!encontrada)) {
        Conversa* conv = dynamic_cast<Conversa*>(it->getCurrent());
        if (conv->esConvInteresado(emailLogueado)) {
            encontrada = true;
            conv->ingresarMensaje(texto);
        }
        it->next();
    }
    delete it;
    if (!encontrada) {
        Conversa* nuevaConversa = new Conversa {};
        nuevaConversa->darAltaConversa(this);
        nuevaConversa->ingresarMensaje(texto);
        conversas->add(nuevaConversa);
    }
} 



void Propiedad::restarDeReporte(char letraDep, int codZona)
{
    TipoPropiedad tipoProp {darTipoProp()};
    inm->restarDeReporte(letraDep, codZona, tipoProp);
}



void Propiedad::marcar(bool estaMarcada, char letraDep, int codZona)
{
    if (!marcada) {
        marcada = estaMarcada;
        restarDeReporte(letraDep, codZona);
    }
}
