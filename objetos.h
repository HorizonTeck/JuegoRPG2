#ifndef OBJETOS_H
#define OBJETOS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Objetos{
protected:
    string _name;
    int _power;
    string _TipoObjeto;
public:
    Objetos();
    Objetos(const string& TipoObjeto, const string& name, const int& power);
    virtual string getName() const;
    virtual string getTipoObjeto() const =0;
    virtual int getPower() const =0;
    virtual string getTipo() const=0;
    virtual void setName(const string& name);
    virtual void setPower(const int& power)=0;
    virtual void setTipoObjeto(const string& TipoObjeto)=0;
    virtual void display() const =0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Objetos();
};

#endif // OBJETOS_H
