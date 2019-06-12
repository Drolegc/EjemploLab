// Inmobiliaria.h

#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <string>
using std::string;

#include "Usuario.h"
#include "Direccion.h"
#include "DtInmobiliaria.h"
#include "DtReporteInm.h"
#include "ReporteDepartamento.h"
#include "ReporteZona.h"
#include "TipoPropiedad.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

class Conversa;
class Propiedad;
class Apartamento;

class Inmobiliaria : public Usuario {
public:
    Inmobiliaria(); 
    explicit Inmobiliaria(string email, string nombre, Direccion ubicacion);
    ~Inmobiliaria();

    Inmobiliaria(const Inmobiliaria&) = delete;
    Inmobiliaria& operator=(const Inmobiliaria&) = delete;

    void agregarConversa(Conversa* c);
    void agregarPropiedad(Propiedad* p, char letraDep);

    void modificarNombre(string nombre);
    void modificarUbicacion(Direccion ubicacion);
    string darNombre();
    Direccion darUbicacion();

    DtInmobiliaria darDtInmobiliaria();
    ICollection* reportarPorDepartamento();
    ICollection* reportarPorZona();
    ICollectible* darReporteCompleto();

    void restarDeReporte(char letraDep, int codZona, TipoPropiedad tipoProp);

private:
    string nom;
    Direccion dir;
    ICollection* conversaciones;
    IDictionary* props;
    IDictionary* reportesDep;
    IDictionary* reportesZ;
};

#include "Conversa.h"
#include "Propiedad.h"
#include "Apartamento.h"

#endif
