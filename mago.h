#ifndef MAGO_H
#define MAGO_H
#include<personajes.h>
#include<objetos.h>

class Mago : public Personajes{
public:
    Mago();
    Mago(const string& name);
    Mago(const string& name, const int atributos[],const Objetos **inventario);
    virtual void setAtributos(const int atributos[], const int tamaño);
    virtual void setAtributos();
    virtual void setInventario(const Objetos **objetos);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    virtual string identificador();
    virtual~Mago();
};

#endif // MAGO_H
