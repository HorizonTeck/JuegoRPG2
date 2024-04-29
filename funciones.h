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
    void setAtributos(bool random, Personajes* Lista_Personajes);
    void setAtributos(bool random, Armas* Arma);
    void setAtributos(bool random, Pociones* Pocion);
    void setAtributos(bool random, Objetos* Objeto);
    int comprobar(int comprobacion,int LI, int LS);
    int seleccion_invalida();
    void crear_objeto();
};

#endif // FUNCIONES_H
