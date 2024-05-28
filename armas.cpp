#include "armas.h"

Armas::Armas() {}
Armas::Armas(const string& name, const string& TipoArma) : Objetos(name){
    _TipoArma=TipoArma;
}
Armas::Armas(const string& name,const string& TipoArma, const int& power) : Objetos(name,power){
    _TipoArma=TipoArma;
}
Armas::Armas(Armas& Arma) : Objetos(Arma){
    this->_TipoArma=Arma._TipoArma;
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
    archivo << "Arma: " << _name << "\n       Tipo:" << _TipoArma << "\n       Poder:" <<_power << endl;
}
ostream& Armas::Display(ostream& os){
    os <<RED<<blanco<< "Arma: "<< getName() << " Tipo: " << getTipo() << " Poder: "<< getPower()<<RESET<<endl;
    return os;
}
void Armas::Display() const {
    cout <<RED<<blanco "Arma: "<< getName() << " Tipo: " << getTipo() << " Poder: "<< getPower()<<RESET<<endl;
}
