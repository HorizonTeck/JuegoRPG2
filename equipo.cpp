#include "equipo.h"

Equipo::Equipo(const string& name) : _name(name){
}

Equipo::Equipo() : _name("NO_NAME_DEFINED"){}

string Equipo::getName() const {
    return _name;
}

vector<Personajes*> Equipo::getLista_Personajes() const {
    return _Lista_Personajes;
}
Personajes* Equipo::getLista_Personajes(int n) const{
    return _Lista_Personajes[n];
}

void Equipo::setName(const string& name) {
    _name = name;
}

void Equipo::setLista_Personajes(vector<Personajes*> lista) {
    for(int i = 0; i < static_cast<int>(_Lista_Personajes.size()); i++) {
        _Lista_Personajes[i] = lista[i];
    }
}
void Equipo::setLista_Personajes(Personajes* Personaje){
    _Lista_Personajes.push_back(Personaje);
}

void Equipo::borrarPersonaje(int posicion){
    auto it = _Lista_Personajes.begin() + posicion - 1;
    delete *it;
    _Lista_Personajes.erase(it);
}

int Equipo::gettamaño(){
    return static_cast<int>(_Lista_Personajes.size());
}

void Equipo::Display() const {
    cout << "Nombre del equipo: " << _name << ", tamaño del equipo: " << static_cast<int>(_Lista_Personajes.size()) << endl;
    cout << "Integrantes:" << endl;
    for (int i = 0; i < static_cast<int>(_Lista_Personajes.size()); i++) {
        cout << i+1<<". "<<_Lista_Personajes[i]->getName() << endl;
    }
}

Equipo::~Equipo(){
    for(auto objeto : _Lista_Personajes){
        delete objeto;
    }
}

