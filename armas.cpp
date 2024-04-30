#include "armas.h"

Armas::Armas() {}
Armas::Armas(const string&TipoObjeto,const string& name, const string& TipoArma) : Objetos(TipoObjeto,name){
    _TipoArma=TipoArma;
}
Armas::Armas(const string&TipoObjeto,const string& name,const string& TipoArma, const int& power) : Objetos(TipoObjeto,name,power){
    _TipoArma=TipoArma;
}
Armas::~Armas() {

}
string Armas::getTipo() const{
    return _TipoArma;
}
void Armas::setTipo(const string& TipoArma){
    _TipoArma=TipoArma;
}

void Armas::serializar(ofstream& archivo) const {
    archivo << _TipoObjeto << " " << _name << " " << _TipoArma << " " <<_power << endl;
}

void Armas::display() const {
    cout << "Arma: "<< getName() << " Tipo: " << getTipo() << " Poder: "<< getPower()<<endl;
}
