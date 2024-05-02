#ifndef MAGO_H
#define MAGO_H

#include "personajes.h"

class Mago : public Personajes{
public:
    Mago();
    Mago(const string& name);
    Mago(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    virtual void setAtributos(int atrib, int posicion);
    virtual void setAtributos(const vector<int> atributos);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    void LanzarPocion(Pociones& P);
    //virtual string identificador();
    virtual void serializar(ofstream& archivo) const;
};

#endif // MAGO_H
