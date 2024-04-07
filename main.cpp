#include <funciones.h>


using namespace std;

int main() {
    Funciones funcion;
    vector<Equipo*> Lista_Equipos;
    vector<Personajes*> Lista_Personajes;
    int tecla = 0;
    cout << "Bienvenido a JuegoRPG2, ¿qué desea hacer?" << endl;
    while (tecla != 4) {
        this_thread::sleep_for(chrono::seconds(1));
        system("clear");
        cout << "---MENU PRINCIPAL---"<<endl;
        cout << "1. Menu de carga (no disponible)"<<endl<<"2. Menu de creacion"<<endl<<"3. Menu de Juego"<<endl<<"4. Salir" << endl;
        cin >> tecla;
        switch (tecla) {
            case 1: {
                while (tecla != 7) {
                    this_thread::sleep_for(chrono::seconds(1));
                    system("clear");
                    cout << "---MENU DE CARGA---"<<endl;
                    cout << "1. Cargar los equipos"<<endl<<"2. Guardar los equipos"<<endl<<"3. Cargar los objetos"<<endl<<"4. Guardar los objetos"<< endl;
                    cout << "5. Cargar personajes"<<endl<<"6. Guardar Personaje"<<endl<<"7. Atrás" << endl;
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
                    cout << "---MENU DE CREACION---"<<endl;
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
                                cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
                                for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
                                    cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
                                }
                                cout<<"Cual de ellos quieres borrar? "<<endl;
                                cin>>tecla;
                                while(tecla < 0 && tecla>=static_cast<int>(Lista_Equipos.size())){
                                    cout << "Seleccion invalida" <<endl;
                                    cin>>tecla;
                                }
                                cout<<"Equipo seleccionado para borrar con nombre: "<<Lista_Equipos[tecla-1]->getName()<<endl;
                                auto it = Lista_Equipos.begin() + tecla - 1;
                                delete *it;
                                Lista_Equipos.erase(it);
                                cout << "El equipo ha sido eliminado correctamente." << endl;
                            }
                            break;
                        }
                        case 3: {
                            string *name=new string;
                            cout << "Como quieres llamar al personaje?" <<endl;
                            cin >> *name;
                            cout << "De que tipo quieres que sea el personaje? "<<endl<< "1. Mago" <<endl<<"2. Guerrero"<<endl<<"3. Arquero"<<endl;
                            cin >>tecla;
                            while(tecla!=1 && tecla!=2 && tecla!=3){
                                cout << "Seleccion invalida" << endl;
                                cin>>tecla;
                            }
                            if(tecla == 1){
                                Lista_Personajes.push_back(new Mago(*name));
                            }
                            else if(tecla ==2){
                                Lista_Personajes.push_back(new Guerrero(*name));
                            }
                            else{
                                Lista_Personajes.push_back(new Arquero(*name));
                            }
                            cout << "Como quieres asignarle los atributos?" <<endl<<"1. Random (El niver será 1)"<<endl<<"2. Manualmente"<<endl;
                            cin>>tecla;
                            while(tecla!=1 && tecla!=2){
                                cout << "Seleccion invalida" <<endl;
                                cin>>tecla;
                            }
                            if(tecla==1){
                                Lista_Personajes[Lista_Personajes.size()-1]->setAtributos(0);
                            }
                            else{
                                Lista_Personajes [Lista_Personajes.size()-1]->setAtributos(1);
                            }
                            cout << "Quieres añadir el nuevo personaje a un equipo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
                            cin>>tecla;
                            while(tecla!=1 && tecla!=2){
                                cout <<"Seleccion invalida"<<endl;
                                cin>>tecla;
                            }
                            if(tecla==1){
                                cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
                                for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
                                    cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
                                }
                                cout<<"A cual de ellos quieres meter el nuevo personaje? "<<endl;
                                cin>>tecla;
                                while(tecla < 0 && tecla>=static_cast<int>(Lista_Equipos.size())){
                                    cout << "Seleccion invalida" <<endl;
                                    cin>>tecla;
                                }
                                cout<<"Equipo seleccionado con nombre: "<<Lista_Equipos[tecla-1]->getName()<<endl;
                                Lista_Equipos[tecla-1]->setLista_Personajes(Lista_Personajes[Lista_Personajes.size()-1]);
                                cout << "El nuevo personaje ha sido añadido, asi queda el equipo: " << endl;
                                Lista_Equipos[tecla-1]->display();
                            }
                            else{

                            }
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
    /* vector<Objetos*> Lista_Objetos;
    Lista_Objetos.push_back(new Armas("Arma", "julian", "Cortante", 46));
    Lista_Objetos.push_back(new Armas("Arma", "Pepe", "Contundente", 50));
    Lista_Objetos.push_back(new Armas("Arma", "Monica", "Gorda", 1000000));
    funcion.guardar(Lista_Objetos, "ObjetosPrueba.txt");
    for(auto objeto : Lista_Objetos){
        delete objeto;
    } */


        //Ejemplo de como se cargarian objetos desde txt en el programa

    /* if( funcion.contarLineas("objetos.txt") < 0) cout<<"No hay suficientes objetos"<<endl;
    else{
        vector<Objetos*> Lista_Objetos;
        funcion.cargar(Lista_Objetos,"objetos.txt");
        for (int i=0;i<static_cast<int>(Lista_Objetos.size());i++){
            Lista_Objetos[i]->display();
            delete Lista_Objetos[i];
        }
    } */

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
