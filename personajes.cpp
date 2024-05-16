#include "personajes.h"
#include "mago.h"

Personajes::Personajes(){
    _name="NO_NAME_DEFINED";
}

Personajes::Personajes(const string& name){
    _name=name;
}
Personajes::Personajes(const string& name, vector<int> atributos, vector<Objetos*>  inventario){
    _name=name;
    for(int i=0;i<6;i++){
        _atributos.push_back(atributos[i]);
    }
    for(auto objeto : inventario){
        setInventario(objeto);
    }
}
Personajes::Personajes(Personajes* P){
    for(auto objeto : P->_inventario) this->setInventario(objeto);
    for(auto atributo : P->_atributos) this->_atributos.push_back(atributo);
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

Personajes& Personajes::operator>>(Objetos *Objeto){
    if(comprobarInventario(Objeto)==1) this->setInventario(Objeto);
    return *this;
}
string Personajes::getName() const{
    return _name;
}
void Personajes::setName(const string &name){
    _name=name;
}

vector<Objetos*>& Personajes::getInventario(){
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
ostream& operator<<(ostream& os, Personajes& P){
    P.Display(os);
    return os;
}
Personajes::~Personajes(){
    for(Objetos* objeto : _inventario){
        delete objeto;
    }
}

