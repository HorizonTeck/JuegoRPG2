#ifndef GUERRERO_H
#define GUERRERO_H

#include "personajes.h"

class Guerrero : public Personajes{
public:
    Guerrero();
    Guerrero(const string& name);
    Guerrero(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    Guerrero(Guerrero& Guerrero);
    virtual void setAtributos(const vector<int> atributos);
    virtual void setAtributos(int atrib, int posicion);
    virtual bool comprobarInventario(Objetos* objeto);
    virtual bool comprobarInventario();
    virtual ostream& Display(ostream& os);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    void LanzarPocion(Pociones& P);
    virtual void serializar(ofstream& archivo) const;
};
#endif // GUERRERO_H
