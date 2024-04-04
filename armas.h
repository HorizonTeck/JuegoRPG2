#ifndef ARMAS_H
#define ARMAS_H

#include <objetos.h>

class Armas : public Objetos{
private:
    string _TipoArma;
public:
    Armas();
    Armas(const string& name, const string& TipoObjeto, const string& TipoArma, const int& power);
    virtual string getTipo() const;
    virtual string getTipoObjeto() const;
    virtual int getPower() const;
    virtual void setPower(const int& power);
    virtual void setTipoObjeto(const string& TipoObjetos);
    virtual void setTipo(const string& TipoArma);
    virtual void serializar(ofstream& archivo) const;
    virtual void display() const;
    virtual~Armas();
};

#endif // ARMAS_H
