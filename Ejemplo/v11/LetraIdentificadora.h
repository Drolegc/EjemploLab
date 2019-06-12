// LetraIdentificadora.h

#ifndef LETRAIDENTIFICADORA_H
#define LETRAIDENTIFICADORA_H

#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"

struct LetraIdentificadora : public ICollectible, public OrderedKey {
public:
    LetraIdentificadora(char letra);
    
    ComparisonRes compare(OrderedKey* k) const;

    virtual ~LetraIdentificadora() {}
private:
    char letraId;
};

#endif
