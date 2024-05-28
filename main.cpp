#include <funciones.h>


using namespace std;

int main() {
    Funciones funcion;
    Objetos *objeto=new Armas("ElPalo","BACULO",100);
    Objetos *objeto2=new Pociones("lacurativa", "SALUD", 100);
    Objetos *objeto3=new Armas("ElLargo","DISTANCIA", 100);
    Personajes *personaje=new Mago("Julian");
    Personajes *personaje2=new Arquero("Gordito");
    Equipo *equipo=new Equipo("Losduros");
    Hechizos *hechizo=new Hechizos(50, "TIERRA", "Placas");
    *personaje>>objeto>>objeto2;
    *personaje2>>objeto2>>objeto3;
    if(Mago *tmp=dynamic_cast<Mago*>(personaje)) *tmp>>hechizo;
    Graveyard cementerio;
    vector<Equipo*> Lista_Equipos;
    vector<Personajes*> Lista_Personajes;
    vector<Objetos*> Lista_Objetos;
    vector<Hechizos*> Lista_Hechizos;
    vector<Personajes*> Cementerio;
    funcion.setAtributos(personaje);
    funcion.setAtributos(personaje2);
    Lista_Equipos.push_back(equipo);
    Lista_Objetos.push_back(objeto);
    Lista_Objetos.push_back(objeto2);
    Lista_Hechizos.push_back(hechizo);
    *Lista_Equipos[0]>>personaje>>personaje2;
    int tecla=0;
    cout << "Bienvenido a JuegoRPG2, ¿qué desea hacer?" << endl;
    while (tecla != 6) {
        this_thread::sleep_for(chrono::seconds(1));
        if(tecla!=0){
            funcion.espera();
        }
        system("clear");
        cout <<blanco<<RED<< "------MENU PRINCIPAL------"<<endl;
        cout << "1. Menu de carga          \n2. Menu de creacion       \n3. Menu de Modificaciones \n4. Menu de Juego          \n5. Menu de Display        \n6. Salir                  "<<RESET<<endl;
        cin >> tecla;
        switch (tecla) {
        case 1: {
            while (tecla != 11) {
                funcion.espera();
                system("clear");
                cout << "---MENU DE CARGA---"<<endl;
                cout << "1. Cargar arbol"<<endl<<"2. Guardar arbol"<<endl<<"3. Cargar los objetos"<<endl<<"4. Guardar los objetos"<<endl;
                cout << "5. Cargar personajes Sin Equipo"<<endl<<"6. Guardar Personaje Sin Equipo"<<endl<<"7. Cargar Hechizos"<<endl<<"8. Guardar Hechizos"<<endl;
                cout << "9. Cargar Hechizos"<<endl<<"10. Guardar Hechizos"<<endl<<"11. atras"<<endl;
                cin >> tecla;
                switch (tecla){
                case 1: funcion.cargar(Lista_Equipos,"GuardadoEquipos"); break;
                case 2: funcion.guardar(Lista_Equipos,"GuardadoEquipos"); break;
                case 3: funcion.cargar(Lista_Objetos,"GuardadoObjetos"); break;
                case 4: {
                    ofstream archivo("GuardadoObjetos");
                    funcion.guardar(Lista_Objetos,archivo);
                    archivo.close();
                    break;
                }
                case 5: funcion.cargar(Lista_Personajes,"GuardadoPersonajes"); break;
                case 6: funcion.guardar(Lista_Personajes,"GuardadoPersonajes"); break;
                case 7: funcion.cargar(Lista_Hechizos,"GuardadoHechizos"); break;
                case 8: //funcion.guardar(Lista_Hechizos, "GuardadoHechizos"); break;
                case 9:
                case 10:
                case 11: break;
                default: {
                    cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                    break;
                }
                }
            }
            break;
        }
        case 2: {
            while (tecla != 9) {
                funcion.espera();
                system("clear");
                cout << "----MENU DE CREACION----"<<endl;
                cout << "1. Crear un equipo      "<<endl<<"2. Eliminar un equipo   "<<endl<<"3. Crear un personaje   "<<endl<<"4. Eliminar un personaje" << endl;
                cout << "5. Crear un objeto      "<<endl<<"6. Eliminar un objeto   "<<endl<<"7. Crear Hechizo        "<<endl<<"8. Eliminar Hechizo     "<<endl<<"9. Atrás                " <<endl;
                cin >> tecla;
                switch (tecla) {
                case 1: funcion.crear_equipo(Lista_Equipos, Lista_Personajes); break;
                case 2: funcion.eliminar_equipo(Lista_Equipos); break;
                case 3: funcion.crear_personaje(Lista_Equipos,Lista_Personajes); break;
                case 4: funcion.eliminar_personaje(Lista_Equipos,Lista_Personajes); break;
                case 5: Lista_Objetos.push_back(funcion.crear_objeto()); break;
                case 6: funcion.eliminar_objeto(Lista_Objetos); break;
                case 7: Lista_Hechizos.push_back(funcion.crear_hechizo()); break;
                case 8: funcion.eliminar_hechizo(Lista_Hechizos); break;
                case 9: break;
                default: {
                    cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                    break;
                }
                }
            }
            break;
        }
        case 3:{
            funcion.espera();
            system("clear");
            cout<<"---MENU DE MODIFICACIONES---"<<endl;
            cout<<"1. Modificar Arbol"<<endl<<"2. Modificar Personaje sin Equipo"<<endl<<"3. Modificar Objeto"<<endl<<"4. Modificar Hechizos"<<endl<<"5. Salir"<<endl;
            tecla=funcion.seleccion_invalida(1,5);
            switch(tecla){
            case 1: funcion.modificar_equipo(Lista_Equipos, Lista_Personajes, Lista_Objetos, Lista_Hechizos); break;
            case 2:{
                if(Lista_Personajes.size()<=0){
                    cout<<"No hay Personajes sin Equipo"<<endl;
                    break;
                }
                Personajes *tmp=funcion.seleccionar_Personaje(Lista_Personajes);
                funcion.modificar_personaje(tmp, Lista_Objetos, Lista_Hechizos);
                break;
            }
            case 3: funcion.modificar_objetos(Lista_Objetos); break;
            case 4: funcion.modificar_hechizos(Lista_Hechizos); break;
            default: break;
            }
            break;
        }
        case 4: funcion.espera();
            cout<<"MENU DE JUEGO:" <<endl <<"1. Empezar combate"<<endl<<"2. Mostrar Log de combate anterior"<<endl<<"3. MODO PACIFICO "<<endl<<"4. Salir"<<endl;
            tecla=funcion.seleccion_invalida(1,4);
            switch(tecla){
            case 1: while(funcion.InicioCombate(Lista_Equipos, Cementerio)!=0); cementerio.set_Muertos(Cementerio);break;
            case 2:{
                ifstream archivo("Log.txt");
                if (!archivo.is_open()) {
                    cerr << "Error al abrir el archivo" <<endl;
                }
                string linea;
                while (getline(archivo, linea)) {
                    cout << linea << endl;
                } archivo.close();
                break;
            }
            case 3: cout<< "En este juego no hay posibilidad de ser pacifico, disfrute de las otras experiencias"<<endl;
                break;
            default:
                break;
            }


            break;
        case 5: {
            if(Lista_Equipos.size()<=0&&funcion.tamaño_equipos(Lista_Equipos)<=0&&Lista_Personajes.size()<=0&&Lista_Objetos.size()<=0){
                cout<<"No hay nada creado todavia"<<endl;
                break;
            }
            tecla=0;
            while(tecla!=5){
                funcion.espera();
                system("clear");
                cout<<"---MENU DE DISPLAY---"<<endl;
                cout<<"1. Arbol"<<endl<<"2. Personajes Sin Equipo"<<endl<<"3. Objetos"<<endl<<"4. Hechizos"<<endl<<"5. Salir"<<endl;
                tecla=funcion.seleccion_invalida(1,5);
                switch(tecla){
                case 1:{
                    Equipo* Equipo;
                    system("clear");
                    if(Lista_Equipos.size()<=0){
                        cout<<"No hay equipos todavia"<<endl;
                        break;
                    }
                    Equipo=funcion.seleccionar_Equipo(Lista_Equipos);
                    if(Equipo->gettamaño()<=0){
                        cout<<"Este equipo no tiene Personajes"<<endl;
                        break;
                    }
                    funcion.Recorrer(Equipo->getLista_Personajes());
                    break;
                }
                case 2: funcion.Recorrer(Lista_Personajes); break;
                case 3: funcion.Recorrer(Lista_Objetos); break;
                case 4: funcion.Recorrer(Lista_Hechizos); break;
                default: break;
                }
            }
            break;
        }
        case 6: {
            break;
        }
        default: {
            cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
            break;
        }
        }
        if(tecla ==6){
            cout<<"Esta seguro de que quiere salir?"<<endl<<"1. SI"<<endl<<"2. NO"<<endl;
            tecla=funcion.seleccion_invalida(1,2);
            (tecla==1) ? tecla=6 : tecla=0;
        }
    }
    cout << "Hasta la próxima" << endl;
    funcion.liberar_memoria(Lista_Equipos);
    funcion.liberar_memoria(Lista_Objetos);
    funcion.liberar_memoria(Lista_Hechizos);
    funcion.liberar_memoria(Lista_Personajes);
    return 0;
}

