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
    for(auto objeto : inventario){
        setInventario(objeto);
    }
}

Personajes::~Personajes(){
    for(auto objeto : _inventario){
        delete objeto;
    }
}

void Personajes::setInventario(const vector<Objetos *> inventario){
    for(auto objeto : inventario){
        setInventario(objeto);
    }
}
void Personajes::setInventario(Objetos* objeto){
    Objetos *copia;
    if(dynamic_cast<Armas*>(objeto)){
        copia= new Armas(dynamic_cast<Armas&>(*objeto));
    }else{
        copia=new Pociones(dynamic_cast<Pociones&>(*objeto));
    }
    _inventario.push_back(copia);
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

