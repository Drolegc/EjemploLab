// ControladorUsuarios.cpp

#include <stdexcept>
#include "ControladorUsuarios.h"
#include "interfaces/IIterator.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"
#include "Sesion.h"
#include "StringKey.h"
#include "Administrador.h"
#include "Interesado.h"
#include "Inmobiliaria.h"

ControladorUsuarios* ControladorUsuarios::instance {nullptr};



ControladorUsuarios::ControladorUsuarios()
{
    usuarios = new OrderedDictionary();
}



ControladorUsuarios* ControladorUsuarios::getInstance()
{
    if (instance == nullptr)
        instance = new ControladorUsuarios();
    return instance;
}



/* Elimina el controlador junto con todos los usuarios
 y las claves de la coleccion. Las claves son eliminadas
 en el destructor del diccionario mismo, mientras
 que cada usuario debe ser eliminado de manera independiente */
ControladorUsuarios::~ControladorUsuarios()
{
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete usuarios;
    instance = nullptr;
}



bool ControladorUsuarios::ingresarEmail(string email)
{
    bool res {false};
    StringKey* sk = new StringKey {email};
    if (usuarios->member(sk)) {
        emailGuardado = email;
        res = true;
    }
    delete sk;
    return res;
}



void ControladorUsuarios::asignarSesion(Usuario* u)
{
    Sesion* s = Sesion::getInstance();
    s->asignarSesion(u);
    emailGuardado = "";
    contraseniaGuardada = "";
}



bool ControladorUsuarios::ingresarContrasenia(string contrasenia)
{
    bool res {false};
    StringKey* sk = new StringKey {emailGuardado};
    if (usuarios->member(sk)) {
        Usuario* u = dynamic_cast<Usuario*>(usuarios->find(sk));
        if (u->confDeContra(contrasenia)) {
            asignarSesion(u);
            res = true;
        }
    }
    delete sk;
    return res;
}



void ControladorUsuarios::liberarMemoria()
{
    Direccion vacia;
    emailGuardado = "";
    contraseniaGuardada = "";
    nombreGuardado = "";
    direccionGuardada = vacia;
}



/* Esta operacion corresponde a cerrarSistema y cancelarAI
 de laboratorios previos */
void ControladorUsuarios::cancelar()
{
    liberarMemoria();
}



void ControladorUsuarios::registrarContrasenia(string contrasenia)
{
    contraseniaGuardada = contrasenia;
}



/* Si las contrasenias ingresadas coinciden,
 asigna esa contrasenia y la sesion al usuario */
bool ControladorUsuarios::ingrVerifiContrasenia(string contrasenia)
{
    bool res {false};
    if (contrasenia == contraseniaGuardada) {
        StringKey* sk = new StringKey {emailGuardado};
        if (usuarios->member(sk)) {
            Usuario* u = dynamic_cast<Usuario*>(usuarios->find(sk));
            u->modificarContrasenia(contrasenia);
            asignarSesion(u);
            res = true;
            contraseniaGuardada = "";
            delete sk;
        }
    }
    return res;
}



/* Precondicion: Existe un usuario de email 'email'
   Postcondicion: Devuelve 'true' si es la primera vez
   que el usuario inicia sesion, y 'false' en caso contrario */
bool ControladorUsuarios::esPrimeraSesion(string email)
{
    bool res {false};
    StringKey* sk = new StringKey {email};
    if (usuarios->member(sk)) {
        Usuario* u = dynamic_cast<Usuario*>(usuarios->find(sk));
        if (u && (u->darContrasenia().empty()))
            res = true;
    }
    else {
        delete sk;
        throw std::invalid_argument("No existe usuario con ese email");
    }
    delete sk;
    return res;
}


void ControladorUsuarios::cerrarSesion()
{
    Sesion* s = Sesion::getInstance();
    s->desvincularUsuario();
}


bool ControladorUsuarios::sesionAdmin()
{
    bool res {false};
    Sesion* s = Sesion::getInstance();
    Administrador* admin = dynamic_cast<Administrador*>(s->darUsuario());
    if (admin)
        res = true;
    return res;
}



bool ControladorUsuarios::sesionInm()
{
    bool res {false};
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(s->darUsuario());
    if (inm)
        res = true;
    return res;
}



bool ControladorUsuarios::sesionInt()
{
    bool res {false};
    Sesion* s = Sesion::getInstance();
    Interesado* inter = dynamic_cast<Interesado*>(s->darUsuario());
    if (inter)
        res = true;
    return res;
}



void ControladorUsuarios::agregarUsuario(Usuario* u)
{
    StringKey* sk = new StringKey {u->darEmail()};
    usuarios->add(sk, u);
}



void ControladorUsuarios::removerUsuario(Usuario* u)
{
    StringKey* sk = new StringKey {u->darEmail()};
    usuarios->remove(sk);
    delete sk;
}



void ControladorUsuarios::verificarUnicidadEmail(string email)
{
    StringKey* sk = new StringKey {email};
    bool existeUsuario {usuarios->member(sk)};
    delete sk;
    if (existeUsuario)
        throw std::invalid_argument("Ese email ya esta en uso");
}



void ControladorUsuarios::chequearNombreInmob(string nombre)
{
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Inmobiliaria* inmob = dynamic_cast<Inmobiliaria*>(it->getCurrent());
        if (inmob && (inmob->darNombre() == nombre)) {
            delete it;
            throw std::invalid_argument("Ese nombre ya esta en uso");
        }
        it->next();

    }
    delete it; 
}



void ControladorUsuarios::crearAdministrador(string email, string contrasenia)
{
    verificarUnicidadEmail(email);
    Administrador* admin = new Administrador(email, contrasenia);
    agregarUsuario(admin);
}



void ControladorUsuarios::altaInteresado(string nombre, string apellido,
                                        int edad, string email)
{
    verificarUnicidadEmail(email);
    Interesado* inter = new Interesado(email, edad, nombre, apellido);
    agregarUsuario(inter);
}



void ControladorUsuarios::altaInmobiliaria(string nombre, Direccion direccion,
                                           string email)
{
    verificarUnicidadEmail(email);
    chequearNombreInmob(nombre);
    nombreGuardado = nombre;
    direccionGuardada = direccion;
    emailGuardado = email;
}



void ControladorUsuarios::aceptarAltaInmob()
{
    Inmobiliaria* inmob = new Inmobiliaria {emailGuardado, nombreGuardado,
                                            direccionGuardada};
    agregarUsuario(inmob);
    liberarMemoria();
}



bool ControladorUsuarios::existeUsuario(string email)
{
    bool res {false};
    StringKey* clave = new StringKey {email};
    res = usuarios->member(clave);
    delete clave;
    return res;
}


/* Retorna una coleccion de DtReporteInm con los reportes de todas
las inmobiliarias del sistema */
ICollection* ControladorUsuarios::obtenerReporteInmobiliarias()
{
    ICollection* res = new List();
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Inmobiliaria* ptrInm = dynamic_cast<Inmobiliaria*>(it->getCurrent());
        if (ptrInm) {
            ICollectible* reporteInm = ptrInm->darReporteCompleto();
            res->add(reporteInm);
        }
        it->next();
    }
    delete it;
    return res;
}
