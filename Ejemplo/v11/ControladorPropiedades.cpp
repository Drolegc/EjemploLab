// ControladorPropiedades.cpp

#include <string>

#include <iostream>
using std::cout;

#include <stdexcept>

#include "ControladorPropiedades.h"
#include "LetraIdentificadora.h"
#include "ColeccionEdificios.h"
#include "DtDepartamento.h"
#include "DtOferta.h"
#include "interfaces/IIterator.h"
#include "collections/OrderedDictionary.h"
#include "collections/List.h"

ControladorPropiedades* ControladorPropiedades::instance {nullptr};

ControladorPropiedades::ControladorPropiedades()
{
    departamentos = new OrderedDictionary();
    tipoPropGuardado = TipoPropiedad::noValido;
    codigoZonaGuardado = -1;
    codPropGuardado = -1;
    cantAmbGuardada = -1;
    cantDormGuardada = -1;
    cantBaniosGuardada = -1;
    propTieneGaraje = false;
    m2EdifGuardados = -1.0;
    m2EspVerdeGuardados = -1.0;
    ultimoCodigoApartamento = 1110;
    ultimoCodigoCasa = 2110;
    ultimoCodigoZona = 100;
    // los strings se inicializan solos
}

ControladorPropiedades* ControladorPropiedades::getInstance()
{
    if (instance == nullptr)
        instance = new ControladorPropiedades();
    return instance;
}



ControladorPropiedades::~ControladorPropiedades()
{
    IIterator* it = departamentos->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    // Elimina departamentos con toda LetraIdentificadora
    delete departamentos;
    instance = nullptr;
}



void ControladorPropiedades::liberarMemoria()
{
    matriculaGuardada = "";
    codigoZonaGuardado = -1;
    codPropGuardado = -1;
    tipoPropGuardado = TipoPropiedad::noValido;
    cantAmbGuardada = -1;
    cantDormGuardada = -1;
    cantBaniosGuardada = -1;
    propTieneGaraje = false;
    Direccion dirVacia {"", ""};
    dirGuardada = dirVacia;
    m2EdifGuardados = -1.0;
    m2EspVerdeGuardados = -1.0;
    nombreEdificioGuardado = "";
}



void ControladorPropiedades::resetearCodigosProps()
{
    ultimoCodigoApartamento = 1110;
    ultimoCodigoCasa = 2110;
    ultimoCodigoZona = 100;
}



/* Devuelve una coleccion con los datos de 
todas las propiedades del sistema */
ICollection* ControladorPropiedades::listarProps()
{
    ICollection* res = new List();
    IIterator* it = departamentos->getIterator();
    while (it->hasCurrent()) {
        Departamento* dep = 
                dynamic_cast<Departamento*>(it->getCurrent());
        ICollection* propsDep = dep->listarProps();
        IIterator* it2 = propsDep->getIterator();
        while (it2->hasCurrent()) {
            res->add(it2->getCurrent());
            it2->next();
        }
        delete it2;
        delete propsDep;
        it->next();
    }
    delete it;
    return res;
}

DtDepartamento* ControladorPropiedades::darDepartamentoPorMatricula(string matricula){
    Departamento* dep;
    
    LetraIdentificadora* letraId = new LetraIdentificadora(matricula.front());
    if (!departamentos->member(letraId)) {
        delete letraId;
        throw std::invalid_argument("El departamento no existe");
    }
    dep = dynamic_cast<Departamento*>(departamentos->find(letraId));
    DtDepartamento* dtDep = dep->darDtDepartamento();
    delete letraId;
    return dtDep;
}


void ControladorPropiedades::agregarDepartamento(Departamento* dep) 
{
    LetraIdentificadora* letraId = new LetraIdentificadora
                                   {dep->darMatricula().front()};
    if (departamentos->member(letraId)) {
        delete letraId;
        throw std::invalid_argument("LetraIdentificadora no unica\n");
    }
    departamentos->add(letraId, dep);
}



void ControladorPropiedades::crearZona(string matDep, string nombre)
{
    LetraIdentificadora* id = new LetraIdentificadora {matDep.front()};
    if (departamentos->member(id)) {
        Departamento* d = 
                dynamic_cast<Departamento*>(departamentos->find(id));
        delete id; // en caso de que crearZona lance una excepcion,
                   // "id" habra sido liberada antes
        d->crearZona(++ultimoCodigoZona, nombre);
    }
    else
        delete id;
}



