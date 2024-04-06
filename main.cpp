#include <funciones.h>

using namespace std;



int main(){
    Funciones funcion;
    int tecla = 0;
    while(tecla != 4){
        cout << "Bienvenido a JuegoRPG2, que desea hacer: "<<endl;
        cout << "1. Menu de carga  2. Menu de creacion  3. Menu de Juego 4. Salir"<<endl;
        cin >> tecla;
        switch(tecla){
            case 1:{
                while(tecla!=7){
                    cout << "1. Cargar los equipos    2. Guardar los equipos   3. Cargar los objetos   4. Guardar los objetos"<<endl;
                    cout << "5. Cargar personajes  6. Guardar Personaje  7. atras" <<endl;
                    cin >> tecla;
                    switch(tecla){
                        case 1:{
                            funcion.cargar();
                            break;
                        }
                        case 2:{
                            funcion.guardar();
                            break;
                        }
                        case 3:{
                            funcion.cargar();
                            break;
                        }
                        case 4:{
                            funcion.guardar();
                            break;
                        }
                        case 5:{
                            funcion.cargar();
                            break;
                        }
                        case 6:{
                            funcion.guardar();
                            break;
                        }
                        case 7:{
                            break;
                        }
                        default:{
                            cout<<"No has introducido una tecla valida, se volvera al menú anterior"<<endl;
                            break;
                        }
                    }
                }
                break;
            }


            case 2:{
                while(tecla!=7){
                    cout << "1. Crear un equipo  2. Eliminar un equipo  3. Crear un personaje  4. Eliminar un personaje" <<endl;
                    cout <<"5. Crear un objeto  6. Eliminar un objeto  7. atras"<<endl;
                    cin >> tecla;
                    switch(tecla){
                        case 7:
                            break;
                    }
                    break;
                }
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            default:{
                cout<<"No has introducido una tecla valida, se volvera al menú anterior"<<endl;
                break;
            }
        }
    }
    cout << "Hasta la proxima" << endl;





                                        //Ejemplo de guardar objetos en txt
    vector<Objetos*> Lista_Objetos;
    Lista_Objetos.push_back(new Armas("Arma", "julian", "Cortante", 46));
    Lista_Objetos.push_back(new Armas("Arma", "Pepe", "Contundente", 50));
    Lista_Objetos.push_back(new Armas("Arma", "Monica", "Gorda", 1000000));
    funcion.guardar(Lista_Objetos, "ObjetosPrueba.txt");
    for(auto objeto : Lista_Objetos){
        delete objeto;
    }


        //Ejemplo de como se cargarian objetos desde txt en el programa

    if( funcion.contarLineas("objetos.txt") < 0) cout<<"No hay suficientes objetos"<<endl;
    else{
        vector<Objetos*> Lista_Objetos;
        funcion.cargar(Lista_Objetos,"objetos.txt");
        for (int i=0;i<static_cast<int>(Lista_Objetos.size());i++){
            Lista_Objetos[i]->display();
            delete Lista_Objetos[i];
        }
    }

    /* Personajes **lista = new Personajes*[3];  //Ejemplo de como seria poner una lista de personajes en equipo
    lista[0] = new Guerrero;
    lista[1] = new Guerrero;
    lista[2] = new Guerrero;
    lista[0]->setName("pepe");
    lista[1]->setName("juan");
    lista[2]->setName("Lola");
    Equipo equipo("equipo",3);
    equipo.setLista_Personajes(lista);
    for(int i=0;i<3;i++){
        delete lista[i];
    }
    cout<<endl;
    equipo.display(); */

}
