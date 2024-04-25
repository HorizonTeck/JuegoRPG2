#include "arquero.h"

Arquero::Arquero() : Personajes() {_atributos.resize(7);}

Arquero::Arquero(const string& name) : Personajes(name) {_atributos.resize(7);}

Arquero::Arquero(const string& name, vector<int> atributos, vector <Objetos*> inventario) : Personajes(name, atributos, inventario) {_atributos.resize(7);}


void Arquero::setAtributos(bool random){
    int* comprobacion=new int();
    _atributos[0]=1; //nivel
    if(random==0)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        _atributos[1]=0 + rand() % (100-0+1); //salud
        _atributos[2]=0 + rand() % (30-0+1); //poder
        _atributos[3]=1 + rand() % (12-1+1); //precisión
        _atributos[4]=15 + rand() % (40-20+1); //protección
        _atributos[5]=1 + rand() % (15-1+1); //agilidad
        _atributos[6]=0 + rand() % (10-1+1); //carcaj
    }else
    {
        cout << "Dime la salud de tu personaje (0-100)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=0&&*comprobacion<=100)
        {
            _atributos[1]=*comprobacion;
         } else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<0)
            {
                _atributos[1]=0;
            }else if(*comprobacion>100) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[1]=100;
            }
        }
        cout << "Dime el poder de tu personaje (0-30)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=0&&*comprobacion<=30)
        {
            _atributos[2]=*comprobacion;
         } else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<0)
            {
                _atributos[2]=0;
            }else if(*comprobacion>30) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[2]=30;
            }
        }
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=1&&*comprobacion<=12)
        {
            _atributos[3]=*comprobacion;
         } else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<1)
            {
                _atributos[3]=1;
            }else if(*comprobacion>12) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[3]=12;
            }
        }
        cout << "Dime protecion de tu personaje (20-40)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=20&&*comprobacion<=40)
        {
            _atributos[4]=*comprobacion;
         } else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<20)
            {
                _atributos[4]=20;
            }else if(*comprobacion>40) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[4]=40;
            }
        }
        cout << "Dime la agilidad de tu personaje (1-15)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=1&&*comprobacion<=15)
        {
            _atributos[5]=*comprobacion;
         } else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<1)
            {
                _atributos[5]=1;
            }else if(*comprobacion>15) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[5]=15;
            }
        }
        cout << "Dime las flechas que tiene tu personaje en el carcaj (0-10)"<< endl;
        cin>> *comprobacion;
        if(*comprobacion>=0&&*comprobacion<=10)
        {
            _atributos[6]=*comprobacion;
         }else
        {
            cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
            if(*comprobacion<0)
            {
                _atributos[6]=0;
            }else if(*comprobacion>10) //Comprobacion para que no se cuele nada que no sea un numero
            {
                _atributos[6]=10;
            }
        }
    }
    delete comprobacion;
}

void Arquero::setAtributos(vector<int> atributos) {
    for(int i=0;i<static_cast<int>(atributos.size());i++){
        this->_atributos[i] = atributos[i];
    }
}

void Arquero::setAtributos(int atrib, int posicion) {
    if(posicion<=6)
    {
        _atributos[posicion]=atrib;
    }else
        cout<< "Posicion no encontrada"<<endl;
}

void Arquero::setInventario(vector<Objetos*> objetos) {
    for(int i=0;i<4;i++){
        *_inventario[i] = *objetos[i];
    }
}

void Arquero::Display() const {
    cout<< " Arquero: "<<_name<<" Atributos: "<<endl;
    cout <<"Nivel: "<< _atributos[0] <<" Salud: "<< _atributos[1] <<" Poder: "<< _atributos[2] <<" Precisión: "<<_atributos[3]<<" Protección: "<<_atributos[4];
    cout <<" Agilidad: "<<_atributos[5]<<" Carcaj: "<<_atributos[6]<<endl;
}

int Arquero::Ataque() {
    int ataque=0;
    ataque = getAtributos(2)*getAtributos(0);
    for(auto objeto : _inventario)
    {
        if(objeto->getTipoObjeto()=="Arma")
        {
        ataque= ataque+ objeto->getPower()/getAtributos(6);
    }
    }
    return ataque;
}

int Arquero::Defensa() {
    int defensa=0;
    defensa = getAtributos(4)*getAtributos(0)+2*getAtributos(5);
    return defensa;
}

string Arquero::identificador(){
    return "Arquero";
}
Arquero::~Arquero() {

}
