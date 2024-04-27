#ifndef EQUIPO_H
#define EQUIPO_H

#include <personajes.h>
#include <guerrero.h>

class Equipo{
private:
    string _name;
    vector<Personajes*> _Lista_Personajes;
public:
    Equipo();
    Equipo(const string& name);
    string getName() const;
    vector<Personajes*> getLista_Personajes() const;
    Personajes* getLista_Personajes(int n) const;
    void setName(const string& name);
    void setLista_Personajes(vector<Personajes*> lista);
    void setLista_Personajes(Personajes*);
    int gettamaño();
    void borrarPersonaje(int n);
    void display() const;
    ~Equipo();
};

#endif // EQUIPO_H
