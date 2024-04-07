#ifndef POCIONES_H
#define POCIONES_H

#include <objetos.h>
#include<personajes.h>

class Pociones : public Objetos{
private:
    string _TipoPocion;
public:
    Pociones();
    Pociones(const string& name, const string& TipoObjeto, const string& TipoArma, const int& power);
    virtual string getTipo() const;
    virtual int getPower() const;
    virtual void setPower(const int& power);
    virtual void setTipo(const string& TipoPocion);
    void LanzarPocion(Personajes* Defensor);
    virtual void serializar(ofstream& archivo) const;
    virtual void display() const;
    virtual~Pociones();
};

#endif // POCIONES_H
