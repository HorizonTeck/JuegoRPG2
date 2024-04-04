#include "pociones.h"

Pociones::Pociones() {}

Pociones::Pociones(const string& TipoObjeto, const string& name, const string& TipoPocion, const int& power) : Objetos(TipoObjeto, name, power) {
    _TipoPocion = TipoPocion;
}

Pociones::~Pociones() {}

string Pociones::getTipoObjeto() const {
    return _TipoObjeto;
}

int Pociones::getPower() const {
    return _power;
}

void Pociones::setPower(const int& power) {
    _power = power;
}

void Pociones::setTipoObjeto(const string& TipoObjeto) {
    _TipoObjeto = TipoObjeto;
}

string Pociones::getTipo() const {
    return _TipoPocion;
}

void Pociones::setTipo(const string& TipoPocion) {
    _TipoPocion = TipoPocion;
}

void Pociones::serializar(ofstream& archivo) const {
    archivo << _TipoObjeto << " " << _name << " " << _TipoPocion << " " << _power << endl;
}

void Pociones::display() const {
    cout << "Pocion: " << getName() << " Tipo: " << getTipo() << " Poder: " << getPower() << endl;
}

