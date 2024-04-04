#include "equipo.h"

Equipo::Equipo(const string& name, const int& n) : _name(name), _tamaño(n) {
    Lista_Personajes = new Personajes*[n];
}

Equipo::Equipo() : _name("NO_NAME_DEFINED"), _tamaño(0), Lista_Personajes(nullptr) {}

string Equipo::getName() const {
    return _name;
}

Personajes** Equipo::getLista_Personajes() const {
    return Lista_Personajes;
}
Personajes* Equipo::getLista_Personajes(int n) const{
    return Lista_Personajes[n];
}

void Equipo::setName(const string& name) {
    _name = name;
}

void Equipo::setLista_Personajes(Personajes** lista) {
    for(int i = 0; i < _tamaño; i++) {
        if(lista[i]->identificador()=="Guerrero"){
            Lista_Personajes[i] = new Guerrero(*dynamic_cast<Guerrero*>(lista[i]));
        }
        else if(lista[i]->identificador()=="Mago"){
            //Exactamente igual cambiando Guerrero por Mago
        }
        else if(lista[i]->identificador()=="Arquero"){

        }
        else{
            cout<< "El personaje en: "<<i<< " es nulo";
        }
    }
}


void Equipo::display() const {
    cout << "Nombre del equipo: " << _name << ", tamaño del equipo: " << _tamaño << endl;
    cout << "Integrantes:" << endl;
    for (int i = 0; i < _tamaño; i++) {
        cout << Lista_Personajes[i]->getName() << endl;
    }
}

Equipo::~Equipo() {
    delete[] Lista_Personajes;
}

