#ifndef MAGO_H
#define MAGO_H
#include<personajes.h>
#include<objetos.h>

class Mago : public Personajes{
public:
    Mago();
    Mago(const string& name);
    Mago(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    virtual void setAtributos();
    virtual void setAtributos(const vector<int> atributos);
    virtual void setInventario(const vector<Objetos*> objetos);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    virtual string identificador();
    virtual~Mago();
};

#endif // MAGO_H
