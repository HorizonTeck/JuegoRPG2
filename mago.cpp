#include "mago.h"

Mago::Mago() : Personajes() {_atributos.resize(6);}

Mago::Mago(const string& name) : Personajes(name) {_atributos.resize(6);}

Mago::Mago(const string& name,vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(6);}

void Mago::setAtributos(){
    srand(static_cast<unsigned int>(time(nullptr)));
    _atributos[0]=0; //nivel
    _atributos[1]=0 + rand() % (100-0+1); //salud
    _atributos[2]=0 + rand() % (30-0+1); //poder
    _atributos[3]=1 + rand() % (12-1+1); //precisión
    _atributos[4]=15 + rand() % (30-15+1); //protección
    _atributos[5]=1 + rand() % (15-1+1); //mana
}
void Mago::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}
void Mago::setAtributos(int atrib, int posicion) {
    if(posicion<=5)
    {
        _atributos[posicion]=atrib;
    }else
        cout<< "Posicion no encontrada"<<endl;
}

void Mago::setInventario(vector<Objetos*> objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Mago::Display() const {
    cout<< " Mago: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Mana: "<<_atributos[5]<<endl;
}

int Mago::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);//FALTA LAS ARMAS
    return ataque;
}

int Mago::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0);
    return defensa;
}

string Mago::identificador(){
    return "Mago";
}

Mago::~Mago() {

}
