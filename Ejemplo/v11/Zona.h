// Zona.h

#ifndef ZONA_H
#define ZONA_H

#include "Direccion.h"
#include "DtOferta.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include <string>
using std::string;

class Propiedad;
class Departamento;

class Zona : public ICollectible {
public:
    explicit Zona(int codigo, string nombre);
    Zona(const Zona&) = delete;
    Zona& operator=(const Zona&) = delete;
    ~Zona();

    int darCodigo() { return cod; }
    string darNombre() { return nom; }

    ICollectible* darDtZona();
    int altaOferta(DtOferta dtOf);

    bool existePropiedad(int codProp);

    bool eliminarPropiedad(int codigoProp, char letraDep);

    ICollection* listarCodDirProps();
    ICollectible* seleccionarPropiedad(int codigoProp);

    ICollection* listarProps();

    // Enviar Mensaje (Usuario Interesado):
 
    ICollection* darDtProps();
    ICollection* elegirPropConv(int codProp);
    void ingresarMensaje(string texto, int codProp);

private:
    Propiedad* hallarPropiedad(int codProp);

    int cod;
    string nom;
    IDictionary* propiedades;

};

#include "Propiedad.h"
#include "Departamento.h"

#endif
