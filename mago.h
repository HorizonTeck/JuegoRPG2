#ifndef MAGO_H
#define MAGO_H

#include "personajes.h"

class Mago : public Personajes{
private:
    vector<Hechizos*> _hechizos;
public:
    Mago();
    Mago(const string& name);
    Mago(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    Mago(const string& name, int nivel, int salud,int poder, int precision, int proteccion, int mana);
    Mago(Mago& Mago);
    virtual void setAtributos(int atrib, int posicion);
    virtual void setAtributos(const vector<int> atributos);
    virtual bool comprobarInventario(Objetos* objeto);
    virtual bool comprobarInventario();
    vector<Hechizos*>& getHechizos();
    void setHechizos(Hechizos* Hechizo);
    bool comprobarHechizos();
    bool comprobarBaculo();
    virtual ostream& Display(ostream& os);
    virtual void Display() const;
    virtual void DisplayAtaque() const;
    virtual int Ataque();
    virtual int Defensa();
    virtual bool LanzarPocion(Pociones* P);
    virtual void serializar(ofstream& archivo) const;
    Mago& operator>>(Hechizos* Hechizo);
    virtual~Mago();
};

#endif // MAGO_H
