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
        cout << "1. Menu de carga (no disponible)"<<endl<<"2. Menu de creacion"<<endl<<"3. Menu de Juego"<<endl<<"4. Menu de Display" <<endl<<"5. Salir"<<endl;
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
                            if(Lista_Personajes.size()<=0){
                                cout<<"Actualmente no hay ningun Personaje sin Equipo disponible"<<endl;
                            }else{
                                cout<<"Actualmente hay: "<<Lista_Personajes.size()<<" Personajes sin Equipo"<<endl;
                                for(int i=0; i< static_cast<int>(Lista_Personajes.size());i++){
                                    cout<<"Personaje numero: "<< i+1 <<" Nombre del Personaje: "<<Lista_Personajes[i]->getName()<<endl;
                                }
                                cout<<"Cual de ellos quieres añadir al equipo? "<<endl;
                                cin>>tecla;
                                while(tecla <= 0 || tecla> static_cast<int>(Lista_Personajes.size())){
                                    cout << "Seleccion invalida" <<endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cin>>tecla;
                                }
                                cout<<"Personaje seleccionado para añadir con nombre: "<<Lista_Personajes[tecla-1]->getName()<<endl;
                                Lista_Equipos[Lista_Equipos.size()-1]->setLista_Personajes(Lista_Personajes[tecla-1]);
                                auto it = Lista_Personajes.begin() + tecla - 1;
                                delete *it;
                                Lista_Personajes.erase(it);
                                cout << "El Personaje ha sido eliminado correctamente." << endl;
                            }
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
                                while(tecla <= 0 || tecla> static_cast<int>(Lista_Equipos.size())){
                                    cout << "Seleccion invalida" <<endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tecla;
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
                                funcion.setAtributos(1,Lista_Personajes);
                            }
                            else{
                                funcion.setAtributos(0,Lista_Personajes);
                            }
                            cout << "Quieres añadir el nuevo personaje a un equipo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
                            cin>>tecla;
                            while(tecla!=1 && tecla!=2){
                                cout << "Seleccion invalida" << endl;
                                cout << "Por favor, selecciona 1 o 2: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tecla;
                            }
                            if(tecla==1){
                                if(static_cast<int>(Lista_Equipos.size())<=0){
                                    cout << "Actualmente no hay ningun equipo disponible"<<endl;
                                    cout << "Le recuerdo que para usar el personaje debera añadirlo a un equipo"<<endl;

                                }
                                else{
                                    cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
                                    for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
                                        cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
                                    }
                                    cout<<"A cual de ellos quieres meter el nuevo personaje? "<<endl;
                                    cin>>tecla;
                                    while(tecla <= 0 || tecla > static_cast<int>(Lista_Equipos.size())){
                                        cout << "Seleccion invalida" << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin >> tecla;
                                    }
                                    cout<<"Equipo seleccionado con nombre: "<<Lista_Equipos[tecla-1]->getName()<<endl;
                                    Lista_Equipos[tecla-1]->setLista_Personajes(Lista_Personajes[Lista_Personajes.size()-1]);
                                    cout << "El nuevo personaje ha sido añadido, asi queda el equipo: " << endl;
                                    Lista_Equipos[tecla-1]->display();
                                    auto it = Lista_Personajes.begin() + tecla - 1;
                                    delete *it;
                                    Lista_Personajes.erase(it);
                                }
                            }
                            else{
                                cout << "Le recuerdo que para usar el personaje debera añadirlo a un equipo"<<endl;
                            }
                            this_thread::sleep_for(chrono::seconds(3));
                            break;
                        }
                        case 4: {
                            cout << "Quieres eliminar un personaje con o sin equipo?"<<endl<<"1. con "<<endl<<"2. sin"<<endl;
                            cin>>tecla;
                            while(tecla!=1 && tecla !=2){
                                cout << "Seleccion invalida" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tecla;
                            }
                            if(tecla==1){
                                if(static_cast<int>(Lista_Equipos.size())<=0){
                                    cout<<"No hay ningun equipo disponible actualmente"<<endl;
                                }
                                else{
                                    cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
                                    for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
                                        cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
                                    }
                                    cout<<"De cual de ellos quieres coger el personaje? "<<endl;
                                    cin>>tecla;
                                    while(tecla < 0 || tecla> static_cast<int>(Lista_Equipos.size())){
                                        cout << "Seleccion invalida" << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin >> tecla;
                                    }
                                    if(Lista_Equipos[tecla-1]->gettamaño()<=0){
                                        cout << "Has elegido el equipo: "<<Lista_Equipos[tecla-1]->getName()<<endl;
                                        cout << "Pero este equipo no tiene ningun personaje miembro"<<endl;
                                        cout << "Se te devolvera al menu anterior" <<endl;
                                    }
                                    else{
                                        cout << "Has elegido el equipo: "<<endl;
                                        Lista_Equipos[tecla-1]->display();
                                        cout << "Cual personaje quieres eliminar?" <<endl;
                                        for(int i=0;i < Lista_Equipos[tecla-1]->gettamaño();i++){
                                            cout <<i+1<<". "<<Lista_Equipos[tecla-1]->getLista_Personajes()[i]->getName()<<endl;
                                        }
                                        int *temp = new int;
                                        cin>>*temp;
                                        while(*temp <=0 && *temp > Lista_Equipos[tecla-1]->gettamaño()){
                                            cout << "Seleccion invalida" << endl;
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cin >> tecla;
                                        }
                                        cout << "Has seleccionado:"<<endl;
                                        cout << "Personaje con nombre: " << Lista_Equipos[tecla-1]->getLista_Personajes()[*temp-1]->getName();
                                        cout << " del Equipo: "<< Lista_Equipos[tecla-1]->getName()<<endl;
                                        Lista_Equipos[tecla-1]->borrarPersonaje(*temp);
                                        cout <<endl<< "Ahora el equipo pasa a ser:"<<endl;
                                        Lista_Equipos[tecla-1]->display();

                                    }
                                }
                            }
                            else{
                                if(static_cast<int>(Lista_Personajes.size())<=0){
                                    cout<<"No hay ningun personaje sin equipo disponible actualmente"<<endl;
                                }
                                else{
                                    cout<<"Actualmente hay: "<<Lista_Personajes.size()<<" Personajes"<<endl;
                                    for(int i=0; i< static_cast<int>(Lista_Personajes.size());i++){
                                        cout<<"Personaje numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Personajes[i]->getName()<<endl;
                                    }
                                    cout<<"Cual de ellos quieres borrar? "<<endl;
                                    cin>>tecla;
                                    while(tecla < 0 || tecla> static_cast<int>(Lista_Personajes.size())){
                                        cout << "Seleccion invalida" << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin >> tecla;
                                    }
                                    cout<<"Personaje seleccionado para borrar con nombre: "<<Lista_Personajes[tecla-1]->getName()<<endl;
                                    auto it = Lista_Personajes.begin() + tecla - 1;
                                    delete *it;
                                    Lista_Personajes.erase(it);
                                    cout << "El personaje ha sido eliminado correctamente." << endl;
                            }
                        }
                            this_thread::sleep_for(chrono::seconds(3));
                            break;

                        }
                        case 5: {
                            cout << "Actualmente, como esto es la entrega 2, esta parte del codigo solo esta disponible con las pequeñas demos que hay abajo del main"<<endl;
                            cout << "Puedes descomentar y probar el funcionamiento de las mismas descomentando las lineas"<<endl;
                            break;
                        }
                        case 6: {
                            cout << "Actualmente, como esto es la entrega 2, esta parte del codigo solo esta disponible con las pequeñas demos que hay abajo del main"<<endl;
                            cout << "Puedes descomentar y probar el funcionamiento de las mismas descomentando las lineas"<<endl;
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
                cout << "Actualmente, como esto es la entrega 2, esta parte del codigo solo esta disponible con las pequeñas demos que hay abajo del main"<<endl;
                cout << "Puedes descomentar y probar el funcionamiento de las mismas descomentando las lineas"<<endl;
                break;
            }
            case 4: {
                cout<<"Estas en el menú de Display, que deseas hacer?: "<<"1. Display de los Equipos"<<endl<<"2. Display de los Personajes con Equipo"<<endl<<"3. Display de los Personajes sin Equipo"<<endl;
                cin>>tecla;
                while(tecla <=0 || tecla>=4){
                    cout << "Seleccion invalida" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> tecla;
                }
                switch(tecla){
                    case 1:{

                    }
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "No has introducido una tecla válida, se volverá al menú anterior" << endl;
                break;
            }
        }
    }
    cout << "Hasta la próxima" << endl;






    //Ejemplo de crear y guardar objetos en txt
    /*vector<Objetos*> Lista_Objetos;
    Lista_Objetos.push_back(new Armas("Arma", "julian", "Cortante", 46));
    Lista_Objetos.push_back(new Armas("Arma", "Pepe", "Contundente", 50));
    Lista_Objetos.push_back(new Pociones("Pocion", "ladolorosa", "Salud", 100));
    funcion.guardar(Lista_Objetos, "ObjetosPrueba.txt");
    for(auto objeto : Lista_Objetos){
        delete objeto;
    }*/


   //Ejemplo de como se instanciarian objetos cargandolos desde txt en el programa

    /*if(funcion.contarLineas("ObjetosPrueba.txt") < 0) cout<<"No hay suficientes objetos"<<endl;
    else{
        vector<Objetos*> Lista_Objetos;
        funcion.cargar(Lista_Objetos,"ObjetosPrueba.txt");
        for (int i=0;i<static_cast<int>(Lista_Objetos.size());i++){
            Lista_Objetos[i]->display();
            delete Lista_Objetos[i];
        }
    }*/

    //ejemplo de ataque y defensa de un personaje (si salen numeros mas grandes de salud, es porque no estan metidas las armas todavia
    /* vector<Personajes*> Personajes;
    Personajes.push_back(new Guerrero("Pepito"));
    Personajes.push_back(new Arquero("Fulanito"));
    for(auto objeto : Personajes){
        objeto->setAtributos(0);
        objeto->Display();
        cout<<endl;
    }
    if(Personajes[0]->tirar_dados() < Personajes[0]->getAtributos(3)){
        cout << "Ataque efectivo"<<endl;
        int ataque = Personajes[0]->Ataque();
        int defensa = Personajes[1]->Defensa();
        int salud = Personajes[1]->getAtributos(1);
        Personajes[1]->setAtributos(salud-(ataque-defensa), 1);
        cout << "Nuevas estadisticas de: "<<Personajes[1]->getName()<<endl<<endl;
        Personajes[1]->Display();
    }
    else{
        cout << "Ataque inefectivo"<<endl;
    } */

    return 0;
}
