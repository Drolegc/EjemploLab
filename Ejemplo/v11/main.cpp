// main.cpp

#include <exception>
#include <stdexcept>
using std::invalid_argument;
#include <iostream>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "ColeccionEdificios.h"
#include "ControladorPropiedades.h"
#include "ControladorUsuarios.h"
#include "DtCodDirProp.h"
#include "DtDepartamento.h"
#include "DtInmobiliaria.h"
#include "DtMensaje.h"
#include "DtOferta.h"
#include "DtPropiedad.h"
#include "DtReporteDep.h"
#include "DtReporteZ.h"
#include "DtZona.h"
#include "FechaYHora.h"
#include "HoraSistema.h"
#include "InfoPropiedad.h"
#include "InfoAp.h"
#include "InfoC.h"
#include "Sesion.h"
#include "TipoOferta.h"
#include "TipoPropiedad.h"

enum class TipoData : char {dataCodDirP, dataInfoP, dataProp, dataMsj,
                            dataRepD, dataRepZ, dataRepInm};



TipoData darTipoData(ICollectible* data);
void imprimirData(ICollectible* data, TipoData t);
void imprimirDtColeccion(ICollection* col);

ostream& operator<<(ostream& imprimir, DtCodDirProp* dt) {
    cout << "\nCodigo de la propiedad: " << dt->darCodigo()

            << "\nDireccion: " << dt->darDireccion().darCalle() << " "
            << dt->darDireccion().darNumero()

            << "\nEsta en alquiler? ";
    if (dt->estaEnAlquiler())
        cout << "Si";
    else
        cout << "No";

    cout << "\nEsta en venta? ";
    if (dt->estaEnVenta())
        cout << "Si\n";
    else
        cout << "No\n";

    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtPropiedad* dt) {
    cout << "\nCodigo de la propiedad: " << dt->darCodigo()
            << "\nDireccion: " << dt->darDireccion().darCalle() << " "
            << dt->darDireccion().darNumero()
            << "\nCantidad de mensajes: " << dt->darCantMensajes() << '\n';
    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtMensaje* dt) {
    cout << "\nEmisor: " << dt->darEmisor()

            << "\nFecha del mensaje: " << dt->darFechaYHora().darDia() <<
            '/' << dt->darFechaYHora().darMes() << '/' << dt->darFechaYHora().darAnio()

            << "\nHora del mensaje: " << dt->darFechaYHora().darHora() << ':';
    if ((dt->darFechaYHora().darMinuto()) < 10)
        cout << '0';
    cout << dt->darFechaYHora().darMinuto()

            << "\nTexto: " << dt->darTexto() << '\n';

    return imprimir;
}

ostream& operator<<(ostream& imprimir, InfoPropiedad* info) {
    cout << "\nCodigo de la propiedad: " << info->darCodigo() <<
            "\nCantidad de ambientes: " << info->darCantAmb() <<
            "\nCantidad de dormitorios: " << info->darCantDorm() <<
            "\nCantidad de banios: " << info->darCantBanios() <<
            "\nPropiedad tiene garaje? ";
    if (info->darHayGaraje())
        cout << "Si";
    else
        cout << "No";
    cout << "\nDireccion: " << info->darDir().darCalle() << " " <<
            info->darDir().darNumero() << "\nMetros cuadrados edificados: " <<
            info->darM2Edif() << "\nEsta en venta? ";
    if ((info->darPrecioV()) >= 0)
        cout << "Si\nValor: " << info->darPrecioV();
    else
        cout << "No";
    cout << "\nEsta en alquiler? ";
    if ((info->darPrecioA()) >= 0)
        cout << "Si\nPrecio del alquiler: " << info->darPrecioA();
    else
        cout << "No";
    cout << "\nEmail de la inmobiliaria que ofrece la propiedad: " <<
            info->darEmailInm() <<
            "\nCodigo de la zona donde se encuentra la propiedad: " <<
            info->darCodZ();

    if (InfoAp * ap = dynamic_cast<InfoAp*> (info)) {
        cout << "\nLa propiedad es un apartamento" <<
                "\nMetros cuadrados totales: " << ap->darM2Totales() <<
                "\nNombre del edificio: " << ap->darNombreEdificio() << "\n\n";
    } else if (InfoC * c = dynamic_cast<InfoC*> (info)) {
        cout << "\nLa propiedad es una casa" <<
                "\nMetros cuadrados de espacio verde: " << c->darM2EspacioVerde() <<
                "\nMetros cuadrados totales: " << c->darM2Totales() << "\n\n";
    }
    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtInmobiliaria dt) {
    cout << "\nEmail: " << dt.darEmail()
            << "\nNombre: " << dt.darNombre()
            << "\nDireccion: " << dt.darUbicacion().darCalle() << " "
            << dt.darUbicacion().darNumero() << '\n';
    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtReporteDep* dt) {
    cout << "\nLetra identificadora del departamento: "
            << dt->darLetraIdentificadora()
            << "\nCantidad de casas: " << dt->darCantCasas()
            << "\nCantidad de apartamentos: " << dt->darCantApartamentos()
            << '\n';
    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtReporteZ* dt) {
    cout << "\nCodigo de la zona: "
            << dt->darCodigoZ()
            << "\nCantidad de casas: " << dt->darCantCasas()
            << "\nCantidad de apartamentos: " << dt->darCantApartamentos()
            << '\n';
    return imprimir;
}

ostream& operator<<(ostream& imprimir, DtReporteInm* dt) {
    cout << dt->darDtInm();
    imprimirDtColeccion(dt->darRepDeps());
    imprimirDtColeccion(dt->darRepZonas());
    return imprimir;
}


