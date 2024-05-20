#include "funciones.h"
Funciones::Funciones(){
    tecla=0;
}

//-----------------------------Archivos------------------------------------
int Funciones::contarLineas(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return -1;
    }
    int contador = 0;
    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            contador++;
        }
    }
    archivo.close();
    return contador;
}

void Funciones::cargar(vector<Objetos*>& objetos, const string& nombreArchivo) {
    ifstream archivo("archivo.txt"); // Nombre de tu archivo .txt
        vector<string> texto_despues_de_gt;

        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                size_t pos_gt = linea.find('>');
                if (pos_gt != string::npos && pos_gt + 1 < linea.size()) {
                    string texto_despues = linea.substr(pos_gt + 1);
                    texto_despues_de_gt.push_back(texto_despues);
                }
            }
            archivo.close();
        }
}
/*void Funciones::cargar(vector<Personajes*>& personajes, const string& nombreArchivo){

}
*/
void Funciones::guardar(vector<Personajes*> personajes, const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (auto objeto : personajes) {
            archivo<<"                                     ->";
            objeto->serializar(archivo);
            guardar(objeto->getInventario(),archivo);
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
}
void Funciones::guardar(vector<Objetos*> objetos, ofstream &archivo) {
    if (archivo.is_open()) {
        for (auto objeto : objetos) {
            archivo<<" ---->";
            objeto->serializar(archivo);
        }
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
}
void Funciones::guardar(vector<Equipo*> equipos, const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < static_cast<int>(equipos.size()); i++) {
            archivo<< "EQUIPO: \n ->"<<equipos[i]->getName()<<":\n";
            for (auto objeto : equipos[i]->getLista_Personajes()) {
                archivo<<" -->";
                objeto->serializar(archivo);
                if(objeto->getInventario().size()>0)
                {
                    guardar(objeto->getInventario(),archivo);
                }
            }
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
}



//----------------------------Gestion Atributos-------------------------------------------
void Funciones::setAtributos(bool random, Arquero* A)
{
    A->setAtributos(1,0); //nivel
    if(random==1)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        A->setAtributos(0 + rand() % (100-0+1),1); //salud
        A->setAtributos(0 + rand() % (30-0+1),2); //poder
        A->setAtributos(1 + rand() % (12-1+1),3); //precisión
        A->setAtributos(20 + rand() % (40-20+1),4); //protección
        A->setAtributos(1 + rand() % (10-1+1),5); //agilidad
        A->setAtributos(1 + rand() % (15-1+1),6); //carcaj
    }else
    {
        cout << "Dime la salud de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout << "Dime el poder de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (20-40)"<< endl;
        A->setAtributos(seleccion_invalida(20,40),4);
        cout << "Dime la agilidad de tu personaje (1-10)"<< endl;
        A->setAtributos(seleccion_invalida(1,10),5);
        cout << "Dime las flechas que tiene tu personaje en el carcaj (1-15)"<< endl;
        A->setAtributos(seleccion_invalida(1,15),6);
    }
}
void Funciones::setAtributos(bool random, Guerrero* A)
{
    A->setAtributos(1,0); //nivel
    if(random==1)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        A->setAtributos(0 + rand() % (100-0+1),1); //salud
        A->setAtributos(0 + rand() % (30-0+1),2); //poder
        A->setAtributos(1 + rand() % (12-1+1),3); //precisión
        A->setAtributos(15 + rand() % (30-15+1),4); //protección
        A->setAtributos(0 + rand() % (30-0+1),5); //escudo
        A->setAtributos(1 + rand() % (15-1+1),6); //fuerza
    }else
    {
        cout << "Dime la salud de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout << "Dime el poder de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (15-30)"<< endl;
        A->setAtributos(seleccion_invalida(15,30),4);
        cout << "Dime el escudo de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),5);
        cout << "Dime la fuerza de tu personaje (1-15)"<< endl;
        A->setAtributos(seleccion_invalida(1,15),6);
    }
}
void Funciones::setAtributos(bool random, Mago* A)
{
    A->setAtributos(1,0); //nivel
    if(random==1)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        A->setAtributos(0 + rand() % (100-0+1),1); //salud
        A->setAtributos(50 + rand() % (70-50+1),2); //poder
        A->setAtributos(1 + rand() % (12-1+1),3); //precisión
        A->setAtributos(50 + rand() % (60-50+1),4); //protección
        A->setAtributos(0 + rand() % (100-0+1),5); //mana
    }else
    {
        cout << "Dime la salud de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout << "Dime el poder de tu personaje (50-70)"<< endl;
        A->setAtributos(seleccion_invalida(50,70),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (50-60)"<< endl;
        A->setAtributos(seleccion_invalida(50,60),4);
        cout << "Dime el mana de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),5);
    }
}
void Funciones::setAtributos(Personajes* Personaje){
    bool random;
    cout << "Como quieres asignarle los atributos?" <<endl<<"1. Random (El niver será 1)"<<endl<<"2. Manualmente"<<endl;
    tecla=seleccion_invalida(1,2);
    (tecla==1) ? random=1 : random=0;
    if(Arquero *tmp=dynamic_cast<Arquero*>(Personaje)){
        setAtributos(random,tmp);
    } else if(Mago *tmp=dynamic_cast<Mago*>(Personaje)){
        setAtributos(random,tmp);
    }else if(Guerrero *tmp=dynamic_cast<Guerrero*>(Personaje)){
        setAtributos(random,tmp);
    }
}
void Funciones::setAtributos(bool random, Armas *Arma){
    srand(static_cast<unsigned int>(time(nullptr)));
    if(Arma->getTipo()=="CORTANTE"){
        Arma->setPower(setAtributos(random,0,30));
    }else if(Arma->getTipo()=="CONTUNDENTE"){
        Arma->setPower(setAtributos(random,0,50));
    }else if(Arma->getTipo()=="DISTANCIA"){
        Arma->setPower(setAtributos(random,0,70));
    }else{
        Arma->setPower(setAtributos(random,0,40));
    }
}
void Funciones::setAtributos(bool random, Pociones *Pocion){
    srand(static_cast<unsigned int>(time(nullptr)));
    Pocion->setPower(setAtributos(random,0,100));
}
int Funciones::setAtributos(bool random,int LI,int LS){
    if(random==1){
        return (LI + rand() % (LS-LI+1));
    }else{
        int poder;
        cout<<"Introduce un valor para el poder"<<endl;
        poder = seleccion_invalida(LI,LS);
        return poder;
    }
}
void Funciones::setAtributos(Objetos* Objeto){
    bool random;
    cout << "Como quieres asignarle el poder?" <<endl<<"1. Random"<<endl<<"2. Manualmente"<<endl;
    tecla = seleccion_invalida(1,2);
    (tecla==1) ? random=1 : random=0;
    if(Armas *tmp=dynamic_cast<Armas*>(Objeto)){
        setAtributos(random,tmp);
    } else if(Pociones *tmp=dynamic_cast<Pociones*>(Objeto)){
        setAtributos(random,tmp);
    }
}
void Funciones::modificar_atributos(Personajes *Personaje){
    cout<<*Personaje<<endl;
    cout<<"Que quieres hacer con el Personaje?"<<endl<<"1. Cambiar un atributo"<<endl<<"2. Cambiar todos"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        int atrib,pos;
        cout<<"Cual de ellos quieres cambiar?"<<endl<<*Personaje;
        for(unsigned int i=0;i<Personaje->getAtributos().size();i++){
            cout<<i+1<<". "<<Personaje->getAtributos()[i];
        }
        pos=seleccion_invalida(1,Personaje->getAtributos().size());
        cout<<"Introduce el nuevo atributo"<<endl;
        atrib=seleccion_invalida(1,100);
        Personaje->setAtributos(atrib,pos-1);
    }else{
        setAtributos(Personaje);
    }
}
//----------------------------Gestion Equipos---------------------------------------------
void Funciones::crear_equipo(vector<Equipo*>& Lista_Equipos, vector<Personajes *> &Lista_Personajes){
    string *nombre=new string;
    cout<<"Como quieres nombrar el equipo: "<<endl;
    cin>>*nombre;
    Lista_Equipos.push_back(new Equipo(*nombre));
    delete nombre;
    cout<<"Quieres añadir algun personaje al Equipo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        añadir_personaje(Lista_Equipos[Lista_Equipos.size()-1], Lista_Personajes);
    }else{
        cout<<"Le recuerdo que para usar el Equipo en un combate debera añadirle personajes"<<endl;
    }
}
void Funciones::eliminar_equipo(vector<Equipo *> &Lista_Equipos){
    if(static_cast<int>(Lista_Equipos.size())<=0){
        cout<<"No hay ningun equipo disponible actualmente"<<endl;
    }
    else{
        cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
        cout<<"Cual quieres borrar?"<<endl;
        seleccionar(Lista_Equipos);
        cout<<"Equipo seleccionado para borrar con nombre: "<<Lista_Equipos[tecla-1]->getName()<<endl;
        auto it = Lista_Equipos.begin() + tecla - 1;
        delete *it;
        Lista_Equipos.erase(it);
        cout << "El equipo ha sido eliminado correctamente." << endl;
    }
}
int Funciones::tamaño_equipos(vector<Equipo*>& Lista_Equipos){
    int tmp=0;
    for(auto objeto : Lista_Equipos){
        if(objeto->getLista_Personajes().size()>0){
            tmp++;
        }
    }
    return tmp;
}
Equipo* Funciones::seleccionar_Equipo(vector<Equipo*>& Lista_Equipos){
    cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl<<"Seleccione uno"<<endl;
    Equipo* tmp=seleccionar(Lista_Equipos);
    cout<<"Equipo seleccionado con nombre: "<<tmp->getName()<<endl;
    return tmp;
}
void Funciones::modificar_personaje(Equipo *Equipo, vector<Objetos *>& Lista_Objetos, vector<Hechizos *>& Lista_Hechizos){
    if(Equipo->gettamaño()>0){
        Personajes* Personaje_seleccionado;
        Personaje_seleccionado=seleccionar_Personaje(Equipo->getLista_Personajes());
        modificar_personaje(Personaje_seleccionado, Lista_Objetos, Lista_Hechizos);
    }else{
        cout<<"Este equipo no tiene personajes"<<endl;
    }
}
void Funciones::modificar_equipo(vector<Equipo *> &Lista_Equipos, vector<Personajes *> &Lista_Personajes, vector<Objetos *> &Lista_Objetos, vector<Hechizos *> &Lista_Hechizos){
    if(Lista_Equipos.size()<=0){
        cout<<"No hay Equipos"<<endl;
    }else{
        Equipo *Equipo_seleccionado;
        Equipo_seleccionado=seleccionar_Equipo(Lista_Equipos);
        while(tecla!=5){
            espera();
            system("clear");
            cout<<"Equipo: "<<*Equipo_seleccionado<<endl;
            cout<<"Que desea hacer ahora con este Equipo \n1. Cambiar nombre \n2. Añadir Personaje \n3. Eliminar Personaje \n4. Modificar Personaje \n5. Salir"<<endl;
            tecla=seleccion_invalida(1,5);
            switch(tecla){
                case 1:{
                    string name;
                    cout<<"Introduce un nuevo nombre"<<endl;
                    cin.clear();
                    cin.ignore();
                    getline(cin,name);
                    Equipo_seleccionado->setName(name);
                    break;
                }
                case 2: añadir_personaje(Equipo_seleccionado, Lista_Personajes); break;
                case 3: quitar_personaje(Equipo_seleccionado, Lista_Personajes); break;
                case 4: modificar_personaje(Equipo_seleccionado, Lista_Objetos, Lista_Hechizos); break;
                default: break;
            }
        }
    }
}

