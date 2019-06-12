// Interesado.h

#ifndef INTERESADO_H
#define INTERESADO_H

#include <string>
using std::string;

#include "Usuario.h"
#include "interfaces/ICollection.h"

class Conversa;

class Interesado : public Usuario {
public:
    Interesado() {}
    explicit Interesado(string email, int edad, string nombre, string apellido);
    Interesado(const Interesado&) = delete;
    Interesado& operator=(const Interesado&) = delete;
    ~Interesado();

    int darEdad();
    string darNombre();
    string darApellido();

    void agregarConversa(Conversa* c);

private:
    int ed;
    string nom;
    string ape;
    ICollection* conversas;
};

#include "Conversa.h"

#endif