void eliminarSingletons() {
    HoraSistema* hs = HoraSistema::getInstance();
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Sesion* s = Sesion::getInstance();
    delete s;
    delete cp;
    delete cu;
    delete ce;
    delete hs;
}

void eliminarColeccion(ICollection* coleccion) {
    IIterator* it = coleccion->getIterator();
    while (it->hasCurrent()) {
        ICollectible* temp = it->getCurrent();
        it->next();
        delete temp;
    }
    delete it;
    delete coleccion;
}

void altaInmobiliariaAuto(string calle, string numero, string nombre,
        string email) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Direccion dirInm{calle, numero};
    cu->altaInmobiliaria(nombre, dirInm, email);
    cu->aceptarAltaInmob();
}

void altaInteresadoAuto(string email, int edad, string nombre, string apellido) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    cu->altaInteresado(nombre, apellido, edad, email);
}

void altaInmPredeterminadas() {
    string calles[]{"Benitez", "Rivera", "Comercio", "Inca"};
    string numeros[]{"1134", "1340", "234", "3456"};
    string nombres[]{"Selmo", "Garcia", "Invernissi", "Solei"};
    string emails[]{"inm1@sis.com", "inm2@sis.com", "inm3@sis.com",
        "inm4@sis.com"};

    for (int i = 0; i < 4; ++i) {
        altaInmobiliariaAuto(calles[i], numeros[i], nombres[i], emails[i]);
    }
}

void altaInterPredeterminados() {
    string emails[]{"int1@sis.com", "int2@sis.com", "int3@sis.com",
        "int4@sis.com", "Int5.com"};
    int edades[]{34, 56, 45, 30, 60};
    string nombres[]{"Julio", "Andrea", "Sonia", "Alfonso", "Juan"};
    string apellidos[]{"Chaz", "Berruti", "Braga", "Mier", "Alpi"};
    // string pass[] {"passt1", "passt2", "passt3", "passt4", "passt5"};

    for (int i = 0; i < 5; ++i) {
        altaInteresadoAuto(emails[i], edades[i], nombres[i], apellidos[i]);
    }
}

void iniciarSesionAuto(string email, string contrasenia) {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    if (cu->ingresarEmail(email)) {
        if (cu->esPrimeraSesion(email)) {
            cu->registrarContrasenia(contrasenia);
            if (cu->ingrVerifiContrasenia(contrasenia))
                cout << '\n' << email << " acaba de iniciar sesion\n";
        } else if (cu->ingresarContrasenia(contrasenia))
            cout << '\n' << email << " acaba de iniciar sesion\n";
    }
}

void agregarDepsAuto() {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    string matriculasDeps[]{"ABCDE", "BCDE", "CDE", "DE", "E"};

    string nombresDeps[]{"Canelones", "Maldonado", "Rocha", "Salto",
        "Montevideo"};

    for (int i = 0; i < 5; ++i) {
        try {
            Departamento* dep = new Departamento{matriculasDeps[i],
                nombresDeps[i]};
            cp->agregarDepartamento(dep);
            cout << "Departamento " << i + 1 << " ingresado satisfactoriamente\n";
        }        catch (std::invalid_argument& invalido) {
            cout << "ERROR: " << invalido.what() << '\n';
        }
    }
}

void crearZona(string letra, string nombre) {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    try {
        cp->crearZona(letra, nombre);
    }    catch (std::invalid_argument& invalido) {
        cout << "ERROR: " << invalido.what();
    }
}

void altaZonasAuto() {
    crearZona("A", "Zona1");
    crearZona("A", "Zona2");
    crearZona("B", "Zona3");
    crearZona("D", "Zona4");
    crearZona("D", "Zona5");
}

void altaEdificiosAuto() {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    string nombresEds[]{"Apache Valiente", "Mebeo", "Socrates", "El Burdel",
        "Milajo"};

    int cantPisosEds[]{4, 20, 34, 12, 5};

    double gastosComunesEds[]{1234, 1244, 3452, 456, 900};

    for (int i = 0; i < 5; ++i) {
        try {
            cp->altaEdificio(nombresEds[i], cantPisosEds[i],
                    gastosComunesEds[i]);
        }        catch (std::invalid_argument& invalido) {
            cout << "ERROR: " << invalido.what() << '\n';
        }
    }
}

void altaOfertaAuto(string matriculaDep, DtOferta dtOf) {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    ICollection* dtz = cp->seleccionarDepartamento(matriculaDep);
    eliminarColeccion(dtz);

    cp->seleccionarZona(dtOf.darCodigoZ());

    if (dtOf.darTipoP() == TipoPropiedad::apartamento) {
        ICollection* edifs = cp->ingresarApartamento(dtOf.darCantAmbientes(),
                dtOf.darCantDormitorios(), dtOf.darCantBanios(),
                dtOf.darHayGaraje(), dtOf.darDireccion(), dtOf.darM2Edif());
        eliminarColeccion(edifs);

        cp->seleccionarEdificio(dtOf.darNombreEdif());
    } else if (dtOf.darTipoP() == TipoPropiedad::casa)
        cp->ingresarCasa(dtOf.darCantAmbientes(), dtOf.darCantDormitorios(),
            dtOf.darCantBanios(), dtOf.darHayGaraje(), dtOf.darDireccion(),
            dtOf.darM2Edif(), dtOf.darM2EspVerde());

    if (dtOf.darTipoOf() == TipoOferta::alquiler)
        cp->altaAlquiler(dtOf.darPrecio());
    else
        cp->altaVenta(dtOf.darPrecio());
}

