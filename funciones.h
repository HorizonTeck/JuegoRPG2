#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <equipo.h>
#include <guerrero.h>
#include <arquero.h>
#include <mago.h>
#include <armas.h>
#include <pociones.h>
#include <vector>
#include <thread>
#include <chrono>



class Funciones{
public:
    Funciones();
    void cargar(vector<Objetos*>& objetos, const string& nombreArchivo);
    void cargar();
    void guardar(vector<Objetos*>& objetos, const string& nombreArchivo);
    void guardar();
    int contarLineas(const string& nombreArchivo);
    void setAtributos(bool random, Arquero* P);
    void setAtributos(bool random, Guerrero* P);
    void setAtributos(bool random, Mago* P);
    void setAtributos(Personajes* Lista_Personajes);
    void setAtributos(bool random, Armas* Arma);
    void setAtributos(bool random, Pociones* Pocion);
    void setAtributos(Objetos* Objeto);
    int setAtributos(bool random,int LI,int LS);
    Objetos* crear_objeto();
    int seleccion_invalida(int LI, int LS);
};

#endif // FUNCIONES_H
