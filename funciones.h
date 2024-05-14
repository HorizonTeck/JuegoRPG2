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
#include <cctype>


class Funciones{
private:
    int tecla;
public:

    //Gestion de Archivos
    Funciones();
    void cargar(vector<Objetos*>& objetos, const string& nombreArchivo);
    void cargar(vector<Personajes*>& personajes, const string& nombreArchivo);
    void cargar(vector<Equipo*>& equipos, const string& nombreArchivo);
    void guardar(vector<Objetos*> objetos, ofstream &archivo);
    void guardar(vector<Personajes*> personajes, const string& nombreArchivo);
    void guardar(vector<Equipo*> equipos, const string& nombreArchivo);
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
    void eliminar_personaje(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes);
    Personajes* seleccionar_Personaje(vector<Equipo*>& Lista_Equipos);
    Personajes* seleccionar_Personaje(vector<Personajes*>& Lista_Personajes);

    //Gestion del Display
    template <typename T>friend ostream& operator<<(ostream& os, T& P){
        P.mostrar(os);
        return os;
    }
    template <typename T> void Recorrer(vector<T*> vec){ //ME LO DIJO EL PROFE QUE LO PUSIERA ASI (Jose Carlos)
        if(vec.size()<=0) cout<<"No hay nada declarado todavia de este tipo"<<endl;
        else{
            for(auto objeto:vec){
                objeto->Display();
                cout<<endl;
            }
        }
    }
    //Funciones varias
    int seleccion_invalida(int LI, int LS);
    void espera();
    string to_uppercase(string& linea);
};

#endif // FUNCIONES_H
