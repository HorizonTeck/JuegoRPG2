#include "mago.h"

Mago::Mago() : Personajes() {_atributos.resize(6);}

Mago::Mago(const string& name) : Personajes(name) {_atributos.resize(6);}

Mago::Mago(const string& name,vector<int> atributos, vector<Objetos*>  inventario) : Personajes(name, atributos, inventario) {_atributos.resize(6);}
Mago::Mago(const string& name, int nivel, int salud,int poder, int precision, int proteccion, int mana) : Personajes(name){
    _atributos.resize(6);
    _atributos[0]=nivel;
    _atributos[1]=salud;
    _atributos[2]=poder;
    _atributos[3]=precision;
    _atributos[4]=proteccion;
    _atributos[5]=mana;
}
Mago::Mago(Mago& Mago) : Personajes(Mago){
    for(auto hechizo : Mago._hechizos) setHechizos(hechizo);
}
void Mago::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(_atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}
void Mago::setAtributos(int atrib, int posicion) {
        _atributos[posicion]=atrib;
}
vector<Hechizos*>& Mago::getHechizos(){
    return _hechizos;
}
void Mago::setHechizos(Hechizos* Hechizo){
    _hechizos.push_back(new Hechizos(*Hechizo));
}
Mago& Mago::operator>>(Hechizos* Hechizo){
    setHechizos(Hechizo);
    return *this;
}
bool Mago::comprobarHechizos(){
    if(_hechizos.size()<2) return 0;
    else return 1;
}
bool Mago::comprobarBaculo(){
    for(auto objeto: _inventario)
    {
        if(objeto->getTipo()=="BACULO")
        {
            return 1;
        }
    }
    return 0;
}
bool Mago::comprobarInventario(Objetos *objeto){
    if(comprobarInventario()==1) return 0;
    int armas=0,salud=0,mana=0;
    if(dynamic_cast<Armas*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Armas*>(objetos)) armas++;
        }
        if(armas<1&&objeto->getTipo()=="BACULO") return 1;
        else return 0;
    }else if(dynamic_cast<Pociones*>(objeto)){
        for(auto objetos : _inventario){
            if(dynamic_cast<Pociones*>(objetos)){
                if(objetos->getTipo()=="SALUD") salud++;
                else if(objetos->getTipo()=="MANA") mana++;
            }
        }
        if(mana<1&&objeto->getTipo()=="MANA") return 1;
        else if(salud<2&&objeto->getTipo()=="SALUD") return 1;
    }
    return 0;
}
bool Mago::comprobarInventario(){
    if(_inventario.size()==4) return 1;
    else return 0;
}

ostream& Mago::Display(ostream &os){
    os<< "Mago: "<<_name<<" Atributos: "<<endl;
    os <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Mana: "<<_atributos[5]<<endl;
    if(_inventario.size()>0){
        os<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            os<<"     "<<i+1<<". ";
            os<<*_inventario[i];
        }
    }
    if(_hechizos.size()>0){
        os<<"     Hechizos:"<<endl;
        for(unsigned int i=0;i<_hechizos.size();i++){
            os<<"     "<<i+1<<". ";
            os<<*_hechizos[i];
        }
    }
    return os;
}
void Mago::Display() const {
    cout<< "Mago: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4]<<" Mana: "<<_atributos[5]<<endl;
    if(_inventario.size()>0){
        cout<<"     Inventario:"<<endl;
        for(int i=0;i<static_cast<int>(_inventario.size());i++){
            cout<<"     "<<i+1<<". ";
            _inventario[i]->Display();
        }
    }
    if(_hechizos.size()>0){
        cout<<"     Hechizos:"<<endl;
        for(unsigned int i=0;i<_hechizos.size();i++){
            cout<<"     "<<i+1<<". ";
            _hechizos[i]->Display();
        }
    }
}
void Mago::DisplayAtaque() const{
    cout<<"Ataque efectivo, hará "<<_atributos[2]<<" * "<<_atributos[0]<<" + ";
    for(auto objeto : _inventario){
        if(objeto->getTipo()=="BACULO"){
            cout<<objeto->getPower()<<" daño"<<endl;
        }
    }
}

int Mago::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);
    for(auto objeto : _inventario)
    {
        if(dynamic_cast<Armas*>(objeto))
        {
        ataque += objeto->getPower();
    }
    }
    return ataque;
}

int Mago::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0);
    return defensa;
}

void Mago::LanzarPocion(Pociones* P)
{
    if(P->getTipo()=="Salud"||P->getTipo()=="salud")
    {
        cout<< "El mago " << _name << " se ha curado " << P->getPower()<<" puntos de salud"<<endl;
        _atributos[1]+=P->getPower();
    }else if (P->getTipo()=="Mana"||P->getTipo()=="mana"||P->getTipo()=="Maná"||P->getTipo()=="maná")
    {
        cout<< "El mago " << _name << " ha restaurado  " << P->getPower()<<" puntos de maná"<<endl;
        _atributos[5]+=P->getPower();
    }else
        cout<< "Pocion no valida"<<endl;

}

void Mago::serializar(ofstream &archivo) const
{
   archivo<< "Mago: "<<_name<<"\n   Nivel: "<< _atributos[0] <<"\n   Salud: "<< _atributos[1] <<"\n   Poder: "<< _atributos[2] <<"\n   Precision: "<<_atributos[3]<<"\n   Proteccion: "<<_atributos[4]<<"\n   Mana: "<<_atributos[5]<<endl;
   for(auto hechizo : _hechizos)
   {
       archivo<< "    Hechizo: " << hechizo->getName()<<"\n     Tipo: "<<hechizo->getTipoHechizo()<<"\n     Coste: "<<hechizo->getCoste()<<"\n";
   }
}
Mago::~Mago(){
    for(auto objeto : _hechizos){
        delete objeto;
    }
}