//----------------------------Gestion Objetos---------------------------------------------
Objetos* Funciones::crear_objeto(){
    string name;
    Objetos *objeto;
    cout<<"Como quiere llamar al objeto?:"<<endl;
    cin>>name;
    cout<<"De que tipo quieres que sea el objeto?"<<endl<<"1. Arma"<<endl<<"2. Poción"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        cout<<"De que tipo quieres que sea el Arma?:"<<endl<<"1. Cortante"<<endl<<"2. Contundente"<<endl<<"3. Distancia"<<endl<<"4. Báculos"<<endl;
        tecla=seleccion_invalida(1,4);
        if(tecla==1){
            objeto=new Armas(name,"CORTANTE");
        }
        else if(tecla==2){
            objeto=new Armas(name,"CONTUNDENTE");
        }
        else if(tecla==3){
            objeto=new Armas(name,"DISTANCIA");
        }
        else{
            objeto=new Armas(name,"BACULO");
        }
    } else{
        cout<<"De que tipo quieres que sea la pocion?: "<<endl<<"1. Salud"<<endl<<"2. Mana"<<endl;
       tecla=seleccion_invalida(1,2);
        if(tecla==1){
            objeto=new Pociones(name,"SALUD");
        }
        else{
            objeto=new Pociones(name,"MANA");
        }
    }
    setAtributos(objeto);
    return objeto;
}
void Funciones::modificar_objetos(Personajes *Personaje, vector<Objetos*>& Lista_Objetos){
    if(Personaje->getInventario().size()>0){
        cout<<"Los objetos del Personaje actualmente son: "<<endl;
        Recorrer(Personaje->getInventario());
        cout<<"Que desea hacer con ellos"<<endl<<"1. Añadir Objeto"<<endl<<"2. Eliminar Objeto"<<endl<<"3. Modificar un Objeto"<<endl<<"4. Atras"<<endl;
        tecla=seleccion_invalida(1,4);
        switch(tecla){
            case 1: añadir_objeto(Personaje, Lista_Objetos); tecla=1; break;
            case 2: eliminar_objeto(Personaje->getInventario()); tecla=2; break;
            case 3: modificar_objetos(Personaje->getInventario()); tecla=3; break;
            default: break;
        }
    }else{
        cout<<"Este Personaje no tiene objetos"<<endl;
    }
}
void Funciones::eliminar_objeto(vector<Objetos *> &Lista_Objetos){
    if(Lista_Objetos.size()>0){
        cout<<"Que objeto quieres eliminar?"<<endl;
        Objetos *objeto=seleccionar(Lista_Objetos);
        cout<<"Has seleccionado el objeto con nombre: "<<objeto->getName()<<endl;
        delete objeto;
        Lista_Objetos.erase(Lista_Objetos.begin()+tecla-1);
    }else{
        cout<<"No hay objetos"<<endl;
    }
}
void Funciones::añadir_objeto(Personajes *Personaje, vector<Objetos *> &Lista_Objetos){
    if(Lista_Objetos.size()>0){
        cout<<"Que Objeto quieres añadirle al Personaje? ten en cuenta el tipo de personaje ya que sino no te dejara añadirle el objeto"<<endl;
        Objetos* objeto=seleccionar(Lista_Objetos);
        cout<<"Has seleccionado el objeto: "<<endl<<*objeto<<endl;
        if(Personaje->comprobarInventario(objeto)==1){
            Personaje->setInventario(objeto);
            cout<<"Personaje añadido con exito"<<endl<<*Personaje<<endl;
        }else{
            cout<<"No se ha podido añadir el objeto, o bien el personaje ya tiene el maximo de objetos o no es compatible el tipo"<<endl;
        }
    }else{
        cout<<"No hay objetos"<<endl;
    }
}
void Funciones::modificar_objetos(vector<Objetos *> &Lista_Objetos){
    int tecla_pulsada=0;
    if(Lista_Objetos.size()>0){
        while(tecla_pulsada!=2){
            cout<<"Seleccione un objeto"<<endl;
            Objetos* tmp=seleccionar(Lista_Objetos);
            while(tecla_pulsada!=3){
                cout<<"Que desea hacer con el objeto: "<<tmp->getName()<<endl<<"1. Cambiar Nombre"<<endl<<"2. Cambiar Poder"<<endl<<"3. Atras"<<endl;
                tecla_pulsada=seleccion_invalida(1,3);
                if(tecla_pulsada==1){
                    cout<<"Introduce un nuevo nombre"<<endl;
                    string name;
                    cin.clear();
                    cin.ignore();
                    getline(cin,name);
                    tmp->setName(name);
                }else if(tecla_pulsada==2){
                    setAtributos(tmp);
                }
                cout<<"Asi ha quedado el Objeto: "<<endl<<*tmp<<endl;
            }
            cout<<"Desea cambiar algun objeto mas?"<<endl<<"1. SI"<<endl<<"2. NO"<<endl;
            tecla_pulsada=seleccion_invalida(1,2);
        }
    }else{
        cout<<"No hay objetos"<<endl;
    }
}

