#include "personajes.h"

Personajes::Personajes(){
    _name="NO_NAME_DEFINED";
}

Personajes::Personajes(const string& name){
    _name=name;
}
Personajes::Personajes(const string& name, const int atributos[], const Objetos* inventario[]){
    _name=name;
    for(int i=0;i<6;i++){
        _atributos[i] = atributos[i];
    }
    for(int i=0;i<4;i++){
        *_inventario[i] = *inventario[i];
    }
}

Personajes::~Personajes(){
}


string Personajes::getName() const{
    return _name;
}
void Personajes::setName(const string &name){
    _name=name;
}

vector<Objetos*> Personajes::getInventario() const{
    return _inventario;
}

vector<int> Personajes::getAtributos() const{
    return _atributos;
}
int Personajes::tirar_dados() const{
     srand(static_cast<unsigned int>(time(nullptr)));
     return (1+rand()%(6-1+1));
}

