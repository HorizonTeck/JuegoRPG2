#ifndef OBJETOS_H
#define OBJETOS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Objetos{
protected:
    string _name;
    string _TipoObjeto;
    int _power;
public:
    Objetos();
    Objetos(const string&TipoObjeto,const string& name);
    Objetos(const string&TipoObjeto,const string& name, const int& power);
    virtual string getName() const;
    virtual string getTipoObjeto() const;
    virtual string getTipo() const=0;
    virtual void setName(const string& name);
    virtual void setTipoObjeto(const string& TipoObjeto);
    virtual void setTipo(const string& tipo)=0;
    virtual int getPower() const;
    virtual void setPower(const int& power);
    virtual void display() const =0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Objetos();
};

#endif // OBJETOS_H
