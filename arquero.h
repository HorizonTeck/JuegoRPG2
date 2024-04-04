#ifndef ARQUERO_H
#define ARQUERO_H
#include<personajes.h>
#include<objetos.h>

class Arquero : public Personajes{
public:
    Arquero ();
    Arquero(const string& name);
    Arquero(const string& name, const int atributos[],const Objetos **inventario);
    virtual void setAtributos(const int atributos[], const int tamaño);
    virtual void setAtributos();
    virtual void setInventario(const Objetos **objetos);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    virtual string identificador();
    virtual~Arquero();
};

#endif // ARQUERO_H
