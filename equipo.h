#ifndef EQUIPO_H
#define EQUIPO_H

#include "mago.h"
#include "arquero.h"
#include "guerrero.h"
class Equipo{
private:
    string _name;
    vector<Personajes*> _Lista_Personajes;
    int _dinero;
public:
    Equipo();
    Equipo(const string& name);
    Equipo(const string& name, int dinero);
    Equipo(Equipo& Equipo);
    string getName() const;
    vector<Personajes*>& getLista_Personajes();
    Personajes* getLista_Personajes(int n) const;
    void setName(const string& name);
    int getDinero();
    void setDinero(int dinero);
    void setLista_Personajes(vector<Personajes*> lista);
    void setLista_Personajes(Personajes*);
    int gettamano();
    void borrarPersonaje(int n);
    friend ostream& operator<<(ostream& os, Equipo& E);
    Equipo& operator>>(Personajes* P);
    void Display() const;
    ~Equipo();
};

#endif // EQUIPO_H
