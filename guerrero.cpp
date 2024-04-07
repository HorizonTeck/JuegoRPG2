#include "guerrero.h"

Guerrero::Guerrero() : Personajes() {_atributos.resize(7);}

Guerrero::Guerrero(const string& name) : Personajes(name) {_atributos.resize(7);}

Guerrero::Guerrero(const string& name, vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}



void Guerrero::setAtributos(){
    srand(static_cast<unsigned int>(time(nullptr)));
    _atributos[0]=0; //nivel
    _atributos[1]=0 + rand() % (100-0+1); //salud
    _atributos[2]=0 + rand() % (30-0+1); //poder
    _atributos[3]=1 + rand() % (12-1+1); //precisión
    _atributos[4]=15 + rand() % (30-15+1); //protección
    _atributos[5]=1 + rand() % (15-1+1); //fuerza
    _atributos[6]=0+ rand() % (30-0+1); //escudo
}

void Guerrero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Guerrero::setInventario(vector<Objetos*> objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Guerrero::Display() const {
    cout<< " Guerrero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Fuerza: "<<_atributos[5]<<" Escudo: "<<_atributos[6]<<endl;
}

int Guerrero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0)+getAtributos(5);//FALTA LAS ARMAS
    return ataque;
}

int Guerrero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+getAtributos(6);
    return defensa;
}

string Guerrero::identificador(){
    return "Guerrero";
}
Guerrero::~Guerrero() {

}
