#include "guerrero.h"
//#include <armas.h>

Guerrero::Guerrero() : Personajes() {_atributos.resize(7);}

Guerrero::Guerrero(const string& name) : Personajes(name) {_atributos.resize(7);}

Guerrero::Guerrero(const string& name, vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}
Guerrero::Guerrero(const string& name, int nivel, int salud,int poder, int precision, int proteccion, int fuerza, int escudo) : Personajes(name){
    _atributos.resize(7);
    _atributos[0]=nivel;
    _atributos[1]=salud;
    _atributos[2]=poder;
    _atributos[3]=precision;
    _atributos[4]=proteccion;
    _atributos[5]=escudo;
    _atributos[6]=fuerza;
}
Guerrero::Guerrero(Guerrero& Guerrero) : Personajes(Guerrero){}


void Guerrero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Guerrero::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}
bool Guerrero::comprobarInventario(Objetos *objeto){
    if(comprobarInventario()==1) return 0;
    int armas=0,pociones=0;
    if(dynamic_cast<Armas*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Armas*>(objetos)) armas++;
        }
        if(armas<2&&(objeto->getTipo()=="CONTUNDENTE"||objeto->getTipo()=="CORTANTE")) return 1;
        else return 0;
    }else if(dynamic_cast<Pociones*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Pociones*>(objetos)) pociones++;
            if(pociones<1&&objeto->getTipo()=="SALUD") return 1;
        }
    }
    return 0;
}
bool Guerrero::comprobarInventario(){
    if(_inventario.size()==3) return 1;
    else return 0;
}

ostream& Guerrero::Display(ostream &os){
    os<< "Guerrero: "<<_name<<" Atributos: "<<endl;
    os <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Fuerza: "<<_atributos[6]<<" Escudo: "<<_atributos[5]<<endl;
    if(_inventario.size()>0){
        os<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            os<<"     "<<i+1<<". ";
            os<<*_inventario[i];
        }
    }
    return os;
}

void Guerrero::Display() const {
    cout<< "Guerrero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Fuerza: "<<_atributos[6]<<" Escudo: "<<_atributos[5]<<endl;
    if(_inventario.size()>0){
        cout<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            cout<<"     "<<i+1<<". ";
            _inventario[i]->Display();
        }
    }
}
void Guerrero::DisplayAtaque() const
{
    //Poder*nivel + fuerza + arma1+ arma2
    cout<< _atributos[2] << " * "<< _atributos[0] << " + "<< _atributos[6] ;
    for(auto objeto : _inventario)
    {
        if(objeto->getTipo()=="Arma")
        {
            cout<<" + "<<objeto->getPower();
        }
    }
    cout<<endl;
}

int Guerrero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0)+getAtributos(5);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
        ataque += objeto->getPower();
        }
    }
    return ataque;
}

int Guerrero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+getAtributos(6);
    return defensa;
}

void Guerrero::serializar(ofstream &archivo) const
{
    archivo<< "Guerrero: "<<_name<<"\n   Nivel: "<< _atributos[0] <<"\n   Salud: "<< _atributos[1] <<"\n   Poder: "<< _atributos[2] <<"\n   Precision: "<<_atributos[3]<<"\n   Proteccion: "<<_atributos[4]<<"\n   Fuerza: "<<_atributos[6]<<"\n   Escudo: "<<_atributos[5]<<endl;
}

bool Guerrero::LanzarPocion(Pociones* P)
{
    if(P->getTipo()=="Salud"||P->getTipo()=="SALUD")
    {
        cout<< "El guerrero " << _name << " se ha curado " << P->getPower()<<" puntos de salud"<<endl;
        _atributos[1]+=P->getPower();
        return 1;
    }else if (P->getTipo()=="MANA"||P->getTipo()=="mana"||P->getTipo()=="Maná"||P->getTipo()=="maná")
    {
        cout<< "El guerrero " << _name << " no ha sido capaz de lanzar la pocion"<<endl;
        return 0;
    }else cout<< "Pocion no valida"<<endl;
    return 0;
}
Guerrero::~Guerrero(){}
