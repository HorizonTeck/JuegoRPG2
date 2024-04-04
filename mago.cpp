#include "mago.h"

Mago::Mago() : Personajes() {}

Mago::Mago(const string& name) : Personajes(name) {}

Mago::Mago(const string& name, const int atributos[], const Objetos** inventario) : Personajes(name, atributos, inventario) {}

void Mago::setAtributos(const int atributos[], const int tamaño) {
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
    _atributos[5] = 1 + rand() % (15-1+1); //fuerza
    _atributos[6] = 0 + rand() % (30-0+1); //escudo
}

void Mago::setInventario(const Objetos **objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Mago::Display() const {
    cout<< " Mago: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Fuerza: "<<_atributos[5]<<" Escudo: "<<_atributos[6]<<endl;
}

int Mago::Ataque() {
    const int* atributos = getAtributos();
    int ataque=0;
    ataque = atributos[2]*atributos[0]+atributos[5];//FALTA LAS ARMAS
    return ataque;
    delete[] atributos;
}

int Mago::Defensa() {
    const int* atributos = getAtributos();
    int defensa=0;
    defensa = atributos[4]*atributos[0]+atributos[6];
    return defensa;
    delete[] atributos;
}

string Mago::identificador(){
    return "Mago";
}

Mago::~Mago() {

}
