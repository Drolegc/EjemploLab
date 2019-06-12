// LetraIdentificadora.cpp

#include <stdexcept>
#include "LetraIdentificadora.h"

LetraIdentificadora::LetraIdentificadora(char letra)
{
    letraId = letra;
}

ComparisonRes LetraIdentificadora::compare(OrderedKey* k) const
{
    LetraIdentificadora* li = dynamic_cast<LetraIdentificadora*>(k); 
    if (li == nullptr)
        throw std::invalid_argument("Invalid key k");

    if (letraId == li->letraId)
        return EQUAL;
    else if (letraId > li->letraId)
        return GREATER;
    else
        return LESSER;
}
