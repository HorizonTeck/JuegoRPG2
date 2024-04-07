#include "equipo.h"

Equipo::Equipo(const string& name) : _name(name) {
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


void Equipo::display() const {
    cout << "Nombre del equipo: " << _name << ", tamaño del equipo: " << static_cast<int>(_Lista_Personajes.size()) << endl;
    cout << "Integrantes:" << endl;
    for (int i = 0; i < static_cast<int>(_Lista_Personajes.size()); i++) {
        cout << _Lista_Personajes[i]->getName() << endl;
    }
}

Equipo::~Equipo() {
}

