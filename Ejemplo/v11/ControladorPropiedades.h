// ControladorPropiedades.h

#ifndef CONTROLADOR_PROPIEDADES_H
#define CONTROLADOR_PROPIEDADES_H

#include "Departamento.h"
#include "Direccion.h"
#include "InfoPropiedad.h"
#include "TipoPropiedad.h"
#include "interfaces/IDictionary.h"
#include "interfaces/ICollection.h"

class ControladorPropiedades {
public:
    static ControladorPropiedades* getInstance();
    ControladorPropiedades(const ControladorPropiedades&) = delete;
    void operator=(const ControladorPropiedades&) = delete;
    ~ControladorPropiedades();

    // Operaciones varias:
    void liberarMemoria();
    void resetearCodigosProps();
    ICollection* listarProps();
    void agregarDepartamento(Departamento* dep);
    void crearZona(string matDep, string nombre);
    Departamento* hallarDepartamento();
    void guardarZona(Departamento* dep, int codigoZona);
    DtDepartamento* darDepartamentoPorMatricula(string matricula);
    // Alta Edificio: 
    void altaEdificio(string nombre, int cantidadPisos, double gastosComunes);

    // Alta Propiedad:
    ICollection* verDepartamentos();
    ICollection* seleccionarDepartamento(string matricula);
    void seleccionarZona(int codigo);
    ICollection* ingresarApartamento(int cantAmbientes, int cantDormitorios,
            int cantBanios, bool tieneGaraje, Direccion direccion,
            double m2Edificados);
    void seleccionarEdificio(string nombreEdificio);
    void ingresarCasa(int cantAmbientes, int cantDormitorios,
            int cantBanios, bool tieneGaraje, Direccion direccion,
            double m2Edificados, double m2EspacioVerde);
    int altaOferta(TipoOferta oferta, double precio);
    int altaAlquiler(double precioAlquiler);
    int altaVenta(double valor);

    // Consultar Propiedad:
    // 1) verDepartamentos igual que antes
    // 2) seleccionarDepartamento igual que antes
    // 3) Pero se agregan estas dos operaciones:
    ICollection* listarPropsZona(int codigoZ);
    InfoPropiedad* seleccionarPropiedad(int codigoProp);


    // Eliminar Propiedad:
    // Retorna falso si la propiedad no esta en el sistema
    bool eliminarPropiedad(int codigoProp);

    // Enviar Mensaje (Usuario Interesado):
    // 1) verDepartamento igual que en Alta Propiedad
    // 2) seleccionarDepartamento igual que en Alta Propiedad
    // Tres operaciones nuevas:

    // Retorna una coleccion de DtPropiedad
    ICollection* elegirZona(int codigoZ);
    ICollection* elegirPropConv(int codProp);
    void ingresarMensaje(string texto);

private:
    ControladorPropiedades();

    static ControladorPropiedades* instance;
    IDictionary* departamentos;
    string matriculaGuardada;
    int codigoZonaGuardado;
    int codPropGuardado;
    TipoPropiedad tipoPropGuardado;
    int cantAmbGuardada;
    int cantDormGuardada;
    int cantBaniosGuardada;
    bool propTieneGaraje;
    Direccion dirGuardada;
    double m2EdifGuardados;
    double m2EspVerdeGuardados;
    string nombreEdificioGuardado;
    int ultimoCodigoApartamento;
    int ultimoCodigoCasa;
    int ultimoCodigoZona;
};

#endif
