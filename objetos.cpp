#include "objetos.h"


Objetos::Objetos(){

}
Objetos::Objetos(const string&TipoObjeto,const string& name) : _name(name), _TipoObjeto(TipoObjeto) {}
Objetos::Objetos(const string&TipoObjeto,const string& name, const int& power) : _name(name), _TipoObjeto(TipoObjeto), _power(power){}
Objetos::~Objetos(){

}
string Objetos::getTipoObjeto() const {
    return _TipoObjeto;
}

void Objetos::setTipoObjeto(const string& TipoObjeto) {
    _TipoObjeto=TipoObjeto;
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

