#include "graveyard.h"

Graveyard::Graveyard()
{

}

void Graveyard::set_Muertos(vector<Personajes *> Muertos)
{
   list <Personajes*> tmp (Muertos.begin(),Muertos.end());
   Personajes_muertos=tmp;
}

void Graveyard::Display()
{
    for (auto objeto: Personajes_muertos)
    {
        cout<<objeto;
    }
}

list <Personajes*> Graveyard::get_Muertos() const
{
    return Personajes_muertos;
}

int Graveyard::get_NumMuertos() const
{
    return static_cast <int>(Personajes_muertos.size());
}
