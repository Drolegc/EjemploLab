// DtDepartamento.h

#ifndef DT_DEPARTAMENTO_H
#define DT_DEPARTAMENTO_H

#include <string>
using std::string;
#include "interfaces/ICollectible.h"

struct DtDepartamento : public ICollectible {
public:
    DtDepartamento() {}
    explicit DtDepartamento(string matricula, string nombre);
    ~DtDepartamento() {}

    string darMatricula();
    string darNombre();

private:
    string mat;
    string nom;
};

#endif
