#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <equipo.h>
#include <list>

class Graveyard: public Equipo
{
private:
    list <Personajes*> Personajes_muertos;

public:
    Graveyard();
    void set_Muertos(vector <Personajes*> Muertos);
    list <Personajes*> get_Muertos() const;
    int get_NumMuertos() const;
    void Display();
};

#endif // GRAVEYARD_H
