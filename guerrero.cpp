#include "guerrero.h"
//#include <armas.h>

Guerrero::Guerrero() : Personajes() {_atributos.resize(7);}

Guerrero::Guerrero(const string& name) : Personajes(name) {_atributos.resize(7);}

Guerrero::Guerrero(const string& name, vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}




void Guerrero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Guerrero::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}

void Guerrero::Display() const {
    cout<< "Guerrero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Fuerza: "<<_atributos[6]<<" Escudo: "<<_atributos[5]<<endl;
}

int Guerrero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0)+getAtributos(5);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
        ataque += objeto->getPower();
        }
    }
    return ataque;
}

int Guerrero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+getAtributos(6);
    return defensa;
}

void Guerrero::serializar(ofstream &archivo) const
{
    archivo<< "Guerrero "<<_name<<" Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Fuerza: "<<_atributos[6]<<" Escudo: "<<_atributos[5]<<endl;
}