void ControladorPropiedades::altaEdificio(string nombre, int cantidadPisos, 
                                          double gastosComunes)
{
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();
    if (!(ce->existeEdificio(nombre))) {
        Edificio* e = new Edificio {nombre, cantidadPisos, gastosComunes};
        ce->agregarEdificio(e);
    }
    else
        throw std::invalid_argument("Ya existe un edificio con ese nombre");
}



ICollection* ControladorPropiedades::verDepartamentos()
{
    List* res = new List();
    IIterator* it = departamentos->getIterator();
    while (it->hasCurrent()) {
        Departamento* dep = dynamic_cast<Departamento*>(it->getCurrent());
        DtDepartamento* dtDep = dep->darDtDepartamento();
        res->add(dtDep);
        it->next();
    }
    delete it;
    return res;
}



ICollection* ControladorPropiedades::seleccionarDepartamento(string matricula)
{
    LetraIdentificadora* letraId = new LetraIdentificadora(matricula.front());
    if (!departamentos->member(letraId)) {
        delete letraId;
        throw std::invalid_argument("El departamento no existe");
    }
    Departamento* dep = 
            dynamic_cast<Departamento*>(departamentos->find(letraId));
    ICollection* dt = dep->zonas();
    matriculaGuardada = matricula;
    delete letraId;
    return dt;
}



// Precondicion: Hay matricula guardada
Departamento* ControladorPropiedades::hallarDepartamento()
{
    LetraIdentificadora* letra = 
            new LetraIdentificadora {matriculaGuardada.front()};
    Departamento* dep = 
            dynamic_cast<Departamento*>(departamentos->find(letra));
    delete letra;
    return dep;
}


/* Si la Zona de codigo codigoZona existe en el Departamento dep,
guarda el codigo. De lo contrario, lanza una excepcion */
void ControladorPropiedades::guardarZona(Departamento* dep, int codigoZona)
{
    if (!(dep->existeZona(codigoZona)))
        throw std::invalid_argument("No existe una zona con ese codigo");
    codigoZonaGuardado = codigoZona;
}



void ControladorPropiedades::seleccionarZona(int codigo)
{
    Departamento* dep = hallarDepartamento();
    guardarZona(dep, codigo);
}



ICollection* ControladorPropiedades::ingresarApartamento(int cantAmbientes,
        int cantDormitorios, int cantBanios, bool tieneGaraje,
        Direccion direccion, double m2Edificados)
{
    if (cantAmbientes < 1 || cantDormitorios < 0 || cantBanios < 0 ||
                m2Edificados <= 0.0)
        throw std::invalid_argument("Valores no validos");
    tipoPropGuardado = TipoPropiedad::apartamento;
    cantAmbGuardada = cantAmbientes;
    cantDormGuardada = cantDormitorios;
    cantBaniosGuardada = cantBanios;
    propTieneGaraje = tieneGaraje;
    dirGuardada = direccion;
    m2EdifGuardados = m2Edificados;
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();
    return ce->darDataEdificios();
}



void ControladorPropiedades::seleccionarEdificio(string nombreEdificio)
{
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();
    if (ce->existeEdificio(nombreEdificio))
        nombreEdificioGuardado = nombreEdificio;
}



void ControladorPropiedades::ingresarCasa(int cantAmbientes,
        int cantDormitorios, int cantBanios, bool tieneGaraje,
        Direccion direccion, double m2Edificados, double m2EspacioVerde)
{
    if (cantAmbientes < 1 || cantDormitorios < 0 || cantBanios < 0 ||
                m2Edificados <= 0.0 || m2EspacioVerde < 0)
        throw std::invalid_argument("Valores no validos");
    tipoPropGuardado = TipoPropiedad::casa;
    cantAmbGuardada = cantAmbientes;
    cantDormGuardada = cantDormitorios;
    cantBaniosGuardada = cantBanios;
    propTieneGaraje = tieneGaraje;
    dirGuardada = direccion;
    m2EdifGuardados = m2Edificados;
    m2EspVerdeGuardados = m2EspacioVerde;
}



