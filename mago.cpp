#include "mago.h"

Mago::Mago() : Personajes() {_atributos.resize(6);}

Mago::Mago(const string& name) : Personajes(name) {_atributos.resize(6);}

Mago::Mago(const string& name,vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(6);}


void Mago::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}
void Mago::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}


void Mago::Display() const {
    cout<< "Mago: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Mana: "<<_atributos[5]<<endl;
}

int Mago::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
        ataque += objeto->getPower();
    }
    }
    return ataque;
}

int Mago::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0);
    return defensa;
}

void Mago::LanzarPocion(Pociones& P)
{
    if(P.getTipo()=="Salud"||P.getTipo()=="salud")
    {
        cout<< "El mago " << _name << " se ha curado " << P.getPower()<<" puntos de salud"<<endl;
        _atributos[1]+=P.getPower();
    }else if (P.getTipo()=="Mana"||P.getTipo()=="mana"||P.getTipo()=="Maná"||P.getTipo()=="maná")
    {
        cout<< "El mago " << _name << " ha restaurado  " << P.getPower()<<" puntos de maná"<<endl;
        _atributos[5]+=P.getPower();
    }else
        cout<< "Pocion no valida"<<endl;

}

void Mago::serializar(ofstream &archivo) const
{
    archivo<< "Mago: "<< endl <<_name<<" Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Mana: "<<_atributos[5]<<endl;
}
