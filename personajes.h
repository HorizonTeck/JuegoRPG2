#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <vector>
#include <armas.h>
#include <pociones.h>
#include <hechizos.h>
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
    friend bool operator++(Personajes& Personaje);

    //Gestion Inventario
    vector<Objetos*>& getInventario();
    void setInventario(Objetos* Objeto);
    virtual bool comprobarInventario(Objetos* objeto)=0;
    virtual bool comprobarInventario()=0;
    Personajes& operator>>(Objetos* Hechizo);
    int NumPociones();

    //Gestion Display
    virtual ostream& Display(ostream& os) =0;
    virtual void Display() const =0;
    friend ostream& operator<<(ostream& os, Personajes& P);
    virtual void DisplayAtaque() const =0;

    //Funciones varias
    int tirar_dados() const;
    virtual int Ataque() =0;
    virtual int Defensa() =0;
    virtual bool LanzarPocion(Pociones* P)=0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Personajes();
};
#endif // PERSONAJES_H
