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

void Hechizos::LanzarHechizo(Personajes& Defensor, Mago& Atacante)
{
    //agua (restaura la salud de los compañeros), fuego (resta salud a los enemigos), tierra (debilita la protección de los enemigos) y aire (resta poder a los enemigos)
    if (_TipoHechizo == "Agua"||_TipoHechizo == "agua") {
        Defensor.setAtributos(100,1);
        Atacante.setAtributos(Atacante.getAtributos(5)-_coste,5);
    } else if (_TipoHechizo == "Fuego"||_TipoHechizo == "fuego") {
        Defensor.setAtributos(Defensor.getAtributos(1)-20,1);
        Atacante.setAtributos(Atacante.getAtributos(5)-_coste,5);
    } else if (_TipoHechizo == "Tierra"||_TipoHechizo == "tierra") {
        Defensor.setAtributos(Defensor.getAtributos(4)-7,4);
        Atacante.setAtributos(Atacante.getAtributos(5)-_coste,5);
    } else if(_TipoHechizo == "Aire"||_TipoHechizo == "aire")
    {
        Defensor.setAtributos(Defensor.getAtributos(2)-7,2);
        Atacante.setAtributos(Atacante.getAtributos(5)-_coste,5);
    }else
        cout<< "Hechizo no encontrado"<<endl;

}
string Hechizos::getName()
{
    return _nombre;
}
void Hechizos::setName(const string& nombre)
{
    _nombre = nombre;
}
void Hechizos::Display()
{
    cout << "Hechizo: " << getName() << " Tipo: " << getTipoHechizo() << " Coste: " << getCoste() << endl;
}