//------------------------------Gestion Personajes-------------------------------------
Personajes* Funciones::seleccionar_Personaje(vector<Equipo*>& Lista_Equipos){
    int tmp=tamaño_equipos(Lista_Equipos);
    cout<<"Elige un equipo con personajes: "<<endl;
    for(int i=0;i<static_cast<int>(Lista_Equipos.size());i++){
        if(Lista_Equipos[i]->gettamaño()>0){
            cout<<tmp<<". "<<Lista_Equipos[i]->getName()<<endl;
        }
    }
    tecla=seleccion_invalida(1,tmp);
    for(int i=0;i<tecla;i++){
        if(Lista_Equipos[i]->gettamaño()>0) tmp=i;
    }
    cout<<"Elige ahora uno de los personajes del Equipo: "<<endl;
    Lista_Equipos[tmp]->Display();
    tecla=seleccion_invalida(1,Lista_Equipos[tmp]->gettamaño());
    return Lista_Equipos[tmp]->getLista_Personajes()[tecla-1];
}
Personajes* Funciones::seleccionar_Personaje(vector<Personajes*>& Lista_Personajes){
    cout<<"Actualmente hay: "<<Lista_Personajes.size()<<" Personajes"<<endl;
    cout<<"Cual de ellos quieres seleccionar? "<<endl;
    Personajes *tmp=seleccionar(Lista_Personajes);
    cout<<"Personaje seleccionado con nombre: "<<tmp->getName()<<endl;
    return tmp;
}

