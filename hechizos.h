#ifndef HECHIZOS_H
#define HECHIZOS_H

#include <iostream>
#include <personajes.h>
using namespace std;

class Hechizos
{
private:
    string _TipoHechizo;
    int _coste;
    string _nombre;
public:
    Hechizos();
    Hechizos(const int& coste,const string& TipoHechizo,const string& nombre);
    string getTipoHechizo() const;
    int getCoste() const;
    void setCoste();
    void setCoste(const int& coste);
    void setTipoHechizo(const string& TipoHechizo);
   // void LanzarHechizo(Personajes* Defensor, Personajes* Atacante);
    friend ostream& operator<<(ostream& os, Hechizos& O);
    //void Display(ostream& os);
    void Display();
    void setName(const string& nombre);
    string getName();
    ~Hechizos();

};

#endif // HECHIZOS_H
