#include "arquero.h"
#include <armas.h>

Arquero::Arquero() : Personajes() {_atributos.resize(7);}

Arquero::Arquero(const string& name) : Personajes(name) {_atributos.resize(7);}

Arquero::Arquero(const string& name, vector<int> atributos, vector <Objetos*> inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}



void Arquero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Arquero::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}


void Arquero::Display() const {
    cout<< "Arquero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Agilidad: "<<_atributos[5]<<" Carcaj: "<<_atributos[6]<<endl;
}

int Arquero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
        ataque= ataque+ objeto->getPower()/getAtributos(6);
    }
    }
    return ataque;
}

int Arquero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+2*getAtributos(5);
    return defensa;
}

void Arquero::serializar(ofstream& archivo) const
{
    archivo<< "Arquero: "<< endl <<_name<<" Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Agilidad: "<<_atributos[5]<<" Carcaj: "<<_atributos[6]<<endl;
}


void Arquero::LanzarPocion(Pociones &P)
{
    if(P.getTipo()=="Salud"||P.getTipo()=="salud")
    {
        cout<< "El arquero " << _name << " se ha curado " << P.getPower()<<" puntos de salud"<<endl;
        _atributos[1]+=P.getPower();
    }else if (P.getTipo()=="Mana"||P.getTipo()=="mana"||P.getTipo()=="Maná"||P.getTipo()=="maná")
    {
        cout<< "El arquero " << _name << " no ha sido capaz de lanzar la pocion"<<endl;
    }else
        cout<< "Pocion no valida"<<endl;
}
