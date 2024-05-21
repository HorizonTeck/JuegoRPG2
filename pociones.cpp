#include "pociones.h"

Pociones::Pociones() {}
Pociones::Pociones(const string& name, const string& TipoPocion) : Objetos(name){
    _TipoPocion=TipoPocion;
}
Pociones::Pociones(const string& name,const string& TipoPocion, const int& power) : Objetos(name,power){
    _TipoPocion=TipoPocion;
}
Pociones::Pociones(Pociones& Pocion) : Objetos(Pocion){
    this->_TipoPocion=Pocion._TipoPocion;
}
Pociones::~Pociones() {}

string Pociones::getTipo() const {
    return _TipoPocion;
}

void Pociones::setTipo(const string& TipoPocion) {
    _TipoPocion = TipoPocion;
}

void Pociones::serializar(ofstream& archivo) const {
    archivo << "Pocion: " << _name << "\n       Tipo:" << _TipoPocion<< "\n       Poder:"<< _power  <<endl;
}
ostream& Pociones::Display(ostream& os){
    os << "Pocion: " << getName() << " Tipo: " << getTipo() <<endl;
    return os;
}
void Pociones::Display() const {
    cout << "Pocion: " << getName() << " Tipo: " << getTipo() <<endl;
}

