#include "mago.h"

Mago::Mago() : Personajes() {}

Mago::Mago(const string& name) : Personajes(name) {}

Mago::Mago(const string& name,vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {}

void Mago::setAtributos(vector<int> atributos, const int tamaño) {
    for(int i=0;i<tamaño;i++){
        this->_atributos[i] = atributos[i];
    }
    //se puede quitar tamaño y poner 6 quizá
}

void Mago::setAtributos(){
    srand(static_cast<unsigned int>(time(nullptr)));
    _atributos[0] = 0; //nivel
    _atributos[1] = 0 + rand() % (100-0+1); //salud
    _atributos[2] = 0 + rand() % (30-0+1); //poder
    _atributos[3] = 1 + rand() % (12-1+1); //precisión
    _atributos[4] = 15 + rand() % (30-15+1); //protección
    _atributos[5] = 1 + rand() % (15-1+1); //mana
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
    vector<int> atributos ;
    atributos = getAtributos();
    int ataque=0;
    ataque = atributos[2]*atributos[0];//FALTA LAS ARMAS
    return ataque;
}

int Mago::Defensa() {
    vector<int> atributos ;
    atributos = getAtributos();
    int defensa=0;
    defensa = atributos[4]*atributos[0];
    return defensa;
}

string Mago::identificador(){
    return "Mago";
}

Mago::~Mago() {

}
