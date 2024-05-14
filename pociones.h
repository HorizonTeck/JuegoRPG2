#ifndef POCIONES_H
#define POCIONES_H

#include "objetos.h"

class Pociones : public Objetos{
private:
    string _TipoPocion;
public:
    Pociones();
    Pociones(const string& name, const string& TipoPocion);
    Pociones(const string& name, const string& TipoPocion, const int& power);
    Pociones(Pociones& Pocion);
    virtual string getTipo() const;
    virtual void setTipo(const string& TipoPocion);
    virtual void serializar(ofstream& archivo) const;
    virtual ostream& Display(ostream& os);
    virtual void Display() const;
    virtual~Pociones();
};

#endif // POCIONES_H