void Funciones::añadir_personaje(Equipo* Equipo, vector<Personajes*>& Lista_Personajes){
    int tecla=0;
    while(tecla!=2){
        if(Lista_Personajes.size()<=0){
            cout<<"Actualmente no hay ningun Personaje sin Equipo o has asignado ya todos a un Equipo"<<endl;
            tecla=2;
        }else{
            cout<<"Elije un personaje para añadirlo"<<endl;
            Equipo->setLista_Personajes(seleccionar_Personaje(Lista_Personajes));
            Lista_Personajes.erase(Lista_Personajes.begin() + tecla - 1);
            cout << "El Personaje ha sido añadido correctamente. Desea añadir otro mas?" << endl;
            cout<<"1. SI"<<endl<<"2. NO"<<endl;
            tecla=seleccion_invalida(1,2);
        }
    }
}
void Funciones::crear_personaje(vector<Equipo *>& Lista_Equipos, vector<Personajes *>& Lista_Personajes){
    string *name=new string;
    cout << "Como quieres llamar al personaje?" <<endl;
    cin >> *name;
    cout << "De que tipo quieres que sea el personaje? "<<endl<< "1. Mago" <<endl<<"2. Guerrero"<<endl<<"3. Arquero"<<endl;
    tecla=seleccion_invalida(1,3);
    if(tecla == 1){
        Lista_Personajes.push_back(new Mago(*name));
    }
    else if(tecla ==2){
        Lista_Personajes.push_back(new Guerrero(*name));
    }
    else{
        Lista_Personajes.push_back(new Arquero(*name));
    }
    delete name;
    setAtributos(Lista_Personajes[Lista_Personajes.size()-1]);
    cout << "Quieres añadir el nuevo personaje a un equipo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        if(Lista_Equipos.size()>0){
            seleccionar_Equipo(Lista_Equipos)->setLista_Personajes(Lista_Personajes[Lista_Personajes.size()-1]);
        }else{
            cout<<"Actualmente no hay ningun Equipo creado"<<endl;
        }
    }else{
        cout<<"Le recuerdo que debera añadir el personaje a un equipo si quiere usarlo"<<endl;
    }
}
void Funciones::quitar_personaje(Equipo *Equipo, vector<Personajes *> &Lista_Personajes){
    if(Equipo->gettamaño()>0){
        cout<<"Selecciona un personaje para quitarlo"<<endl;
        seleccionar(Equipo->getLista_Personajes());
        int tmp=tecla;
        cout<<"Has seleccionado el Personaje con nombre: "<<Equipo->getLista_Personajes()[tecla-1]->getName()<<endl;
        cout<<"Quieres borrar el personaje permanentemente o dejarlo en la lista de personajes sin equipo?"<<endl<<"1. Borrarlo"<<endl<<"2. Guardarlo"<<endl;
        tecla=seleccion_invalida(1,2);
        if(tecla==1){
            delete Equipo->getLista_Personajes()[tmp-1];
            Equipo->getLista_Personajes().erase(Equipo->getLista_Personajes().begin()+tmp-1);
        }else{
            Lista_Personajes.push_back(Equipo->getLista_Personajes()[tmp-1]);
            Equipo->getLista_Personajes().erase(Equipo->getLista_Personajes().begin()+tmp-1);
        }
    }else{
        cout<<"Este equipo no tiene personajes"<<endl;
    }
}
void Funciones::eliminar_personaje(vector<Equipo *> &Lista_Equipos, vector<Personajes *> &Lista_Personajes){
    cout << "Quieres eliminar un personaje con o sin equipo?"<<endl<<"1. con "<<endl<<"2. sin"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        if(static_cast<int>(Lista_Equipos.size())<=0){
            cout<<"No hay ningun equipo disponible actualmente"<<endl;
        }
        else{
            Equipo *E;
            E=seleccionar_Equipo(Lista_Equipos);
            if(E->gettamaño()<=0){
                cout << "Has elegido el equipo: "<<E->getName()<<endl;
                cout << "Pero este equipo no tiene ningun personaje miembro"<<endl;
                cout << "Se te devolvera al menu anterior" <<endl;
            }
            else{
                cout << "Has elegido el equipo: "<<endl;
                E->Display();
                cout << "Cual personaje quieres eliminar?" <<endl;
                for(int i=0;i < E->gettamaño();i++){
                    cout <<i+1<<". "<<E->getLista_Personajes()[i]->getName()<<endl;
                }
                int *temp = new int;
                *temp=seleccion_invalida(1,E->gettamaño());
                cout << "Has seleccionado:"<<endl;
                cout << "Personaje con nombre: " << E->getLista_Personajes()[*temp-1]->getName();
                cout << " del Equipo: "<< E->getName()<<endl;
                E->borrarPersonaje(*temp);
                cout <<endl<< "Ahora el equipo pasa a ser:"<<endl;
                E->Display();
                delete temp;
            }
        }
    }
    else{
        if(static_cast<int>(Lista_Personajes.size())<=0){
            cout<<"No hay ningun personaje sin equipo disponible actualmente"<<endl;
        }
        else{
            seleccionar_Personaje(Lista_Personajes);
            cout<<"Personaje seleccionado para borrar con nombre: "<<Lista_Personajes[tecla-1]->getName()<<endl;
            auto it = Lista_Personajes.begin() + tecla - 1;
            delete *it;
            Lista_Personajes.erase(it);
            cout << "El personaje ha sido eliminado correctamente." << endl;
        }
    }
}
void Funciones::modificar_personaje(Personajes *Personaje, vector<Objetos *>& Lista_Objetos, vector<Hechizos *>& Lista_Hechizos){
    int tecla_pulsada=0;
    while(tecla_pulsada!=4){
        if(Mago *temp=dynamic_cast<Mago*>(Personaje)){
            cout<<"Que desea hacer con el Personaje? \n1. Modificar Objetos \n2.Modificar Atributos \n3. Modificar Hechizos \n4. Salir"<<endl;
        }else{
            cout<<"Que desea hacer con el Personaje? \n1. Modificar Objetos \n2.Modificar Atributos \n3. Salir"<<endl;
            tecla_pulsada=seleccion_invalida(1,4);
            if(tecla_pulsada==1) modificar_objetos(Personaje, Lista_Objetos);
            else if(tecla_pulsada==2) modificar_atributos(Personaje);
            else if(tecla_pulsada==3&&dynamic_cast<Mago*>(Personaje)) modificar_hechizos(temp, Lista_Hechizos);
        }
        cout<<"Desea seguir haciendo cambios al Personaje?"<<endl<<"1. SI"<<endl<<"2. NO"<<endl;
        tecla_pulsada=seleccion_invalida(1,2);
        (tecla_pulsada ==1) ? tecla_pulsada=0 : tecla_pulsada=4;
    }
}

