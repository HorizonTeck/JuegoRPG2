#include "arquero.h"

Arquero::Arquero() : Personajes() {_atributos.resize(7);}

Arquero::Arquero(const string& name) : Personajes(name) {_atributos.resize(7);}

Arquero::Arquero(const string& name, vector<int> atributos, vector <Objetos*> inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}


void Arquero::setAtributos(){
    srand(static_cast<unsigned int>(time(nullptr)));
    _atributos[0]=0; //nivel
    _atributos[1]=0 + rand() % (100-0+1); //salud
    _atributos[2]=0 + rand() % (30-0+1); //poder
    _atributos[3]=1 + rand() % (12-1+1); //precisión
    _atributos[4]=15 + rand() % (30-15+1); //protección
    _atributos[5]=1 + rand() % (15-1+1); //agilidad
    _atributos[6]=0 + rand() % (30-0+1); //carcaj
}

void Arquero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Arquero::setInventario(vector<Objetos*> objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Arquero::Display() const {
    cout<< " Arquero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Fuerza: "<<_atributos[5]<<" Escudo: "<<_atributos[6]<<endl;
}

int Arquero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);//FALTA LAS ARMAS Y FLECHAS
    return ataque;
}

int Arquero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+2*getAtributos(5);
    return defensa;
}

string Arquero::identificador(){
    return "Arquero";
}
Arquero::~Arquero() {

}
