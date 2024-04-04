#include "objetos.h"


Objetos::Objetos(){

}

Objetos::Objetos(const string& TipoObjeto, const string& name, const int& power) : _name(name), _power(power), _TipoObjeto(TipoObjeto) {

}

Objetos::~Objetos(){

}
string Objetos::getTipoObjeto() const {
    return _TipoObjeto;
}
int Objetos::getPower() const {
    return _power;
}
void Objetos::setPower(const int& power) {
    _power=power;
}
void Objetos::setTipoObjeto(const string& TipoObjeto) {
    _TipoObjeto=TipoObjeto;
}

void Objetos::setName(const string &name){
    _name=name;
}
string Objetos::getName() const{
    return _name;
}

