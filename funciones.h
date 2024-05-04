#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <equipo.h>
#include <guerrero.h>
#include <arquero.h>
#include <mago.h>
#include <pociones.h>
#include <armas.h>
#include <vector>
#include <thread>
#include <chrono>


class Funciones{
private:
    int tecla;
public:
    //Gestion de Archivos
    Funciones();
    void cargar(vector<Objetos*>& objetos, const string& nombreArchivo);
    void cargar(vector<Personajes*>& personajes, const string& nombreArchivo);
    void asignacionGuerrero(string linea,vector <int> atributos);
    void asignacionArquero(string linea,vector <int> atributos);
    void asignacionMago(string linea,vector <int>& atributos);
    void guardar(vector<Objetos*>& objetos, const string& nombreArchivo);
    void guardar(vector<Personajes*>& personajes, const string& nombreArchivo);
    int contarLineas(const string& nombreArchivo);

    //Gestion Atributos
    void setAtributos(Personajes* Lista_Personajes); //Pregunta al usuario y llama a las otras funciones de asignacion
    void setAtributos(bool random, Arquero* P);
    void setAtributos(bool random, Guerrero* P);
    void setAtributos(bool random, Mago* P);
    void setAtributos(Objetos* Objeto); //Pregunta al usuario y llama a las otras funciones de asignacion
    void setAtributos(bool random, Armas* Arma);
    void setAtributos(bool random, Pociones* Pocion);
    int setAtributos(bool random,int LI,int LS);

    //Gestion Equipos//
    void crear_equipo(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes); //Crea un Equipo preguntando al usuario
    void eliminar_equipo(vector<Equipo*>& Lista_Equipos);
    int tamaño_equipos(vector<Equipo*>& Lista_Equipos);
    Equipo* seleccionar_Equipo(vector<Equipo*>& Lista_Equipos);

    //Gestion Objetos
    Objetos* crear_objeto();
    void añadir_objeto(vector<Personajes*>& Lista_Personajes, vector<Equipo*>& Lista_Equipos, Objetos* objeto);


    //Gestion Personajes
    void añadir_personaje(Equipo* Equipo, vector<Personajes*>& Lista_Personajes);
    void crear_personaje(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes);
    Personajes* seleccionar_Personaje(vector<Equipo*>& Lista_Equipos);
    Personajes* seleccionar_Personaje(vector<Personajes*>& Lista_Personajes);
    //Funciones varias
    int seleccion_invalida(int LI, int LS);
    void Prueba(string linea);
};

#endif // FUNCIONES_H
