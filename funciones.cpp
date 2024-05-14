#include "funciones.h"
Funciones::Funciones(){
    tecla=0;
}
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
                    archivo<<" --->";
                    guardar(objeto->getInventario(),archivo);
                }
            }
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
}

//Gestion Atributos
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
        tmp=new Arquero;
        delete tmp;
    } else if(Mago *tmp=dynamic_cast<Mago*>(Personaje)){
        setAtributos(random,tmp);
        tmp=new Mago;
        delete tmp;
    }else if(Guerrero *tmp=dynamic_cast<Guerrero*>(Personaje)){
        setAtributos(random,tmp);
        tmp=new Guerrero;
        delete tmp;
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
        tmp=new Armas;
        delete tmp;
    } else if(Pociones *tmp=dynamic_cast<Pociones*>(Objeto)){
        setAtributos(random,tmp);
        tmp=new Pociones;
        delete tmp;
    }
}

//Gestion Equipos
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
        for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
            cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
        }
        cout<<"Cual de ellos quieres borrar? "<<endl;
        tecla=seleccion_invalida(1,static_cast<int>(Lista_Equipos.size()));
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
    cout<<"Actualmente hay: "<<Lista_Equipos.size()<<" Equipos"<<endl;
    for(int i=0; i< static_cast<int>(Lista_Equipos.size());i++){
        cout<<"Equipo numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Equipos[i]->getName()<<endl;
    }
    cout<<"A cual de ellos quieres meter el nuevo personaje? "<<endl;
    tecla=seleccion_invalida(1,static_cast<int>(Lista_Equipos.size()));
    cout<<"Equipo seleccionado con nombre: "<<Lista_Equipos[tecla-1]->getName()<<endl;
    return Lista_Equipos[tecla-1];
}
//Gestion Objetos
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
void Funciones::añadir_objeto(vector<Personajes*>& Lista_Personajes,vector<Equipo*>& Lista_Equipos, Objetos* objeto){
    cout<<"Quieres añadir el objeto a un personaje con o sin equipo?"<<endl<<"1. CON"<<endl<<"2. SIN"<<endl;
    tecla=seleccion_invalida(1,2);
    Personajes *P;
    if(tecla==1){
        if(Lista_Equipos.size()>0){
            int tmp=tamaño_equipos(Lista_Equipos);
            if(tmp>0){
                P=seleccionar_Personaje(Lista_Equipos);
                if(P->comprobarInventario(objeto)==true) P->setInventario(objeto);
                else cout<<"No se ha podido añadir el objeto"<<endl;
            }else{
                cout<<"Actualmente no hay Equipos con Personajes"<<endl;
            }
        }else{
            cout<<"Actualmente no hay ningun Equipo creado"<<endl;
        }
    }else{
        if(Lista_Personajes.size()>0){
            P=seleccionar_Personaje(Lista_Personajes);
            if(P->comprobarInventario(objeto)==true) P->setInventario(objeto);
            else cout<<"No se ha podido añadir el objeto"<<endl;
        }else{
            cout<<"Actualmente no hay ningun Personaje sin equipo"<<endl;
        }
    }
}

//Gestion Personajes
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
    for(int i=0; i< static_cast<int>(Lista_Personajes.size());i++){
        cout<<"Personaje numero: "<< i+1 <<" Nombre del equipo: "<<Lista_Personajes[i]->getName()<<endl;
    }
    cout<<"Cual de ellos quieres borrar? "<<endl;
    tecla=seleccion_invalida(1,static_cast<int>(Lista_Personajes.size()));
    cout<<"Personaje seleccionado con nombre: "<<Lista_Personajes[tecla-1]->getName()<<endl;
    return Lista_Personajes[tecla-1];
}
void Funciones::añadir_personaje(Equipo* Equipo, vector<Personajes*>& Lista_Personajes){
    int tecla=0;
    while(tecla!=2){
        if(Lista_Personajes.size()<=0){
            cout<<"Actualmente no hay ningun Personaje sin Equipo o has asignado ya todos a un Equipo"<<endl;
            tecla=2;
        }else{
            Equipo->setLista_Personajes(seleccionar_Personaje(Lista_Personajes));
            auto it = Lista_Personajes.begin() + tecla - 1;
            Lista_Personajes.erase(it);
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
void Funciones::eliminar_personaje(vector<Equipo *> &Lista_Equipos, vector<Personajes *> &Lista_Personajes)
{
    {
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
}
void Funciones::espera(){
    cout<<"Presione 1 para continuar"<<endl;
    tecla=seleccion_invalida(1,1);
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
