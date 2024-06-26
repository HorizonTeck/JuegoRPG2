#include "arquero.h"
#include <armas.h>

Arquero::Arquero() : Personajes() {_atributos.resize(7);}

Arquero::Arquero(const string& name) : Personajes(name) {_atributos.resize(7);}

Arquero::Arquero(const string& name, vector<int> atributos, vector <Objetos*> inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}
Arquero::Arquero(const string& name, int nivel, int salud,int poder, int precision, int proteccion, int agilidad, int carcaj) : Personajes(name){
    _atributos.resize(7);
    _atributos[0]=nivel;
    _atributos[1]=salud;
    _atributos[2]=poder;
    _atributos[3]=precision;
    _atributos[4]=proteccion;
    _atributos[5]=agilidad;
    _atributos[6]=carcaj;
}
Arquero::Arquero(Arquero& Arquero) : Personajes(Arquero){}

void Arquero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Arquero::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}
bool Arquero::comprobarInventario(Objetos *objeto){
    if(comprobarInventario()==1) return 0;
    int armas=0,pociones=0;
    if(dynamic_cast<Armas*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Armas*>(objetos)) armas++;
        }
        if(armas<1&&objeto->getTipo()=="DISTANCIA") return 1;
        else return 0;
    }else if(dynamic_cast<Pociones*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Pociones*>(objetos)) pociones++;
        }
        if(pociones<2&&objeto->getTipo()=="SALUD") return 1;
    }
    return 0;
}
bool Arquero::comprobarInventario(){
    if(_inventario.size()==3) return 1;
    else return 0;
}

ostream& Arquero::Display(ostream &os){
    os<< rojo<<"Arquero: "<<_name<<" Atributos: "<<endl;
    os <<verde<<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Agilidad: "<<_atributos[5]<<" Carcaj: "<<_atributos[6]<<blanco<<BLUE<<endl;
    if(_inventario.size()>0){
        os<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            os<<"     "<<i+1<<". ";
            os<<*_inventario[i];
        }
    }
    os<<RESET;
    return os;
}
void Arquero::Display() const {
    cout<<rojo<< "Arquero: "<<_name<<" Atributos: "<<endl;
    cout <<verde<<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Agilidad: "<<_atributos[5]<<" Carcaj: "<<_atributos[6]<<blanco<<BLUE<<endl;
    if(_inventario.size()>0){
        cout<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            cout<<"     "<<i+1<<". ";
            _inventario[i]->Display();
        }
    }
    cout<<RESET;
}
void Arquero::DisplayAtaque() const
{
    cout<<"Ataque efectivo, hará "<<_atributos[2]<<" * "<<_atributos[0]<<" + ";
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
            if(_atributos[6]>=1)
            {
               cout<< objeto->getPower() <<" / "<<_atributos[6];
            }
        }
    }
}

int Arquero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
            if(getAtributos(6)>=1)
            {
                ataque= ataque+ objeto->getPower()/getAtributos(6);
            }
        }
    }
    return ataque;
}

int Arquero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+2*getAtributos(5);
    return defensa;
}

void Arquero::serializar(ofstream& archivo) const
{
    archivo<< "Arquero: "<<_name<<" \n   Nivel: "<< _atributos[0] <<"\n   Salud: "<< _atributos[1] <<"\n   Poder: "<< _atributos[2] <<"\n   Precision: "<<_atributos[3]<<"\n   Proteccion: "<<_atributos[4]<<"\n   Agilidad: "<<_atributos[5]<<"\n   Carcaj: "<<_atributos[6]<<endl;
 }


bool Arquero::LanzarPocion(Pociones* P)
{
    if(P->getTipo()=="Salud"||P->getTipo()=="SALUD")
    {
        cout<< "El arquero " << _name << " se ha curado " << P->getPower()<<" puntos de salud"<<endl;
        _atributos[1]+=P->getPower();
        return 1;
    }else if (P->getTipo()=="MANA"||P->getTipo()=="mana"||P->getTipo()=="Maná"||P->getTipo()=="maná")
    {
        cout<< "El arquero " << _name << " no ha sido capaz de lanzar la pocion"<<endl;
        return 0;
    }else cout<< "Pocion no valida"<<endl;
    return 0;
}
Arquero::~Arquero(){}