TipoData darTipoData(ICollectible* data) {
    TipoData res;

    DtCodDirProp* ptrCodDirP;
    InfoPropiedad* ptrInfoProp;
    DtPropiedad* ptrDtProp;
    DtMensaje* ptrDtMsj;
    DtReporteDep* ptrDtRepD;
    DtReporteZ* ptrDtRepZ;
    DtReporteInm* ptrDtRepInm;

    if ((ptrCodDirP = dynamic_cast<DtCodDirProp*> (data)))
        res = TipoData::dataCodDirP;
    else if ((ptrInfoProp = dynamic_cast<InfoPropiedad*> (data)))
        res = TipoData::dataInfoP;
    else if ((ptrDtProp = dynamic_cast<DtPropiedad*> (data)))
        res = TipoData::dataProp;
    else if ((ptrDtMsj = dynamic_cast<DtMensaje*> (data)))
        res = TipoData::dataMsj;
    else if ((ptrDtRepD = dynamic_cast<DtReporteDep*> (data)))
        res = TipoData::dataRepD;
    else if ((ptrDtRepZ = dynamic_cast<DtReporteZ*> (data)))
        res = TipoData::dataRepZ;
    else if ((ptrDtRepInm = dynamic_cast<DtReporteInm*> (data)))
        res = TipoData::dataRepInm;

    return res;
}