int ControladorPropiedades::altaOferta(TipoOferta oferta, double precio)
{
    int res {0};
    LetraIdentificadora* letra = 
            new LetraIdentificadora {matriculaGuardada.front()};
    Departamento* dep =
            dynamic_cast<Departamento*>(departamentos->find(letra));
    delete letra;

    int codigoProp {0};
    if (tipoPropGuardado == TipoPropiedad::apartamento) {
        ++ultimoCodigoApartamento;
        codigoProp = ultimoCodigoApartamento;
    }
    else {
        ++ultimoCodigoCasa;
        codigoProp = ultimoCodigoCasa;
    }

    DtOferta dtOf {tipoPropGuardado, oferta, codigoProp,
                precio, cantAmbGuardada, cantDormGuardada,
                cantBaniosGuardada, propTieneGaraje, dirGuardada,
                m2EdifGuardados, m2EspVerdeGuardados, nombreEdificioGuardado,
                codigoZonaGuardado, matriculaGuardada.front()};
    res = dep->altaOferta(dtOf);
    liberarMemoria();
    return res;
}



int ControladorPropiedades::altaAlquiler(double precioAlquiler)
{
    int res {0};
    TipoOferta tipoOf {TipoOferta::alquiler};
    res = altaOferta(tipoOf, precioAlquiler);
    return res;
}



int ControladorPropiedades::altaVenta(double valor)
{
    int res {0};
    TipoOferta tipoOf {TipoOferta::venta};
    res = altaOferta(tipoOf, valor);
    return res;
}


/* Devuelve una coleccion de DtCodDirProp con codigo
y direccion de todas las propiedades de la zona 
Pre: seleccionarDepartamento */
ICollection* ControladorPropiedades::listarPropsZona(int codigoZ)
{
    codigoZonaGuardado = codigoZ;
    ICollection* res {nullptr};
    LetraIdentificadora* clave
            = new LetraIdentificadora {matriculaGuardada.front()};
    Departamento* dep =
                dynamic_cast<Departamento*>(departamentos->find(clave));
    delete clave;
    if (dep->existeZona(codigoZ)) {
        res = dep->listarPropsZona(codigoZ);
    }
    return res;
}



InfoPropiedad* ControladorPropiedades::seleccionarPropiedad(int codigoProp)
{
    LetraIdentificadora* letra =
            new LetraIdentificadora {matriculaGuardada.front()};
    Departamento* dep =
            dynamic_cast<Departamento*>(departamentos->find(letra));
    ICollectible* infoProp = dep->seleccionarPropiedad(codigoZonaGuardado,
                                                       codigoProp);
    InfoPropiedad* res = dynamic_cast<InfoPropiedad*>(infoProp);
    delete letra;
    liberarMemoria();
    return res;
}



bool ControladorPropiedades::eliminarPropiedad(int codigoProp)
{
    bool fueEliminada {false};
    IIterator* it = departamentos->getIterator();
    while (it->hasCurrent() && (!fueEliminada)) {
        Departamento* dep = dynamic_cast<Departamento*>(it->getCurrent());
        fueEliminada = dep->eliminarPropiedad(codigoProp);
        it->next();
    }
    delete it;
    return fueEliminada;
}



// Enviar Mensaje (Usuario Interesado):

// Precondicion: seleccionarDepartamento
ICollection* ControladorPropiedades::elegirZona(int codigoZ)
{
    Departamento* dep = hallarDepartamento();
    guardarZona(dep, codigoZ);
    ICollection* res {nullptr};
    res = dep->elegirZona(codigoZonaGuardado);
    return res;
}


/* Precondicion: elegirZona
PostCondicion: En caso de que exista una Conversa del usuario logueado
acerca de la propiedad de codigo codProp, devuelve los ultimos
cinco mensajes; en caso contrario, retorna nullptr */
ICollection* ControladorPropiedades::elegirPropConv(int codProp)
{
    Departamento* dep = hallarDepartamento();
    ICollection* res {nullptr};
    res = dep->elegirPropConv(codigoZonaGuardado, codProp);
    codPropGuardado = codProp;
    return res;
}



void ControladorPropiedades::ingresarMensaje(string texto)
{
    Departamento* dep = hallarDepartamento();
    dep->ingresarMensaje(texto, codigoZonaGuardado, codPropGuardado);
    liberarMemoria();
}
