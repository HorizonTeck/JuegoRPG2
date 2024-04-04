#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <vector>
#include <objetos.h>
using namespace std;

class Personajes{
protected:
    string _name;
    vector<int> _atributos; //Nivel, Salud, Poder, Precisión, Proteccion, especial1 y especial2
    vector<Objetos*> _inventario;
public:
    Personajes();
    Personajes(const string& name);
    Personajes(const string& name, const int atributos[],const Objetos **inventario);
    string getName() const;
    vector<int> getAtributos() const;
    vector<Objetos*> getInventario() const;
    void setName(const string& name);
    virtual void setAtributos(const int atributos[], const int tamaño) =0;
    virtual void setAtributos() =0;
    virtual void setInventario(const Objetos* objetos[]) =0;
    int tirar_dados() const;
    virtual void Display() const =0; //Display
    virtual int Ataque() =0;
    virtual int Defensa() =0;
    virtual string identificador() =0;
    virtual~Personajes();
};
#endif // PERSONAJES_H
