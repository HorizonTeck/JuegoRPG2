#include "guerrero.h"

Guerrero::Guerrero() : Personajes() {}

Guerrero::Guerrero(const string& name) : Personajes(name) {}

Guerrero::Guerrero(const string& name, const int atributos[], const Objetos** inventario) : Personajes(name, atributos, inventario) {}

void Guerrero::setAtributos(const int atributos[], const int tamaño) {
    for(int i=0;i<tamaño;i++){
        this->_atributos[i] = atributos[i];
    }
    //se puede quitar tamaño y poner 6 quizá
}

void Guerrero::setAtributos(){
    srand(static_cast<unsigned int>(time(nullptr)));
    _atributos[0] = 0; //nivel
    _atributos[1] = 0 + rand() % (100-0+1); //salud
    _atributos[2] = 0 + rand() % (30-0+1); //poder
    _atributos[3] = 1 + rand() % (12-1+1); //precisión
    _atributos[4] = 15 + rand() % (30-15+1); //protección
    _atributos[5] = 1 + rand() % (15-1+1); //fuerza
    _atributos[6] = 0 + rand() % (30-0+1); //escudo
}

void Guerrero::setInventario(const Objetos **objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Guerrero::Display() const {
    cout<< " Guerrero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Fuerza: "<<_atributos[5]<<" Escudo: "<<_atributos[6]<<endl;
}

void Guerrero::Ataque(Personajes& Defensor) {

}

void Guerrero::Defensa(Personajes& Atacante) {

}

string Guerrero::identificador(){
    return "Guerrero";
}
Guerrero::~Guerrero() {

}

