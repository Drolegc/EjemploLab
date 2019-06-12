// DtZona.h

#ifndef DT_ZONA_H
#define DT_ZONA_H

#include <string>
using std::string;
#include "interfaces/ICollectible.h"

struct DtZona : public ICollectible {
public:
    DtZona() {}
    explicit DtZona(int codigo, string nombre);
    ~DtZona() {}

    int darCodigo();
    string darNombre();

private:
    int cod;
    string nom;
};

#endif
