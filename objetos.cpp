#include "objetos.h"


Objetos::Objetos(){

}
Objetos::Objetos(const string& name) : _name(name) {}
Objetos::Objetos(const string& name, const int& power) : _name(name), _power(power){}
Objetos::Objetos(Objetos& objeto){
    this->_name=objeto._name;
    this->_power=objeto._power;
}
Objetos::~Objetos(){

}

ostream& operator<<(ostream& os, Objetos& O){
    O.Display(os);
    return os;
}

void Objetos::setPower(const int &power){
    _power=power;
}
int Objetos::getPower() const{
    return _power;
}

void Objetos::setName(const string &name){
    _name=name;
}
string Objetos::getName() const{
    return _name;
}

