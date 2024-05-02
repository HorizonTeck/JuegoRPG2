#ifndef ARMAS_H
#define ARMAS_H

#pragma once
#include "objetos.h"

class Armas : public Objetos{
private:
    string _TipoArma;
public:
    Armas();
    Armas(const string& name, const string& TipoArma);
    Armas(const string& name, const string& TipoArma, const int& power);
    Armas(Armas& arma);
    virtual string getTipo() const;
    virtual void setTipo(const string& TipoArma);
    virtual void serializar(ofstream& archivo) const;
    virtual void display() const;
    virtual~Armas();
};

#endif // ARMAS_H
