#ifndef GUERRERO_H
#define GUERRERO_H

#include <personajes.h>

class Guerrero : public Personajes{
public:
    Guerrero();
    Guerrero(const string& name);
    Guerrero(const string& name, const int atributos[],const Objetos **inventario);
    virtual void setAtributos(const int atributos[], const int tamaño);
    virtual void setAtributos();
    virtual void setInventario(const Objetos **objetos);
    virtual void Display() const;
    virtual void Ataque(Personajes& Defensor);
    virtual void Defensa(Personajes& Atacante);
    virtual string identificador();
    virtual~Guerrero();
};
#endif // GUERRERO_H
