// Interesado.cpp

#include "Interesado.h"
#include "collections/List.h"

Interesado::Interesado(string email, int edad, string nombre, string apellido)
                     : Usuario(email), nom {nombre}, ape {apellido}
{
    ed = edad;
    conversas = new List();
}

int Interesado::darEdad()
{
    return ed;
}

string Interesado::darNombre()
{
    return nom;
}

string Interesado::darApellido()
{
    return ape;
}

void Interesado::agregarConversa(Conversa* c)
{
    conversas->add(c);
}

Interesado::~Interesado()
{
    // La Propiedad es quien se encarga de eliminar cada Conversa 
    delete conversas;
}
