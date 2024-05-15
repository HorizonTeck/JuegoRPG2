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
    //Constructores
    Personajes();
    Personajes(const string& name);
    Personajes(const string& name, const vector<int> atributos,const vector<Objetos*> inventario);
    Personajes(Personajes* P);

    //Gestion de variables basicas
    string getName() const;
    void setName(const string& name);

    //Gestion de atributos
    vector<int> getAtributos() const;
    int getAtributos(int atrib);
    virtual void setAtributos(const vector<int> atributos)=0;
    virtual void setAtributos(int atrib, int posicion) =0;

    //Gestion Inventario
    vector<Objetos*>& getInventario();
    void setInventario(Objetos* Objeto);
    virtual bool comprobarInventario(Objetos* objeto)=0;
    virtual bool comprobarInventario()=0;
    friend Personajes& operator>>(Personajes& P, Objetos& O);

    //Gestion Display
    virtual ostream& Display(ostream& os) =0;
    virtual void Display() const =0; //Display
    friend ostream& operator<<(ostream& os, Personajes& P);

    //Funciones varias
    int tirar_dados() const;
    virtual int Ataque() =0;
    virtual int Defensa() =0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Personajes();
};
#endif // PERSONAJES_H
