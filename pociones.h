#ifndef POCIONES_H
#define POCIONES_H

#include <objetos.h>

class Pociones : public Objetos{
private:
    string _TipoPocion;
public:
    Pociones();
    Pociones(const string& name, const string& TipoObjeto, const string& TipoArma, const int& power);
    virtual string getTipo() const;
    virtual string getTipoObjeto() const;
    virtual int getPower() const;
    virtual void setPower(const int& power);
    virtual void setTipoObjeto(const string& TipoObjetos);
    virtual void setTipo(const string& TipoPocion);
    virtual void serializar(ofstream& archivo) const;
    virtual void display() const;
    virtual~Pociones();
};

#endif // POCIONES_H

//hola hijo de puta
