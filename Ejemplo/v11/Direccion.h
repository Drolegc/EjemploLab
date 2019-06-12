// Direccion.h

#ifndef DIRECCION_H
#define DIRECCION_H

#include <string>
using std::string;

struct Direccion {
public:
    Direccion() {}
    explicit Direccion(string calle, string numero);
    ~Direccion() {}

    string darCalle();
    string darNumero();

private:
    string c;
    string n;   
};

#endif
