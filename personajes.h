#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <iostream>
#include <objetos.h>
using namespace std;

class Personajes{
protected:
    string _name;
    int _atributos[7]; //Nivel, Salud, Poder, Precisión, Proteccion, especial1 y especial2
    Objetos* _inventario[4];
public:
    Personajes();
    Personajes(const string& name);
    Personajes(const string& name, const int atributos[],const Objetos **inventario);
    string getName() const;
    const int* getAtributos() const;
    const Objetos* const* getInventario() const;
    void setName(const string& name);
    virtual void setAtributos(const int atributos[], const int tamaño) =0;
    virtual void setAtributos() =0;
    virtual void setInventario(const Objetos* objetos[]) =0;
    int tirar_dados() const;
    virtual void Display() const =0; //Display
    virtual void Ataque(Personajes& Defensor) =0;
    virtual void Defensa(Personajes& Atacante) =0;
    virtual string identificador() =0;
    virtual~Personajes();
};
#endif // PERSONAJES_H

//hola buenas tardes
//ADIOS
