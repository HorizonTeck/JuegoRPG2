#ifndef POCIONES_H
#define POCIONES_H

#pragma once
#include "objetos.h"

class Pociones : public Objetos{
private:
    string _TipoPocion;
public:
    Pociones();
    Pociones(const string& name, const string& TipoPocion);
    Pociones(const string& name, const string& TipoPocion, const int& power);
    virtual string getTipo() const;
    virtual void setTipo(const string& TipoPocion);
    //void LanzarPocion(Personajes& Personaje);
    virtual void serializar(ofstream& archivo) const;
    virtual void display() const;
    virtual~Pociones();
};

#endif // POCIONES_H
