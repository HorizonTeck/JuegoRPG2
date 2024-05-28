#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <equipo.h>
#include <guerrero.h>
#include <arquero.h>
#include <hechizos.h>
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
    void cargar(vector<Objetos*>& Lista_Objetos, string nombreArchivo);
    void cargar(vector<Equipo*>& Lista_Equipos, string nombreArchivo);
    void cargar(vector<Hechizos*>& Lista_Hechizos, string nombreArchivo);
    void cargar(vector<Personajes*>& Lista_Personajes, string nombreArchivo);

    void guardar(vector<Objetos*> objetos, ofstream &archivo);
    void guardar(vector<Personajes*> personajes, const string& nombreArchivo);
    void guardar(vector<Equipo*> equipos, const string& nombreArchivo);
    int contarLineas(const string& nombreArchivo);
    void QuitarEspacios(string& palabra);

    //Gestion Atributos
    void setAtributos(Personajes* Lista_Personajes); //Pregunta al usuario y llama a las otras funciones de asignacion
    void setAtributos(bool random, Arquero* P);
    void setAtributos(bool random, Guerrero* P);
    void setAtributos(bool random, Mago* P);
    void setAtributos(Objetos* Objeto); //Pregunta al usuario y llama a las otras funciones de asignacion
    void setAtributos(bool random, Armas* Arma);
    void setAtributos(bool random, Pociones* Pocion);
    int setAtributos(bool random,int LI,int LS);
    void modificar_atributos(Personajes* Personaje);

    //Gestion Equipos//
    void crear_equipo(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes); //Crea un Equipo preguntando al usuario
    void eliminar_equipo(vector<Equipo*>& Lista_Equipos);
    int tamaño_equipos(vector<Equipo*>& Lista_Equipos);
    void modificar_personaje(Equipo* Equipo, vector<Objetos*>& Lista_Objetos, vector<Hechizos*>& Lista_Hechizos);
    void modificar_equipo(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes, vector<Objetos*>& Lista_Objetos, vector<Hechizos*>& Lista_Hechizos);
    Equipo* seleccionar_Equipo(vector<Equipo*>& Lista_Equipos);

    //Gestion Objetos
    Objetos* crear_objeto();
    void añadir_objeto(Personajes* Personaje, vector<Objetos*>& Lista_Objetos);
    void modificar_objetos(Personajes* Personaje, vector<Objetos*>& Lista_Objetos);
    void modificar_objetos(vector<Objetos*>& Lista_Objetos);
    void eliminar_objeto(vector<Objetos*>& Lista_Objetos);

    //Gestion Hechizos
    Hechizos* crear_hechizo();
    void añadir_hechizos(Mago* Mago, vector<Hechizos*>& Lista_Hechizos);
    void modificar_hechizos(Mago* Mago, vector<Hechizos*>& Lista_Hechizos);
    void modificar_hechizos(vector<Hechizos*>& Lista_Hechizos);
    void eliminar_hechizo(vector<Hechizos*>& Lista_Hechizos);


    //Gestion Personajes
    void añadir_personaje(Equipo* Equipo, vector<Personajes*>& Lista_Personajes);
    void quitar_personaje(Equipo* Equipo, vector<Personajes*>& Lista_Personajes);
    void crear_personaje(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes);
    void eliminar_personaje(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes);
    void modificar_personaje(Personajes* Personaje, vector<Objetos*>& Lista_Objetos, vector<Hechizos*>& Lista_Hechizos);
    Personajes* seleccionar_Personaje(vector<Equipo*>& Lista_Equipos);
    Personajes* seleccionar_Personaje(vector<Personajes*>& Lista_Personajes);

    //Gestion del Display
    template <typename T> void Recorrer(vector<T*> vec){ //NOS DIJO EL PROFE QUE LO PUSIERAMOS ASI (Jose Carlos)
        if(vec.size()<=0) cout<<"No hay nada declarado todavia de este tipo"<<endl;
        else{
            for(int i=0; i<static_cast<int>(vec.size());i++){
                cout<<i+1<<". ---> "<<*vec[i]<<endl;
            }
        }
    }
    template<typename T> T* seleccionar(vector<T*>& vec){
        Recorrer(vec);
        tecla=seleccion_invalida(1,vec.size());
        return vec[tecla-1];
    }

    //Combate
    bool InicioCombate(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Muertos);
    void menucombate (vector<Equipo*>& Partida, vector<Personajes*>& Muertos, vector<string*>& Nombres, bool turno);
    void LanzarHechizo(vector<Equipo *>& Lista_Equipos, Mago* Atacante, bool& turno, ofstream& archivo);
    void LanzarPocion(Personajes* Personaje, vector<Equipo*>& Partida, bool& turno, ofstream& archivo);

     //Funciones varias
    void comprobarSalud(Equipo* Defensor,Personajes* personaje ,vector<Personajes*>& Muertos);
    int seleccion_invalida(int LI, int LS);
    void espera();
    string to_uppercase(string& linea);
    bool esNumero(string &linea);
    template<typename T> void liberar_memoria(vector<T*>& vec){ for(auto objeto : vec) delete objeto; vec.clear(); }
    ~Funciones();
};

#endif // FUNCIONES_H
