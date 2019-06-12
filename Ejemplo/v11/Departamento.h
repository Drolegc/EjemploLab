// Departamento.h

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
using std::string;

#include "Direccion.h"
#include "DtOferta.h"
#include "InfoPropiedad.h"
#include "IntKey.h"
#include "Zona.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

#include "DtDepartamento.h"

class Departamento : public ICollectible {
public:
    Departamento() {}
    explicit Departamento(string matricula, string nombre);
    Departamento(const Departamento&) = delete;
    Departamento& operator=(const Departamento&) = delete;
    ~Departamento();

    string darMatricula();
    string darNombre();

    DtDepartamento* darDtDepartamento();
    int altaOferta(DtOferta dtOf);

    ICollection* zonas();
    void crearZona(int codigo, string nombre);
    bool existeZona(int codigo);

    bool eliminarPropiedad(int codigoProp);

    ICollection* listarPropsZona(int codigoZ);
    ICollectible* seleccionarPropiedad(int codigoZ, int codigoProp);

    ICollection* listarProps();

    // Enviar Mensaje (Usuario Interesado):
    ICollection* elegirZona(int codigoZ);
    ICollection* elegirPropConv(int codigoZ, int codProp);
    void ingresarMensaje(string texto, int codZ, int codProp);

private:
    // Crea la clave a partir del codigo y hace un
    // find en la coleccion
    Zona* hallarZona(int codigoZ);

    string mat;
    string nom;
    IDictionary* zonasDep;
};

#endif
