#ifndef OBJETOS_H
#define OBJETOS_H


#include <iostream>
#include <fstream>
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define PINK "\033[38;5;205m"
#define YELLOW "\033[33m"
#define rojo "\033[41m"
#define azul "\033[44m"
#define verde "\033[42m"
#define rosa  "\033[48;5;205m"
#define amarillo "\033[43m"
#define blanco "\033[47m"
#define RESET "\033[0m"



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
    friend ostream& operator<<(ostream& os, Objetos& O);
    virtual ostream& Display(ostream& os)=0;
    virtual void Display() const =0;
    virtual void serializar(ofstream& archivo) const =0;
    virtual~Objetos();
};

#endif // OBJETOS_H
