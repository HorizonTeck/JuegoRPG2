#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <vector>
#include <objetos.h>
#include <armas.h>
#include <pociones.h>
using namespace std;

class Personajes{
protected:
    string _name;
    vector<int> _atributos; //Nivel, Salud, Poder, Precisión, Proteccion, especial1 y especial2
    vector<Objetos*> _inventario;
public:
    Personajes();
    Personajes(const string& name);
    Personajes(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    string getName() const;
    vector<int> getAtributos() const;
    int getAtributos(int atrib);
    vector<Objetos*> getInventario() const;
    void setName(const string& name);
    virtual void setAtributos(const vector<int> atributos)=0;
    virtual void setAtributos(int atrib, int posicion) =0;
    virtual void setInventario(Objetos* Objeto);
    virtual bool comprobarInventario(Objetos* objeto)=0;
    virtual bool comprobarInventario()=0;
    int tirar_dados() const;
    virtual void Display() const =0; //Display
    virtual int Ataque() =0;
    virtual int Defensa() =0;
    //virtual string identificador() =0;
    virtual~Personajes();
    virtual void serializar(ofstream& archivo) const =0;
};
#endif // PERSONAJES_H
