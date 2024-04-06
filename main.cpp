#include <funciones.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    Funciones funcion;
    vector<Equipo*> Lista_Equipos;
    int tecla = 0;
    cout << "Bienvenido a JuegoRPG2, ¿qué desea hacer?" << endl;
    while (tecla != 4) {
        this_thread::sleep_for(chrono::seconds(1));
        system("clear");
        cout << "1. Menu de carga  2. Menu de creacion  3. Menu de Juego  4. Salir" << endl;
        cin >> tecla;
        switch (tecla) {
            case 1: {
                while (tecla != 7) {
                    cout << "1. Cargar los equipos    2. Guardar los equipos   3. Cargar los objetos   4. Guardar los objetos" << endl;
                    cout << "5. Cargar personajes  6. Guardar Personaje  7. Atrás" << endl;
                    cin >> tecla;
                    switch (tecla) {
                        case 1: {
                            funcion.cargar();
                            break;
                        }
                        case 2: {
                            funcion.guardar();
                            break;
                        }
                        case 3: {
                            funcion.cargar();
                            break;
                        }
                        case 4: {
                            funcion.guardar();
                            break;
                        }
                        case 5: {
                            funcion.cargar();
                            break;
                        }
                        case 6: {
                            funcion.guardar();
                            break;
                        }
                        case 7: {
                            break;
                        }
                        default: {
                            cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                            break;
                        }
                    }
                }
                break;
            }


            case 2: {
                while (tecla != 7) {
                    this_thread::sleep_for(chrono::seconds(1));
                    system("clear");
                    cout << "1. Crear un equipo"<<endl<<"2. Eliminar un equipo"<<endl<<"3. Crear un personaje"<<endl<<"4. Eliminar un personaje" << endl;
                    cout << "5. Crear un objeto"<<endl<<"6. Eliminar un objeto"<<endl<<"7. Atrás" << endl;
                    cin >> tecla;
                    switch (tecla) {
                        case 1: {
                            string *nombre=new string;
                            cout<<"Como quieres nombrar el equipo: "<<endl;
                            cin>>*nombre;
                            Lista_Equipos.push_back(new Equipo(*nombre));
                            delete nombre;
                            break;
                        }
                        case 2: {
                            if(static_cast<int>(Lista_Equipos.size())<=0){
                                cout<<"No hay ningun equipo disponible actualmente"<<endl;
                            }
                            else{
                                int *seleccion=new int;
                                cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
                                for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
                                    cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
                                }
                                cout<<"Cual de ellos quieres borrar? "<<endl;
                                cin>>*seleccion;
                                if (*seleccion > 0 && *seleccion <= static_cast<int>(Lista_Equipos.size())){
                                    cout<<"Equipo seleccionado para borrar con nombre: "<<Lista_Equipos[*seleccion-1]->getName()<<endl;
                                    auto it = Lista_Equipos.begin() + *seleccion - 1;
                                    delete *it;
                                    Lista_Equipos.erase(it);
                                    cout << "El equipo ha sido eliminado correctamente." << endl;
                                } else {
                                    cout << "Selección inválida." << endl;
                                }
                                delete seleccion;
                            }
                            break;
                        }
                        case 3: {
                            break;
                        }
                        case 4: {
                            break;
                        }
                        case 5: {
                            break;
                        }
                        case 6: {
                            break;
                        }
                        case 7: {
                            break;
                        }
                        default: {
                            cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                            break;
                        }
                    }
                }
                break;
            }


            case 3: {
                break;
            }


            case 4: {
                break;
            }


            default: {
                cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                break;
            }
        }
    }
    cout << "Hasta la próxima" << endl;






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

    return 0;
}
