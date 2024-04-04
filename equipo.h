#ifndef EQUIPO_H
#define EQUIPO_H

#include <personajes.h>
#include <guerrero.h>

class Equipo{
private:
    string _name;
    int _tamaño;
    vector<Personajes*> _Lista_Personajes;
public:
    Equipo();
    Equipo(const string& name,const int& n);
    string getName() const;
    Personajes** getLista_Personajes() const;
    Personajes* getLista_Personajes(int n) const;
    void setName(const string& name);
    void setLista_Personajes(Personajes **lista);
    void display() const;
    ~Equipo();
};

#endif // EQUIPO_H
