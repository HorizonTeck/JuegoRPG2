#ifndef OBJETOS_H
#define OBJETOS_H


#include <iostream>
#include <fstream>



using namespace std;
class Objetos{
protected:
    string _name;
    int _power;
public:
    Objetos();
    Objetos(const string& name);
    Objetos(const string& name, const int& power);
    Objetos(Objetos& Objeto);
    virtual string getName() const;
    virtual string getTipo() const=0;
    virtual void setName(const string& name);
    virtual void setTipo(const string& tipo)=0;
    virtual int getPower() const;
    virtual void setPower(const int& power);
    virtual void Display() const =0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Objetos();
};

#endif // OBJETOS_H