//------------------------------Gestion de Hechizos-----------------------------------
void Funciones::modificar_hechizos(Mago *Mago, vector<Hechizos*>& Lista_Hechizos){
    tecla=0;
    cout<<"Actualmente este Mago: "<<endl;
    cout<<Mago;
    while(tecla!=4){
        cout<<"Que quieres hacer?"<<endl<<"1. Añadir Hechizo"<<endl<<"2. Eliminar Hechizo"<<endl<<"3. Modificar Hechizo"<<endl<<"4. Atras"<<endl;
        tecla=seleccion_invalida(1,4);
        if(tecla==1) añadir_hechizos(Mago, Lista_Hechizos);
        else if(tecla==2) eliminar_hechizo(Mago->getHechizos());
        else if(tecla==3) modificar_hechizos(Mago->getHechizos());
    }
}
void Funciones::modificar_hechizos(vector<Hechizos *>& Lista_Hechizos){
    int tecla_pulsada=0;
    if(Lista_Hechizos.size()>0){
        Hechizos *tmp=seleccionar(Lista_Hechizos);
        while(tecla_pulsada!=4){
            espera();
            cout<<"Has seleccionado el Hechizo: "<<*tmp<<endl;
            cout<<"Que quieres hacer con el? \n1. Cambiar Nombre \n2. Cambiar Coste \n3. Cambiar Tipo \n4. Salir"<<endl;
            tecla_pulsada=seleccion_invalida(1,4);
            if(tecla_pulsada==1){
                string name;
                cout<<"Introduce el nuevo nombre"<<endl;
                cin.clear();
                cin.ignore();
                getline(cin, name);
                tmp->setName(name);
            }else if(tecla_pulsada==2){
                int coste;
                cout<<"Introduce el nuevo coste (min 1, max 100)"<<endl;
                coste=seleccion_invalida(1,100);
                tmp->setCoste(coste);
            }else if(tecla_pulsada==3){
                cout<<"De que tipo quieres que sea el Hechizo?"<<endl<<"1. Tierra"<<endl<<"2. Agua"<<endl<<"3. Fuego"<<endl<<"4. Aire"<<endl;
                tecla=seleccion_invalida(1,4);
                switch(tecla){
                    case 1: tmp->setTipoHechizo("TIERRA"); break;
                    case 2: tmp->setTipoHechizo("AGUA"); break;
                    case 3: tmp->setTipoHechizo("FUEGO"); break;
                    case 4: tmp->setTipoHechizo("AIRE"); break;
                    default: break;
                }
            }
            cout<<"El Hechizo ha quedado asi: "<<*tmp<<endl;
        }
    }else{
        cout<<"Esta lista no tiene ningun Hechizo"<<endl;
    }
}
Hechizos* Funciones::crear_hechizo(){
    string name, tipo;
    int coste;
    cout<<"Como quieres llamar al hechizo? "<<endl;
    cin.clear();
    cin.ignore();
    getline(cin,name);
    cout<<"De que tipo quieres que sea el Hechizo?"<<endl<<"1. Tierra"<<endl<<"2. Agua"<<endl<<"3. Fuego"<<endl<<"4. Aire"<<endl;
    tecla=seleccion_invalida(1,4);
    switch(tecla){
        case 1: tipo="TIERRA"; break;
        case 2: tipo="AGUA"; break;
        case 3: tipo="FUEGO"; break;
        case 4: tipo="AIRE"; break;
        default: break;
    }
    cout<<"Cuanto quieres que cueste de Mana? (min 1, max 100)"<<endl;
    coste=seleccion_invalida(1,100);
    Hechizos *tmp=new Hechizos(coste,tipo,name);
    return tmp;
}
void Funciones::añadir_hechizos(Mago *Mago, vector<Hechizos *>& Lista_Hechizos){
    if(Lista_Hechizos.size()>0){
        Hechizos *hechizo=seleccionar(Lista_Hechizos);
        cout<<"Has seleccionado el hechizo: "<<endl;
        hechizo->Display();
        Mago->setHechizos(hechizo);
    }else{
        cout<<"Esta lista no tiene ningun hechizo"<<endl;
    }
    cout<<*Mago<<endl;
}
void Funciones::eliminar_hechizo(vector<Hechizos *>& Lista_Hechizos){
    if(Lista_Hechizos.size()>0){
        Recorrer(Lista_Hechizos);
        tecla=seleccion_invalida(1,Lista_Hechizos.size());
        cout<<"Has borrado el hechizo: "<<endl;
        Lista_Hechizos[tecla-1]->Display();
        delete Lista_Hechizos[tecla-1];
        Lista_Hechizos.erase(Lista_Hechizos.begin()+tecla-1);
    }else{
        cout<<"Esta lista no tiene ningun hechizo"<<endl;
    }
}


//-------------------------------------------Funciones-----------------------------------------
void Funciones::espera(){
    cout<<"Presione 1 para continuar"<<endl;
    tecla=seleccion_invalida(1,1);
    system("clear");
}
string Funciones::to_uppercase(string& linea){
    string result;
    for (char c : linea) {
        result += toupper(c);
    }
    return result;
}

int Funciones::seleccion_invalida(int LI,int LS){
    cin.clear();
    cin>>tecla;
    while(tecla<LI||tecla>LS)
    {
        cout << "Seleccion invalida" <<endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin>>tecla;
    }
    return tecla;
}
Funciones::~Funciones(){}