void imprimirData(ICollectible* data, TipoData t) {
    switch (t) {
        case TipoData::dataCodDirP:
        {
            DtCodDirProp* pdata = dynamic_cast<DtCodDirProp*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataInfoP:
        {
            InfoPropiedad* pdata = dynamic_cast<InfoPropiedad*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataProp:
        {
            DtPropiedad* pdata = dynamic_cast<DtPropiedad*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataMsj:
        {
            DtMensaje* pdata = dynamic_cast<DtMensaje*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataRepD:
        {
            DtReporteDep* pdata = dynamic_cast<DtReporteDep*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataRepZ:
        {
            DtReporteZ* pdata = dynamic_cast<DtReporteZ*> (data);
            cout << pdata;
            break;
        }
        case TipoData::dataRepInm:
        {
            DtReporteInm* pdata = dynamic_cast<DtReporteInm*> (data);
            cout << pdata;
            break;
        }
    }
}

void imprimirDtColeccion(ICollection* col) {
    if (col != nullptr) {
        IIterator* it = col->getIterator();
        while (it->hasCurrent()) {
            TipoData tipo = darTipoData(it->getCurrent());
            imprimirData(it->getCurrent(), tipo);
            it->next();
        }
        delete it;
        eliminarColeccion(col);
    }
}

void imprimirDtMsjs(ICollection* dtMsjs) {
    if (dtMsjs) {
        IIterator* it = dtMsjs->getIterator();
        while (it->hasCurrent()) {
            DtMensaje* data =
                    dynamic_cast<DtMensaje*> (it->getCurrent());
            cout << data;
            it->next();
        }
        delete it;
        eliminarColeccion(dtMsjs);
    }
}

void enviarMensajeAuto(string emailInter, string passInter, string texto,
        string matriculaDep, int codigoZ, int codProp) {
    iniciarSesionAuto(emailInter, passInter);
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ICollection* coleccionZonas = cp->seleccionarDepartamento(matriculaDep);
    eliminarColeccion(coleccionZonas);

    ICollection* dtProps = cp->elegirZona(codigoZ);
    imprimirDtColeccion(dtProps);

    ICollection* dtMsjs = cp->elegirPropConv(codProp);
    imprimirDtColeccion(dtMsjs);
    cp->ingresarMensaje(texto);
}

void enviarMsjsPredeterminados() {
    int dias[]{25, 24, 23, 1, 2, 3};
    int meses[]{5, 5, 5, 6, 6, 6};
    int anio{2016};
    int horas[]{13, 12, 12, 0, 12, 2};
    int minutos[]{2, 30, 35, 30, 45, 5};
    string emails[]{"int1@sis.com", "int3@sis.com", "int1@sis.com",
        "int2@sis.com", "int4@sis.com", "int1@sis.com"};
    string pass[]{"passt1", "passt3", "passt1", "passt2", "passt4", "passt1"};
    string textos[]{"Estoy Interesado", "Cuanto cuesta?",
        "PERDON ME EQUIVOQUE", "Quiero hacer una oferta ya!",
        "Tiene humedad?", "Cual es el precio?"};
    string matriculas[]{"DE", "ABCDE", "DE", "ABCDE", "ABCDE", "ABCDE"};
    int codigosZ[]{105, 102, 105, 101, 101, 102};
    int codProps[]{2111, 2114, 2111, 1111, 1112, 1113};

    HoraSistema* hs = HoraSistema::getInstance();

    for (int i = 0; i < 6; ++i) {
        FechaYHora fyh(dias[i], meses[i], anio, horas[i], minutos[i]);
        hs->setearFechaYHora(fyh);
        enviarMensajeAuto(emails[i], pass[i], textos[i], matriculas[i],
                codigosZ[i], codProps[i]);
    }
}


void menuConsultarPropiedad();

void altasOfertasPredeterminadas() {
    string emails[]{"inm1@sis.com", "inm1@sis.com", "inm2@sis.com",
        "inm2@sis.com", "inm3@sis.com", "inm4@sis.com", "inm1@sis.com",
        "inm1@sis.com", "inm2@sis.com", "inm3@sis.com", "inm4@sis.com"};

    string pass[]{"pass4", "pass4", "pass5", "pass5", "pass6", "pass7",
        "pass4", "pass4", "pass5", "pass6", "pass7"};

    string calles[]{"Iturria", "Iturria", "CALLEJON", "CORCEGA", "LUCRECIA",
        "LUCRECIA", "Chana", "Gloria", "CHAPAZ", "JUANICO",
        "VENECIA"};

    string numeros[]{"1115 AP 104", "1115 AP 105", "456 AP 01",
        "3456 AP 2", "456 AP 3", "456 AP 3", "2345", "345",
        "345", "456", "3456"};

    TipoPropiedad tiposP[]{TipoPropiedad::apartamento,
        TipoPropiedad::apartamento, TipoPropiedad::apartamento,
        TipoPropiedad::apartamento, TipoPropiedad::apartamento,
        TipoPropiedad::apartamento, TipoPropiedad::casa,
        TipoPropiedad::casa, TipoPropiedad::casa, TipoPropiedad::casa,
        TipoPropiedad::casa};

    TipoOferta tiposO[]{TipoOferta::venta, TipoOferta::venta,
        TipoOferta::alquiler, TipoOferta::alquiler, TipoOferta::alquiler,
        TipoOferta::alquiler, TipoOferta::venta, TipoOferta::venta,
        TipoOferta::venta, TipoOferta::alquiler, TipoOferta::alquiler};

    double precios[]{34567, 65789, 7689, 6789, 7890, 768, 45000, 34560, 13000,
        20000, 56789};

    int cantAmbs[]{2, 3, 2, 7, 4, 2, 12, 2, 3, 6, 3};

    int cantDorms[]{1, 1, 1, 3, 1, 1, 5, 1, 1, 3, 1};

    int cantBanios[]{1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1};

    bool hayGaraje[]{false, false, true, true, false, false, true, false,
        false, true, false};

    double m2Edif[]{34, 35, 45, 34, 25, 17, 34, 35, 12, 34, 25};

    double m2EspVer[]{-1, -1, -1, -1, -1, -1, 10, 20, 10, 0, 0};

    string nombresEd[]{"Apache Valiente", "Apache Valiente", "Mebeo",
        "Socrates", "El Burdel", "El Burdel", "", "", "", "", ""};

    int codigosZ[]{101, 101, 102, 103, 104, 104, 105, 104, 101, 102, 101};

    string matriculas[]{"ABCDE", "ABCDE", "ABCDE", "BCDE", "DE", "DE", "DE",
        "DE", "ABCDE", "ABCDE", "ABCDE"};

    for (int i = 0; i < 11; ++i) {
        iniciarSesionAuto(emails[i], pass[i]);

        Direccion dir{calles[i], numeros[i]};

        DtOferta dtOf{tiposP[i], tiposO[i], -1, precios[i], cantAmbs[i],
            cantDorms[i], cantBanios[i], hayGaraje[i], dir, m2Edif[i],
            m2EspVer[i], nombresEd[i], codigosZ[i], matriculas[i].front()};

        altaOfertaAuto(matriculas[i], dtOf);
    }
}

void cargarDatosPredeterminados() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    cu->crearAdministrador("adm1@sis.com", "Pass1");
    agregarDepsAuto();
    altaZonasAuto();
    altaEdificiosAuto();
    altaInmPredeterminadas();
    altasOfertasPredeterminadas();
    altaInterPredeterminados();

    cout << "------------- Se Cargaron los datos predeterminados, presione enter para continuar ------------- " << endl;
    cin.get();
    cin.get();
}

void mostrarDepartamentos() {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ICollection* Departamentos;
    IIterator* it;
    DtDepartamento* dep;
    string nomDep;
    string idDep;
    char letraIdentificadora;

    Departamentos = cp->verDepartamentos();
    it = Departamentos->getIterator();
    system("clear");
    cout << "------------ DEPARTAMENTOS ------------" << endl;
    while (it->hasCurrent()) {


        dep = dynamic_cast<DtDepartamento*> (it->getCurrent());
        nomDep = dep->darNombre();
        idDep = dep->darMatricula();
        letraIdentificadora = idDep.front();
        cout << "Letra Identificadora: ";
        cout << letraIdentificadora << endl;
        cout << "Matricula: ";
        cout << idDep << endl;
        cout << "Nombre: ";
        cout << nomDep << endl;
        cout << "____________" << endl;
        it->next();
    }
    delete it;
    eliminarColeccion(Departamentos);
}

void mostrarZonas(string depElegido) {
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ICollection* zonasDep;
    DtZona* zon;
    IIterator* it;
    DtDepartamento* dep;
    string nomZona;
    int codigoZona;
    string nomDep;

    try {
        zonasDep = cp->seleccionarDepartamento(depElegido);
        dep = cp->darDepartamentoPorMatricula(depElegido);
        it = zonasDep->getIterator();
        system("clear");
        cout << "Mostrando zonas del departamento ";
        nomDep = dep->darNombre();
        cout << nomDep << endl;
        while (it->hasCurrent()) {
            zon = dynamic_cast<DtZona*> (it->getCurrent());
            nomZona = zon->darNombre();
            codigoZona = zon->darCodigo();
            cout << "Codigo Zona: ";
            cout << codigoZona << endl;
            cout << "Nombre Zona: ";
            cout << nomZona << endl;
            cout << "___________" << endl;
            it->next();
        }
        delete it;
        delete dep;
        eliminarColeccion(zonasDep);
    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR:  " << e.what();
        cin.get();
        cin.get();
        menuConsultarPropiedad();
    }

}

// Operaciones de menu

void menuConsultarPropiedad();

void menuIniciarSesion() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    string email, pass;
    system("clear");
    cout << "Ingrese Email: " << endl;
    cin >> email;
    cout << "Ingrese Contaseña: " << endl;
    cin >> pass;

    if (cu->existeUsuario(email)) {
        if (cu->esPrimeraSesion(email)) {
            iniciarSesionAuto(email, pass);
            cin.get();
            cin.get();
        } else {
            do {
                cu->ingresarEmail(email);
                if (cu->ingresarContrasenia(pass)) {
                    iniciarSesionAuto(email, pass);
                    cin.get();
                    cin.get();

                } else {
                    system("clear");
                    cout << "La contraseña no coincide con el usuario" << endl;
                    cout << "Vuelva a ingresar la contrasenia, o presione 0 para cancelar" << endl;
                    cin >> pass;
                    if (pass == "0") {
                        system("clear");
                        cu->cancelar();
                        menuIniciarSesion();
                    }

                }
            } while (cu->ingresarContrasenia(pass));

        }

    } else {
        system("clear");
        cout << "El usuario no existe, presione enter para re intentar" << endl;
        cin.get();
        cin.get();
        system("clear");
        menuIniciarSesion();
    }

}

void menuCrearAdmin() {
    string email;
    string pass;

    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    cout << "Ingrese el email del administrador a crear:" << endl;
    cin >> email;
    cout << "Ingrese su contraseña:" << endl;
    cin >> pass;
    try {
        cu->crearAdministrador(email, pass);
        system("clear");
        cout << "Se agrego el administrador: " << email;
        cin.get();
        cin.get();
    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR" << e.what();

        cin.get();
        cin.get();
    }
}

void menuAltaInmobiliaria() {
    string NombreInm;
    string calle;
    string numero;
    string email;


    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    system("clear");
    cout << "Ingrese el nombre de la inmobiliaria" << endl;
    cin >> NombreInm;
    cout << "Ingrese calle" << endl;
    cin >> calle;
    cout << "Ingrese numero" << endl;
    cin >> numero;
    Direccion dir12(calle, numero);
    cout << "ingrese email" << endl;
    cin >> email;
    try {
        cu->altaInmobiliaria(NombreInm, dir12, email);
        system("clear");
        cout << "Se agrego la inmobiliaria " << NombreInm;
        cin.get();
        cin.get();
    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR: " << e.what();
        cin.get();
        cin.get();
    }

}

void menuAltaInteresado() {
    string nom;
    string ape;
    int edad;
    string email;

    ControladorUsuarios* cu = ControladorUsuarios::getInstance();

    cout << "Ingrese nombre de interesado" << endl;
    cin >> nom;
    cout << "Ingrese apellido del interesado " << endl;
    cin >> ape;
    cout << "Ingrese la edad del interesado" << endl;
    cin >> edad;
    cout << "Ingrese el email del interesado" << endl;
    cin >> email;
    try {
        cu->altaInteresado(nom, ape, edad, email);
        system("clear");
        cout << "Se agrego el interesado: " << nom;
        cin.get();
        cin.get();
    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR" << e.what();

        cin.get();
        cin.get();
    }

}

void menuAltaEdificio() {
    string nombre;
    int pisos;
    double gastosComunes;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    system("clear");
    cout << "Ingrese el nombre del edificio: " << endl;
    cin >> nombre;
    cout << "Ingrese cantidad de pisos:" << endl;
    cin >> pisos;
    cout << "Ingrese gastos comunes: " << endl;
    cin >> gastosComunes;
    try {
     cp->altaEdificio(nombre, pisos, gastosComunes);
    cout << "Se agrego el Edificio: ";
    cout << nombre << endl;
    cout << "Pisos: ";
    cout << pisos << endl;
    cout << "Gastos Comunes: ";
    cout << gastosComunes << endl;
    cout << "Presione enter para volver al menu";
    } catch (invalid_argument e) {
        cout << "Error: " << e.what() << endl;
        
    }
    
    cin.get();
    cin.get();

}

void menuAltaApartamento(int codZona) {

    int cantAmbientes;
    int dormitorios;
    int banios;
    int op;
    int montoAlquiler;
    int montoVenta;
    int m2Edificados;
    int codigoProp;
    bool garage;
    string confirmacion;
    string calle;
    string numero;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    system("clear");
    cout << "Ingrese cantidad de ambientes" << endl;
    cin >> cantAmbientes;
    cout << "Ingrese cantidad de dormitorios" << endl;
    cin >> dormitorios;
    cout << "Ingrese cantidad de baños" << endl;
    cin >> banios;
    cout << "Tiene garage? (Y-N)" << endl;
    cin >> confirmacion;
    do {
        if (confirmacion == "y" or confirmacion == "Y") {
            garage = true;
        } else if (confirmacion == "n" or confirmacion == "N") {
            garage = false;
        } else {
            system("clear");
            cout << "Escriba Y o N" << endl;
        }
    } while (confirmacion != "y" and confirmacion != "n" and confirmacion != "Y" and confirmacion != "N");
    cout << "Ingrese calle" << endl;
    cin >> calle;
    cout << "Ingrese numero" << endl;
    cin >> numero;
    Direccion dir(calle, numero);
    cout << "Ingrese m2Edificados" << endl;
    cin >> m2Edificados;
    system("clear");
    do {


        cout << "Presione 1 si se encuentra en alquiler o 2 si se encuentra en venta." << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese monto del alquiler" << endl;
                cin >> montoAlquiler;
                try {
                    cp->ingresarApartamento(cantAmbientes, dormitorios, banios, garage, dir, m2Edificados);
                    codigoProp = cp->altaAlquiler(montoAlquiler);
                    cout << "Se agrego el apartamento " << codigoProp << endl;
                    cout << "Cantidad de ambientes: " << cantAmbientes << endl;
                    cout << "Cantidad de dormitorios: " << dormitorios << endl;
                    cout << "Cantidad de baños: " << banios << endl;
                    cout << "Garage: ";
                    if (garage) {
                        cout << "Si" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                    cout << "Direccion: " << calle << " " << numero << endl;
                    cout << "Metros edificados " << m2Edificados << endl;

                } catch (invalid_argument e) {
                    cout << "ERROR: " << e.what() << endl;

                }

                cin.get();

                break;
            case 2:
                cout << "Ingrese monto de venta:" << endl;
                cin >> montoVenta;
                try {

                    cp->ingresarApartamento(cantAmbientes, dormitorios, banios, garage, dir, m2Edificados);
                    codigoProp = cp->altaVenta(montoVenta);
                    cout << "Se agrego el apartamento " << codigoProp << endl;
                    cout << "Cantidad de ambientes: " << cantAmbientes << endl;
                    cout << "Cantidad de dormitorios: " << dormitorios << endl;
                    cout << "Cantidad de baños: " << banios << endl;
                    cout << "Garage: ";
                    if (garage) {
                        cout << "Si" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                    cout << "Direccion: " << calle << " " << numero << endl;
                    cout << "Metros edificados " << m2Edificados << endl;

                } catch (invalid_argument e) {
                    cout << "ERROR:" << e.what();
                }
                cin.get();
                break;
            default:
                cout << "Error: elija una opcion valida" << endl;
                break;
        }
    } while (op != 1 and op != 2);

}

void menuAltaCasa(int codZona) {
    int cantAmbientes;
    int dormitorios;
    int banios;
    int op;
    int montoAlquiler;
    int montoVenta;
    int m2Edificados;
    int m2EspacioVerde;
    int codigoProp;
    bool garage;
    string confirmacion;
    string calle;
    string numero;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    system("clear");
    cout << "Ingrese cantidad de ambientes" << endl;
    cin >> cantAmbientes;
    cout << "Ingrese cantidad de dormitorios" << endl;
    cin >> dormitorios;
    cout << "Ingrese cantidad de baños" << endl;
    cin >> banios;
    cout << "Tiene garage? (Y-N)" << endl;
    cin >> confirmacion;
    do {
        if (confirmacion == "y" or confirmacion == "Y") {
            garage = true;
        } else if (confirmacion == "n" or confirmacion == "N") {
            garage = false;
        } else {
            system("clear");
            cout << "Escriba Y o N" << endl;
        }
    } while (confirmacion != "y" and confirmacion != "n" and confirmacion != "Y" and confirmacion != "N");
    cout << "Ingrese calle" << endl;
    cin >> calle;
    cout << "Ingrese numero" << endl;
    cin >> numero;
    Direccion dir(calle, numero);
    cout << "Ingrese m2Edificados" << endl;
    cin >> m2Edificados;
    cout << "Ingrese m2EspacioVerde" << endl;
    cin >> m2EspacioVerde;
    system("clear");
    do {


        cout << "Presione 1 si se encuentra en alquiler o 2 si se encuentra en venta." << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese monto del alquiler" << endl;
                cin >> montoAlquiler;
                try {
                    cp->ingresarCasa(cantAmbientes, dormitorios, banios, garage, dir, m2Edificados, m2EspacioVerde);
                    codigoProp = cp->altaAlquiler(montoAlquiler);
                    cout << "Se agrego la casa " << codigoProp << endl;
                    cout << "Cantidad de ambientes: " << cantAmbientes << endl;
                    cout << "Cantidad de dormitorios: " << dormitorios << endl;
                    cout << "Cantidad de baños: " << banios << endl;
                    cout << "Garage: ";
                    if (garage) {
                        cout << "Si" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                    cout << "Direccion: " << calle << " " << numero << endl;
                    cout << "Metros edificados " << m2Edificados << endl;

                } catch (invalid_argument e) {
                    cout << "ERROR: " << e.what() << endl;

                }

                cin.get();

                break;
            case 2:
                cout << "Ingrese monto de venta:" << endl;
                cin >> montoVenta;
                try {

                    cp->ingresarCasa(cantAmbientes, dormitorios, banios, garage, dir, m2Edificados, m2EspacioVerde);
                    codigoProp = cp->altaVenta(montoVenta);
                    cout << "Se agrego la casa " << codigoProp << endl;
                    cout << "Cantidad de ambientes: " << cantAmbientes << endl;
                    cout << "Cantidad de dormitorios: " << dormitorios << endl;
                    cout << "Cantidad de baños: " << banios << endl;
                    cout << "Garage: ";
                    if (garage) {
                        cout << "Si" << endl;
                    } else {
                        cout << "No" << endl;
                    }
                    cout << "Direccion: " << calle << " " << numero << endl;
                    cout << "Metros edificados " << m2Edificados << endl;

                } catch (invalid_argument e) {
                    cout << "ERROR:" << e.what();
                }
                cin.get();
                break;
            default:
                cout << "Error: elija una opcion valida" << endl;
                break;
        }
    } while (op != 1 and op != 2);


}

void menuAltaPropiedad() {
    string matricula;
    string confirmacion;
    int codigoZona;
    int op;


    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ColeccionEdificios* ce = ColeccionEdificios::getInstance();

    mostrarDepartamentos();
    cout << "Elija un Departamento (Matricula) : " << endl;
    cout << endl;
    cin >> matricula;
    mostrarZonas(matricula);
    cout << "Elija una Zona (codigo)" << endl;
    cin >> codigoZona;
    try {
        cp->seleccionarZona(codigoZona);

    } catch (invalid_argument e) {
        e.what();
    }
    do {
        system("clear");

        cout << "Presione 1 si quiere ingresar una casa. Presione 2 si quiere ingresar un apartamento" << endl;
        cin >> op;
        switch (op) {
            case 1:
                menuAltaCasa(codigoZona);
                break;
            case 2:
                ce->darDataEdificios();
                do {
                    system("clear");
                    cout << "¿Quiere añadir un edificio nuevo? (Y-N)" << endl;
                    cin >> confirmacion;
                    if (confirmacion == "y" or confirmacion == "Y") {
                        menuAltaEdificio();
                    } else if (confirmacion == "n" or confirmacion == "N") {
                        menuAltaApartamento(codigoZona);
                    } else {
                        system("clear");
                        cout << "Escriba Y o N" << endl;
                    }
                } while (confirmacion != "y" and confirmacion != "n" and confirmacion != "Y" and confirmacion != "N");
                break;
            default:
                cout << "Elija una opcion valida" << endl;
                break;
                /*    cin.get();
                    cin.get();*/
        }
    } while (op != 1 and op != 2);

    cin.get();

}

void menuConsultarPropiedad() {
    string matricula;
    string confirmacion;
    ICollection* PropiedadesZ;
    InfoPropiedad* PropiedadElegida;
    int codigoZona;
    int codigoProp;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    mostrarDepartamentos();
    cout << "Elija un Departamento (Matricula) : " << endl;
    cin >> matricula;
    try {
        system("clear");

        mostrarZonas(matricula);
    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR:  " << e.what();
        cin.get();
        cin.get();
        menuConsultarPropiedad();
    }
    cout << "Elija una Zona (codigo)" << endl;
    cin >> codigoZona;
    try {
        system("clear");
        cp->seleccionarZona(codigoZona);
        PropiedadesZ = cp->listarPropsZona(codigoZona);
        imprimirDtColeccion(PropiedadesZ);
        cout << "Elija un codigo de propiedad" << endl;
        cin >> codigoProp;
        try {
            PropiedadElegida = cp->seleccionarPropiedad(codigoProp);
            system("clear");
            cout << PropiedadElegida;

            cin.get();
            cin.get();
        } catch (invalid_argument e) {
            system("clear");
            cout << "ERROR: " << e.what();
            cin.get();
            cin.get();
            menuConsultarPropiedad();
        }

    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR: " << e.what();
        cin.get();
        cin.get();
        menuConsultarPropiedad();
    }

}

void menuEliminarPropiedad() {
    int codigoProp;
    bool FueEliminada;
    ICollection* Propiedades;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    Propiedades = cp->listarProps();

    system("clear");
    imprimirDtColeccion(Propiedades);

    cout << "Elija la Propiedad a eliminar (codigo) " << endl;
    cin >> codigoProp;

    FueEliminada = cp->eliminarPropiedad(codigoProp);

    if (FueEliminada) {
        system("clear");
        cout << "La propiedad fue eliminada";
    } else {
        system("clear");
        cout << "La propiedad no existe";
    }


    cin.get();
    cin.get();

}

void menuEnviarMensajeInteresado() {
    string matriculaDep;
    int codigoZona;
    int codigoProp;
    string mensaje;
    mensaje.reserve(1000);
    ICollection* colPropiedadesZ;
    ICollection* conversacionProp;
    ControladorPropiedades* cp = ControladorPropiedades::getInstance();

    mostrarDepartamentos();
    cout << "Elija un Departamento (Matricula) : " << endl;
    cin >> matriculaDep;
    try {
        system("clear");
        mostrarZonas(matriculaDep);
        cout << "Elija una zona (Codigo):" << endl;
        cin >> codigoZona;
        try {
            colPropiedadesZ = cp->elegirZona(codigoZona);
            system("clear");
            imprimirDtColeccion(colPropiedadesZ);
            cout << "Elija la propiedad (Codigo):" << endl;
            cin >> codigoProp;
            try {

                conversacionProp = cp->elegirPropConv(codigoProp);
                if (conversacionProp == nullptr) {
                    cout << "No hay conversacion en la propiedad, comience una." << endl;
                } else {
                    imprimirDtColeccion(conversacionProp);
                }
                cout << "Ingrese un mensaje. Para indicar fin del mensaje,\n";
                cout << "utilice el caracter '|': " << endl;
                getline(cin, mensaje, '|');
                try {
                    cp->ingresarMensaje(mensaje);
                    system("clear");
                     cout << "Se ingreso el mensaje" << endl;
                } catch (invalid_argument e) {
                    cout << "ERROR: " << e.what();
                }
            } catch (invalid_argument e) {
                system("clear");
                cout << "ERROR: " << e.what();
            }
        } catch (invalid_argument e) {
            system("clear");
            cout << "ERROR: " << e.what();
        }

    } catch (invalid_argument e) {
        system("clear");
        cout << "ERROR: " << e.what();
    }
    cin.get();
    cin.get();

}

void menuSetearHora(){
    HoraSistema* horaSis = HoraSistema::getInstance();
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    system("clear");
    cout << "Ingrese dia" << endl;
    cin >> dia;
    cout << "Ingrese mes" << endl;
    cin >> mes;
    cout << "Ingrese año" << endl;
    cin >> anio;
    cout << "Ingrese hora" << endl;
    cin >> hora;
    cout << "Ingrese minutos" << endl;
    cin >> minuto;
    try{
        
     FechaYHora fecha{dia, mes, anio, hora, minuto};
     horaSis->setearFechaYHora(fecha);
    } catch(invalid_argument e){
        system("clear");
        cout << "ERROR: " << e.what();
        
    }
    cin.get();
    cin.get();          
}

void menuReporteInmobiliaria(){
        ICollection* reportes;
        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
        try {
            
        reportes = cu->obtenerReporteInmobiliarias();
        imprimirDtColeccion(reportes);
        } catch(invalid_argument e ){
            system("clear");
            cout << "ERROR: " << e.what();
        }
        
        cin.get();
        cin.get();     
    }

void menuPrincipal() {
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Sesion* ses = Sesion::getInstance();
    HoraSistema* hora = HoraSistema::getInstance();
    FechaYHora fechaS;
    
    int op = 0;
    do {
        system("clear");
        cout << "---------------------------MENU---------------------------" << endl;
        cout << "Elija la opcion deseada\n"
                "1- Iniciar Sesion \n"
                "2- Cerrar Sesion \n"
                "3- Alta Inmobiliaria \n"
                "4- Alta interesado \n"
                "5- Alta edificio \n"
                "6- Alta Propiedad \n"
                "7- Consultar Propiedad \n"
                "8- Modificar Propiedad \n"
                "9- Eliminar Propiedad \n"
                "10- Enviar Mensaje (Usuario interesado) \n"
                "11- Enviar Mensaje (Usuario inmobiliaria) \n"
                "12- Obtener Reporte de inmobiliarias \n"
                "13- Setear hora del Sistema \n"
                "14- Crear Administrador \n"
                "15- Salir \n"
                "---------------------------------------------------- \n"
         "Fecha y Hora: ";
        fechaS = hora->darFechaYHora();
        cout << fechaS.darDia() << "/"<< fechaS.darMes() << "/"  << fechaS.darAnio() << " " << fechaS.darHora() << ":"  << fechaS.darMinuto();
         cout << endl;
        cin >> op;
        switch (op) {
            default:
                system("clear");
                cout << "Ingrese una opcion valida (presione enter para continuar)" << endl;
                cin.get();
                cin.get();
                break;
            case 1:
                cu->cerrarSesion();
                menuIniciarSesion();
                break;
            case 2:
                if (ses->haySesionActiva()) {
                    cu->cerrarSesion();
                    system("clear");
                    cout << "Se ha cerrado la sesion (presione enter para continuar)";
                    cin.get();
                    cin.get();
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 3:
                if (ses->haySesionActiva()) {
                    if (cu->sesionAdmin()) {
                        menuAltaInmobiliaria();
                    } else {
                        system("clear");
                        cout << "No posee de los permisos necesarios (presione enter para continuar) " << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 4:
                if (ses->haySesionActiva()) {
                    if (cu->sesionAdmin()) {
                        menuAltaInteresado();
                    } else {
                        system("clear");
                        cout << "No posee de los permisos necesarios (presione enter para continuar) " << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                break;

            case 5:
                if (ses->haySesionActiva()) {
                    if (cu->sesionInm()) {
                        menuAltaEdificio();
                    } else {
                        system("clear");
                        cout << "No posee de los permisos necesarios (presione enter para continuar) " << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                break;

            case 6:
                if (ses->haySesionActiva()) {
                    if (cu->sesionInm()) {
                        menuAltaPropiedad();
                    } else {
                        system("clear");
                        cout << "No posee de los permisos necesarios (presione enter para continuar) " << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 7:
                if (ses->haySesionActiva()) {
                    if (cu->sesionInm() or cu->sesionInt()) {
                        menuConsultarPropiedad();
                    } else {
                        system("clear");
                        cout << "No tiene los permisos necesarios" << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay sesion activa" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 8:
                cout << "Error 404: Not Found";
                cin.get();
                cin.get();
                break;
            case 9:
                if (ses->haySesionActiva()) {
                    if (cu->sesionInm()) {
                        menuEliminarPropiedad();
                    } else {
                        system("clear");
                        cout << "No tiene los permisos necesarios" << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay sesion activa" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 10:
                if (ses->haySesionActiva()) {
                    if (cu->sesionInt()) {
                        menuEnviarMensajeInteresado();
                    } else {
                        system("clear");
                        cout << "No tiene los permisos necesarios" << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay sesion activa" << endl;
                    cin.get();
                    cin.get();
                }
                break;
            case 11:
                cout << "Error 404: not found";
                break;
            case 12:          
                if (ses->haySesionActiva()) {
                    if (cu->sesionAdmin()) {
                       menuReporteInmobiliaria();
                    } else {
                        system("clear");
                        cout << "No posee de los permisos necesarios (presione enter para continuar) " << endl;
                        cin.get();
                        cin.get();
                    }
                } else {
                    system("clear");
                    cout << "No hay ninguna sesion iniciada (presione enter para continuar)" << endl;
                    cin.get();
                    cin.get();
                }
                
                break;
            case 13:
                menuSetearHora();
                break;
            case 14:
                menuCrearAdmin();
                break;        

        }
    } while (op != 15);



}

int main() {
    string confirmacion;

    cout << "Quieres cargar los datos predefinidos? (Y/N)" << endl;

    do {
        cin >> confirmacion;
        if (confirmacion == "Y" or confirmacion == "y") {
            cargarDatosPredeterminados();
            ControladorUsuarios* cu = ControladorUsuarios::getInstance();
            cu->cerrarSesion();

            cout << "Cargados los datos predeterminados" << endl;
        } else if (confirmacion != "y" and confirmacion != "Y" and confirmacion != "N" and confirmacion != "n") {
            cout << "Ingrese Y o N" << endl;
        }

    } while (confirmacion != "y" and confirmacion != "n" and confirmacion != "Y" and confirmacion != "N");


    // altaInmPredeterminadas();
    menuPrincipal();
    /*
    agregarDepsAuto();

    altaZonasAuto();

    altaEdificiosAuto();

    altaInmPredeterminadas();

    altasOfertasPredeterminadas();

    ControladorPropiedades* cp = ControladorPropiedades::getInstance();
    ICollection* infoProps = cp->listarProps();
    imprimirDtColeccion(infoProps);

    cout << "--------------- SEPARADOR ---------------\n";
    cout << "-----------------------------------------\n\n";

    altaInterPredeterminados();

    enviarMsjsPredeterminados();

    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
     ICollection* reporteInms = cu->obtenerReporteInmobiliarias();
     imprimirDtColeccion(reporteInms);
     */
    /*
        ICollection* propsZ = cp->listarPropsZona(101);
        imprimirDtColeccion(propsZ); */

    eliminarSingletons();

    return 0;
}
