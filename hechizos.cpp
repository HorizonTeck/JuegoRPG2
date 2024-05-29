#include "hechizos.h"


Hechizos::Hechizos(){}

Hechizos::Hechizos(const int& coste,const string& TipoHechizo,const string& nombre)
{
    _TipoHechizo=TipoHechizo;
    _coste=coste;
    _nombre=nombre;
}
string Hechizos::getTipoHechizo() const{
    return _TipoHechizo;
}
void Hechizos::setCoste()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    _coste=0+ rand() % (15-0+1);
}
int Hechizos::getCoste() const
{
    return _coste;
}

void Hechizos::setCoste(const int& coste)
{
    _coste=coste;
}

void Hechizos::setTipoHechizo(const string& TipoHechizo)
{
    _TipoHechizo=TipoHechizo;
}


string Hechizos::getName()
{
    return _nombre;
}
void Hechizos::setName(const string& nombre)
{
    _nombre = nombre;
}
ostream& operator<<(ostream& os, Hechizos& Hechizo){
    os << amarillo<<BLUE<<"Hechizo: " << Hechizo._nombre << " Tipo: " << Hechizo._TipoHechizo << " Coste: " << Hechizo._coste << endl<<RESET;
    return os;
}
void Hechizos::Display()
{
    cout << amarillo<<BLUE<< "Hechizo: " << getName() << " Tipo: " << getTipoHechizo() << " Coste: " << getCoste() << endl<<RESET;
}
Hechizos::~Hechizos(){}
