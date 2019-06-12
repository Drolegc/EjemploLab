// Usuario.h

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using std::string;

#include "interfaces/ICollectible.h"

class Usuario : public ICollectible {
public:
    Usuario() {}
    Usuario(string email);
    Usuario(string email, string contrasenia);
    Usuario(const Usuario&) = delete;
    Usuario& operator=(const Usuario&) = delete;
    virtual ~Usuario() {}

    bool confDeContra(string contrasenia);

    void modificarContrasenia(string contrasenia);
    string darEmail();
    string darContrasenia();

private:
    string e;
    string contra; 
};

#endif
