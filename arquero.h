#ifndef ARQUERO_H
#define ARQUERO_H

#include "personajes.h"

class Arquero : public Personajes{
public:
    Arquero ();
    Arquero(const string& name);
    Arquero(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    Arquero(Arquero& Arquero);
    virtual void setAtributos(int atrib, int posicion);
    virtual void setAtributos(const vector<int> atributos);
    virtual bool comprobarInventario(Objetos* objeto);
    virtual bool comprobarInventario();
    virtual ostream& Display(ostream& os);
    virtual void Display() const;
    virtual void DisplayAtaque() const;
    virtual int Ataque();
    virtual int Defensa();
    virtual void LanzarPocion(Pociones* P);
    virtual void serializar(ofstream& archivo) const;
    virtual~Arquero();
};

#endif // ARQUERO_H
