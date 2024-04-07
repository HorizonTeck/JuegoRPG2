#ifndef HECHIZOS_H
#define HECHIZOS_H
#include<mago.h>

class Hechizos
{
private:
    string _TipoHechizo;
    int _coste;
public:
    Hechizos();
    Hechizos(const int& coste,const string& TipoHechizo);
    void LanzarHechizo(Personajes& Defensor, Mago* Atacante);
    void display();

};

#endif // HECHIZOS_H
