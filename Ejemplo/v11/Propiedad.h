// Propiedad.h

#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "Alquiler.h"
#include "Venta.h"
#include "InfoPropiedad.h"
#include "TipoPropiedad.h"
#include "Zona.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"

class Conversa;
class Inmobiliaria;
class DtInmobiliaria;

class Propiedad : public ICollectible {
public:
    explicit Propiedad(Zona* z, int codigoProp, int cantidadAmbientes,
            int cantidadDormitorios, int cantidadBanios, bool propTieneGaraje,
            Direccion dir, double m2EdificadosProp);
    Propiedad(const Propiedad&) = delete;
    Propiedad& operator=(const Propiedad&) = delete;
    virtual ~Propiedad();

    int darCodigo() { return codigo; }
    int darCantAmbientes() { return cantAmbientes; }
    int darCantDormitorios() { return cantDormitorios; }
    int darCantBanios() { return cantBanios; }
    bool propTieneGaraje() { return tieneGaraje; }
    Direccion darDireccion() { return direccion; }
    double darM2Edificados() { return m2Edificados; }
    void setearAlquiler(Alquiler* alq);
    void setearVenta(Venta* vent);
    void setearInmobiliaria(char letraDep);

    Inmobiliaria* darInmobiliaria() { return inm; }
    Zona* darZona() { return zona; }
    Alquiler* darAlquiler() { return alquiler; }
    Venta* darVenta() { return venta; }
    
    virtual double darM2Totales() = 0;
 
    void altaVenta(double valor, char letraDep);
    void altaAlquiler(double precioAlquiler, char letraDep);

    ICollectible* darCodDir();
    DtInmobiliaria darDtInmobiliaria();
    virtual ICollectible* darInfoPropiedad() = 0;

    // Enviar Mensaje (Usuario Interesado):
    ICollectible* darDtPropiedad();
    ICollection* ultimos5Msj();
    void ingresarMensaje(string texto);

    // Otras operaciones:
    virtual TipoPropiedad darTipoProp() = 0;
    void restarDeReporte(char letraDep, int codZona);
    void marcar(bool estaMarcada, char letraDep, int codZona);
    bool propEstaMarcada() { return marcada; }
    int darCodigoZona() { return zona->darCodigo(); };

private:
    void setearInmobiliaria(Inmobiliaria* inmobiliaria, char letraDep);
    string darEmailLogueado();

    bool marcada;

    Zona* zona;
    int codigo;
    int cantAmbientes;
    int cantDormitorios;
    int cantBanios;
    bool tieneGaraje;
    Direccion direccion;
    double m2Edificados;
    Alquiler* alquiler;
    Inmobiliaria* inm;
    Venta* venta;
    ICollection* conversas;
};

#include "Conversa.h"
#include "Inmobiliaria.h"
#include "DtInmobiliaria.h"

#endif
