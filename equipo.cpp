#include "equipo.h"

Equipo::Equipo(const string& name) : _name(name), _dinero(1000){
}
Equipo::Equipo(const string& name, int dinero) : _name(name), _dinero(dinero){}
Equipo::Equipo() : _name("NO_NAME_DEFINED"), _dinero(1000){}

Equipo::Equipo(Equipo& Equipo) {
    setLista_Personajes(Equipo._Lista_Personajes);
    _name=Equipo._name;
    _dinero=Equipo._dinero;
}

string Equipo::getName() const {
    return _name;
}

vector<Personajes*>& Equipo::getLista_Personajes(){
    return _Lista_Personajes;
}
Personajes* Equipo::getLista_Personajes(int n) const{
    return _Lista_Personajes[n];
}
int Equipo::getDinero(){ return _dinero;}
void Equipo::setName(const string& name) {
    _name = name;
}
Equipo& Equipo::operator>>(Personajes *Personaje){
    this->setLista_Personajes(Personaje);
    return *this;
}
void Equipo::setLista_Personajes(vector<Personajes*> lista) {
    for (auto personaje : lista) {
        if (dynamic_cast<Guerrero*>(personaje)) {
            _Lista_Personajes.push_back(new Guerrero(*dynamic_cast<Guerrero*>(personaje)));
        } else if (dynamic_cast<Mago*>(personaje)) {
            _Lista_Personajes.push_back(new Mago(*dynamic_cast<Mago*>(personaje)));
        } else if (dynamic_cast<Arquero*>(personaje)) {
            _Lista_Personajes.push_back(new Arquero(*dynamic_cast<Arquero*>(personaje)));
        }
    }
}

void Equipo::setLista_Personajes(Personajes* Personaje){
    _Lista_Personajes.push_back(Personaje);
}
void Equipo::setDinero(int dinero){
    _dinero=dinero;
}
void Equipo::borrarPersonaje(int posicion){
    auto it = _Lista_Personajes.begin() + posicion - 1;
    delete *it;
    _Lista_Personajes.erase(it);
}

int Equipo::gettamaño(){
    return static_cast<int>(_Lista_Personajes.size());
}

ostream& operator<<(ostream& os, Equipo& E){
    os << "Nombre del equipo: " << E._name << ", tamaño del equipo: " << static_cast<int>(E._Lista_Personajes.size()) <<" Dinero: "<<E._dinero<< endl;
    os << "Integrantes:" << endl;
    for (int i = 0; i < static_cast<int>(E._Lista_Personajes.size()); i++) {
        os << i+1<<". "<<E._Lista_Personajes[i]->getName() << endl;
    }
    return os;
}
void Equipo::Display() const {
    cout << "Nombre del equipo: " << _name << ", tamaño del equipo: " << static_cast<int>(_Lista_Personajes.size()) << " Dinero: "<<_dinero<< endl;
    cout << "Integrantes:" << endl;
    for (int i = 0; i < static_cast<int>(_Lista_Personajes.size()); i++) {
        cout << i+1<<". "<<_Lista_Personajes[i]->getName() << endl;
    }
}

Equipo::~Equipo(){
    for(Personajes* objeto : _Lista_Personajes){
        delete objeto;
    }
    _Lista_Personajes.clear();
}

