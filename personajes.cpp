#include "personajes.h"

Personajes::Personajes(){
    _name="NO_NAME_DEFINED";
}

Personajes::Personajes(const string& name){
    _name=name;
}
Personajes::Personajes(const string& name, vector<int> atributos, vector<Objetos*>  inventario){
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

void Personajes::setInventario(const vector<Objetos *> inventario){
    for(auto objeto : inventario){
        _inventario.push_back(objeto);
    }
}
void Personajes::setInventario(Objetos* objeto){
    _inventario.push_back(objeto);
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

int Personajes::getAtributos(int atrib)
{
    return _atributos[atrib];
}

vector<int> Personajes::getAtributos() const{
    return _atributos;
}
int Personajes::tirar_dados() const{
     srand(static_cast<unsigned int>(time(nullptr)));
     return (1+rand()%(12-1+1));
}

