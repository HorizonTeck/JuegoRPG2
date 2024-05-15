#ifndef MAGO_H
#define MAGO_H

#include "personajes.h"
#include "hechizos.h"

class Mago : public Personajes{
private:
    vector<Hechizos*> _hechizos;
public:
    Mago();
    Mago(const string& name);
    Mago(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    Mago(Mago& Mago);
    virtual void setAtributos(int atrib, int posicion);
    virtual void setAtributos(const vector<int> atributos);
    virtual bool comprobarInventario(Objetos* objeto);
    virtual bool comprobarInventario();
    vector<Hechizos*> getHechizos();
    void setHechizos(Hechizos* Hechizo);
    virtual ostream& Display(ostream& os);
    virtual void Display() const;
    virtual int Ataque();
    virtual int Defensa();
    void LanzarPocion(Pociones& P);
    virtual void serializar(ofstream& archivo) const;
};

#endif // MAGO_H
