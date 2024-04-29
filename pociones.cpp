#include "pociones.h"

Pociones::Pociones() {}
Pociones::Pociones(const string& TipoObjeto, const string& name, const string& TipoPocion) : Objetos(TipoObjeto,name){
    _TipoPocion=TipoPocion;
}
Pociones::Pociones(const string&TipoObjeto,const string& name,const string& TipoPocion, const int& power) : Objetos(TipoObjeto,name,power){
    _TipoPocion=TipoPocion;
}
Pociones::~Pociones() {}

string Pociones::getTipo() const {
    return _TipoPocion;
}

void Pociones::setTipo(const string& TipoPocion) {
    _TipoPocion = TipoPocion;
}

void Pociones::LanzarPocion(Personajes& Defensor)
{
    if(_TipoPocion=="Mana"||_TipoPocion=="mana")
    {
        Defensor.setAtributos(15,5);
    }else
        Defensor.setAtributos(100,1);
}

void Pociones::serializar(ofstream& archivo) const {
    archivo << _TipoObjeto << " " << _name << " " << _TipoPocion <<endl;
}
void Pociones::display() const {
    cout << "Pocion: " << getName() << " Tipo: " << getTipo() <<endl;
}

