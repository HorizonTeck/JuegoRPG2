#include "equipo.h"

Equipo::Equipo(const string& name, const int& n) : _name(name), _tamaño(n) {
}

Equipo::Equipo() : _name("NO_NAME_DEFINED"), _tamaño(0){}

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
    for(int i = 0; i < _tamaño; i++) {
        _Lista_Personajes[i] = lista[i];
    }
}


void Equipo::display() const {
    cout << "Nombre del equipo: " << _name << ", tamaño del equipo: " << _tamaño << endl;
    cout << "Integrantes:" << endl;
    for (int i = 0; i < _tamaño; i++) {
        cout << _Lista_Personajes[i]->getName() << endl;
    }
}

Equipo::~Equipo() {
}

