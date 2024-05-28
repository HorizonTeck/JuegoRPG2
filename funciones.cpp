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
void Funciones::cargar(vector<Objetos*>& Lista_Objetos, string nombreArchivo){
    vector<string> parametros = {"Arma","Pocion","Tipo","Poder"};
    vector<bool> comprobar;
    comprobar.resize(parametros.size());
    string nombre, tipo,tmp;
    int poder=0,lineas=0;
    ifstream archivo(nombreArchivo);
    string linea, lineaencontrada="";
    size_t posicion=0;
    size_t pos =string::npos;
    while(getline(archivo,linea)){
        lineas++;
        QuitarEspacios(linea);
        pos =string::npos;
        for(int i=0;i<static_cast<int>(parametros.size());i++){
            posicion=linea.find(parametros[i]);
            if (posicion != string::npos && (pos == string::npos || posicion < pos)) {
                pos = posicion;
                lineaencontrada = parametros[i];
                switch(i){
                case 1:
                case 2:
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    comprobar[i]=true;
                    nombre=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(nombre);
                    break;
                case 3:
                    comprobar[i]=true;
                    tipo=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(tipo);
                    to_uppercase(tipo);
                    break;
                case 4:
                    tmp=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(tmp);
                    if(esNumero(tmp)==1){
                        poder=stoi(tmp);
                        comprobar[i]=true;
                    }
                    break;
                }
                if(comprobar[0]==1&&comprobar[2]==1&&comprobar[3]==1) Lista_Objetos.push_back(new Armas(nombre,tipo,poder));
                else if(comprobar[1]==1&&comprobar[2]==1&&comprobar[3]==1) Lista_Objetos.push_back(new Pociones(nombre,tipo,poder));
            }
        }
    }
}
void Funciones::cargar(vector<Equipo*>& Lista_Equipos, string nombreArchivo){
    vector<string> parametros = {"EQUIPO","Mago","Arquero","Guerrero","Hechizo","Arma","Pocion","Tipo","Nivel","Salud","Poder","Precision","Proteccion","Mana","Agilidad","Carcaj","Fuerza","Escudo","Coste","Dinero"};
    vector<bool> comprobar;
    comprobar.resize(parametros.size());
    vector<int> valores;
    valores.resize(parametros.size());
    string nombre, tipo,tmp;
    ifstream archivo(nombreArchivo);
    string linea, lineaencontrada="";
    size_t posicion=0;
    size_t pos =string::npos;
    vector<Equipo*> lista;
    Objetos *objetotmp;
    Personajes *personajetmp;
    Hechizos* hechizotmp;
    Equipo* equipotmp;
    int lineas=0;
    bool personaje=0;
    while(getline(archivo,linea)){
        lineas++;
        QuitarEspacios(linea);
        pos =string::npos;
        for(int i=0;i<static_cast<int>(parametros.size());i++){
            posicion=linea.find(parametros[i]);
            if (posicion != string::npos && (pos == string::npos || posicion < pos)) {
                pos = posicion;
                lineaencontrada = parametros[i];
                switch(i){
                case 0:
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                    personaje=false;
                    comprobar[i]=true;
                    nombre=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(nombre);
                    break;
                case 1:
                case 2:
                case 3:
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                    personaje=1;
                    comprobar[i]=1;
                    nombre=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(nombre);
                    break;
                case 4:
                case 5:
                case 6:
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                    comprobar[i]=1;
                    nombre=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(nombre);
                    break;
                case 7:
                    comprobar[i]=1;
                    tipo=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(tipo);
                    to_uppercase(tipo);
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                    tmp=linea.substr(posicion+lineaencontrada.size()+1);
                    QuitarEspacios(tmp);
                    if(esNumero(tmp)==1){
                        valores[i]=stoi(tmp);
                        comprobar[i]=1;
                    }
                }
                if(comprobar[0]==1&&personaje==0&&comprobar[19]==1){
                    lista.push_back(new Equipo(nombre,valores[19]));
                    equipotmp=lista[lista.size()-1];
                }
                else if(comprobar[1]==1&&comprobar[8]==1&&comprobar[9]==1&&comprobar[10]==1&&comprobar[11]==1&&comprobar[12]==1&&comprobar[13]==1&&personaje==1){
                    equipotmp->setLista_Personajes(new Mago(nombre,valores[8],valores[9],valores[10],valores[11],valores[12],valores[13]));
                    if(personajetmp!=nullptr)personajetmp=equipotmp->getLista_Personajes(equipotmp->gettamaño()-1);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
                else if(comprobar[2]==1&&comprobar[8]==1&&comprobar[9]==1&&comprobar[10]==1&&comprobar[11]==1&&comprobar[12]==1&&comprobar[14]==1&&comprobar[15]==1&&personaje==1){
                    equipotmp->setLista_Personajes(new Arquero(nombre,valores[8],valores[9],valores[10],valores[11],valores[12],valores[14],valores[15]));
                    if(personajetmp!=nullptr)personajetmp=equipotmp->getLista_Personajes(equipotmp->gettamaño()-1);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
                else if(comprobar[3]==1&&comprobar[8]==1&&comprobar[9]==1&&comprobar[10]==1&&comprobar[11]==1&&comprobar[12]==1&&comprobar[16]==1&&comprobar[17]==1&&personaje==1){
                    equipotmp->setLista_Personajes(new Guerrero(nombre,valores[8],valores[9],valores[10],valores[11],valores[12],valores[16],valores[17]));
                    if(personajetmp!=nullptr)personajetmp=equipotmp->getLista_Personajes(equipotmp->gettamaño()-1);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
                else if(comprobar[4]==1&&comprobar[7]==1&&comprobar[18]==1&&personaje==1){
                    hechizotmp=new Hechizos(valores[18],tipo,nombre);
                    if(Mago* tmp2=dynamic_cast<Mago*>(personajetmp)) tmp2->setHechizos(hechizotmp);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
                else if(comprobar[5]==1&&comprobar[7]==1&&comprobar[10]==1&&personaje==1){
                    objetotmp=new Armas(nombre,tipo,valores[10]);
                    if(personajetmp!=nullptr) if(personajetmp->comprobarInventario(objetotmp)==1)personajetmp->setInventario(objetotmp);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
                else if(comprobar[6]==1&&comprobar[7]==1&&comprobar[10]==1&&personaje==1){
                    objetotmp=new Pociones(nombre,tipo,valores[10]);
                    if(personajetmp!=nullptr) if(personajetmp->comprobarInventario(objetotmp)==1)personajetmp->setInventario(objetotmp);
                    for(int i=0;i<static_cast<int>(comprobar.size());i++) comprobar[i]=false;
                    for(int i=0;i<static_cast<int>(valores.size());i++) valores[i]=0;
                }
            }
        }
    }
    for(auto objeto : lista) Lista_Equipos.push_back(objeto);
}
void Funciones::cargar(vector<Personajes*>& Lista_Personajes, string nombreArchivo){

}
void Funciones::cargar(vector<Hechizos*>& Lista_Hechizos,string nombreArchivo){

}
bool Funciones::esNumero(string &linea){
    for(char c : linea){
        if(!isdigit(c)) return 0;
    }
    return 1;
}
void Funciones::guardar(vector<Personajes*> personajes, const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (auto objeto : personajes) {
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
            archivo<<"      ";
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
            archivo<< "EQUIPO: "<<equipos[i]->getName()<<"\nDinero: "<<equipos[i]->getDinero()<<endl;
            for (auto objeto : equipos[i]->getLista_Personajes()) {
                archivo<<"  ";
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

void Funciones::QuitarEspacios(string & palabra)
{
    int start = palabra.find_first_not_of(" \t\n\r\f\v");
    palabra = palabra.substr(start); //coge desde la posicion donde no haya espacios
    int end = palabra.find_last_not_of(" \t\n\r\f\v");
    palabra = palabra.substr(0, end + 1); //coge desde el principio hasta no haya espacios
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
        cout << verde <<"Dime la salud de tu personaje (0-100)"<<RESET<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout << rojo<<"Dime el poder de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (20-40)"<< endl;
        A->setAtributos(seleccion_invalida(20,40),4);
        cout << "Dime la agilidad de tu personaje (1-10)"<< endl;
        A->setAtributos(seleccion_invalida(1,10),5);
        cout << "Dime las flechas que tiene tu personaje en el carcaj (1-15)"<< endl<<RESET;
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
        cout <<verde<< "Dime la salud de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout << azul<<"Dime el poder de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (15-30)"<< endl;
        A->setAtributos(seleccion_invalida(15,30),4);
        cout << "Dime el escudo de tu personaje (0-30)"<< endl;
        A->setAtributos(seleccion_invalida(0,30),5);
        cout << "Dime la fuerza de tu personaje (1-15)"<< endl<<RESET;
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
        cout << verde<<"Dime la salud de tu personaje (0-100)"<< endl;
        A->setAtributos(seleccion_invalida(0,100),1);
        cout <<rosa<< "Dime el poder de tu personaje (50-70)"<< endl;
        A->setAtributos(seleccion_invalida(50,70),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        A->setAtributos(seleccion_invalida(1,12),3);
        cout << "Dime protecion de tu personaje (50-60)"<< endl;
        A->setAtributos(seleccion_invalida(50,60),4);
        cout << "Dime el mana de tu personaje (0-100)"<< endl<<RESET;
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
    cout <<"Como quieres asignarle el poder?" <<endl<<"1. Random"<<endl<<"2. Manualmente"<<endl;
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
    int tecla_pulsada=0;
    while(tecla_pulsada!=2){
        if(Lista_Personajes.size()<=0){
            cout<<"Actualmente no hay ningun Personaje sin Equipo o has asignado ya todos a un Equipo"<<endl;
            tecla_pulsada=2;
        }else{
            cout<<"Elije un personaje para añadirlo"<<endl;
            Equipo->setLista_Personajes(seleccionar_Personaje(Lista_Personajes));
            Lista_Personajes.erase(Lista_Personajes.begin() + tecla - 1);
            // Lista_Personajes.push_back(Equipo->getLista_Personajes()[tmp-1]);
            // Equipo->getLista_Personajes().erase(Equipo->getLista_Personajes().begin()+tmp-1);

            cout << "El Personaje ha sido añadido correctamente. Desea añadir otro mas?" << endl;
            cout<<"1. SI"<<endl<<"2. NO"<<endl;
            tecla_pulsada=seleccion_invalida(1,2);
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

//-------------------------------------------Combate------------------------------------------
void Funciones::LanzarHechizo(vector<Equipo *>& Lista_Equipos, Mago* Atacante, bool& turno, ofstream& archivo){
    bool turno_opuesto;
    (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
    if(Atacante->getHechizos().size()>0){
        cout<<"Que hechizo quieres usar?"<<endl;
        Hechizos *hechizo=seleccionar(Atacante->getHechizos());
        if(hechizo->getTipoHechizo()=="AGUA"){
            cout<<"Has elegido una pocion de tipo Agua, se curara a todos los aliados incluido a ti"<<endl;
            for(auto objeto : Lista_Equipos[turno]->getLista_Personajes()){
                objeto->setAtributos(objeto->getAtributos(1)+hechizo->getCoste(),1);
            }
        }else if(hechizo->getTipoHechizo()=="FUEGO"){
            cout<<"Has elegido una pocion de tipo Fuego, restas salud a todo el equipo enemigo"<<endl;
            for(auto objeto : Lista_Equipos[turno_opuesto]->getLista_Personajes()){
                objeto->setAtributos(objeto->getAtributos(1)-hechizo->getCoste(),1);
            }
        }else if(hechizo->getTipoHechizo()=="TIERRA"){
            cout<<"Has elegido una pocion de tipo Tierra, bajas la proteccion a todo el equipo enemigo"<<endl;
            for(auto objeto : Lista_Equipos[turno_opuesto]->getLista_Personajes()){
                objeto->setAtributos(objeto->getAtributos(4)-hechizo->getCoste(),4);
            }
        }else if(hechizo->getTipoHechizo()=="AIRE"){
            cout<<"Has elegido una pocion de tipo Aire, bajas el poder a todo el equipo enemigo"<<endl;
            for(auto objeto : Lista_Equipos[turno_opuesto]->getLista_Personajes()){
                objeto->setAtributos(objeto->getAtributos(2)-hechizo->getCoste(),2);
            }
        }
        turno=turno_opuesto;
        archivo<<Atacante->getName()<<" Ha lanzado un hechizo de tipo "<<hechizo->getTipoHechizo()<<endl;
        archivo<<"Cambio de turno"<<endl;
    }else{
        cout<<"Este mago no tiene hechizos, tranquilo, no consumes turno"<<endl;
    }
}
void Funciones::menucombate(vector<Equipo*>& Partida, vector<Personajes*>& Muertos, vector<string*>& Nombres, bool turno){
    ofstream archivo ("Log.txt");
    if(archivo.is_open()){
        cout<<"Log preparado"<<endl;
        archivo<< "Inicio de Combate\n";
    }else
    {
        cout<<"Log no preparado"<<endl;
    }
    tecla=0;
    vector <Personajes*> Combatientes;
    int dados=0,seleccion=0;
    bool turno_opuesto;
    (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
    cout<<"Turno de "<< Nombres[turno]<< "\n ¿Cual es tu combatiente?"<<endl;
    Combatientes[turno]=seleccionar_Personaje(Partida[turno]->getLista_Personajes());
    cout<<"Turno de "<< Nombres[turno_opuesto]<< "\n ¿Cual es tu combatiente?"<<endl;
    Combatientes[turno_opuesto]=seleccionar_Personaje(Partida[turno]->getLista_Personajes());
    archivo<<"Se han inicializado los Combatientes: 1. "<< Combatientes[turno]->getName() <<  " 2. "<<Combatientes[turno_opuesto]->getName()<<endl;
    while(tecla!=5&&Partida[0]->getLista_Personajes().size()>0&&Partida[1]->getLista_Personajes().size()>0){
        cout<<"Personaje en uso:  "<<Combatientes[turno]->getName()<<endl;
        if(dynamic_cast<Mago*>(Combatientes[turno]))
        {
            cout<<"¿Que quieres hacer?\n1. Atacar \n2. Usar Pocion \n3. Cambiar Personaje \n4. Lanzar Hechizo\n5. Ver inventario"<<endl;//ver el log de combate y salir del combate, vender objetos
        }
        else
        {
            cout<<"¿Que quieres hacer?\n1. Atacar \n2. Usar Pocion\n3. Cambiar Personaje \n4. Ver inventario"<<endl;
        }
        tecla=seleccion_invalida(1,5);
        switch(tecla){
        case 1:{
            archivo<< "Ataca: " <<Combatientes[turno]->getName() << " Defiende: "<<Combatientes[turno_opuesto]->getName()<<endl;
            dados=Combatientes[turno]->tirar_dados();
            cout<<Combatientes[turno]->getName()<<" Ha sacado "<< dados<<" tirando los dados"<<endl;
            if(dados<Combatientes[turno]->getAtributos(3)){
                cout<<"Y por ello el ataque ha fallado, ya que es menor que la precision de "<<Combatientes[turno]->getName()<<endl;
                archivo<<Combatientes[turno]->getName() <<" Fallo"<<endl;
            }else if(Combatientes[turno]->Ataque()>=Combatientes[turno_opuesto]->Defensa()){
                Combatientes[turno]->DisplayAtaque();
                Combatientes[turno_opuesto]->setAtributos(Combatientes[turno_opuesto]->getAtributos(1)-(Combatientes[turno]->Ataque()-Combatientes[turno_opuesto]->Defensa()),1);
                if(Combatientes[turno_opuesto]->getAtributos(1)<=0)
                {
                    Combatientes[turno]++; //Subida de nivel
                    archivo<< Combatientes[turno]->getName() <<" Ha subido de nivel"<<endl;
                    comprobarSalud(Partida[turno_opuesto],Combatientes[turno_opuesto],Muertos);
                }

                archivo<< "Impacta el ataque a " <<  Combatientes[turno_opuesto]->getName() <<", quitandole" << Combatientes[turno]->Ataque() <<" de salud"<<endl;
            }else{
                cout<<" El ataque ha fallado ya que no tiene suficiente poder"<<endl;
                archivo<<Combatientes[turno]->getName() <<" Fallo"<<endl;
            }
            turno=turno_opuesto;
            (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
            archivo<< "Cambio de turno"<<endl;
            break;
        }
        case 2:{
            if(Combatientes[turno]->NumPociones()>0){ //Pociones esta mal
                LanzarPocion(Combatientes[turno],Partida,turno,archivo);
                (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
            }else if(Combatientes[turno]->getAtributos(1)<=50){
                cout<<"Este personaje no tiene pociones, sin embargo al tener menos de 50 de vida puede recibir una pocion de otro personaje"<<endl;
                cout<<"Deseas coger la pocion de otro personaje? "<<endl<<"1. SI (perderas turno)"<<endl<<"2. NO (saldras sin perder turno)"<<endl;
                tecla=seleccion_invalida(1,2);
                while(tecla!=2){
                    cout<<"Selecciona un Personaje de tu Equipo"<<endl;
                    Personajes *donante=seleccionar(Partida[turno]->getLista_Personajes());
                    vector<Objetos*> inventariotemporal;
                    if(donante->NumPociones()>0){
                        int pociones=0;
                        for(auto objeto : donante->getInventario()){
                            if(dynamic_cast<Pociones*>(objeto)){
                                pociones++;
                                cout<<pociones<<". "<<objeto<<endl;
                                inventariotemporal.push_back(objeto);
                            }
                        }
                        tecla=seleccion_invalida(1,pociones);
                        cout<<"Has seleccionado la pocion: "<<endl<<*inventariotemporal[tecla]<<endl;
                        if(Combatientes[turno]->comprobarInventario(inventariotemporal[tecla])==1){
                            Combatientes[turno]->setInventario(inventariotemporal[tecla]);
                            archivo<<"El personaje: "<<Combatientes[turno]->getName()<<" del equipo"<<Partida[turno]->getName()<<" ha recibido la pocion "<<inventariotemporal[tecla]->getName();
                            archivo<<" del personaje "<<donante->getName()<<endl;
                            turno=turno_opuesto;
                            (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
                            tecla=2;
                            archivo<<"Cambio de turno"<<endl;

                        }
                        else{
                            cout<<"La pocion que has elegido puede que no sea compatible con este personaje o que no tenga espacio suficiente en el inventario "<<endl;
                            cout<<"Desea volver a intentar con otra pocion o otro personaje?"<<endl<<"1. SI"<<endl<<"2. NO (saldras y no perderas turno)"<<endl;
                            tecla=seleccion_invalida(1,2);
                        }

                    }else{
                        cout<<"Este Personaje no tiene Pociones, desea volver a intentar con otro?"<<endl<<"1. SI"<<endl<<"2. NO (saldras y no perderas turno)"<<endl;
                        tecla=seleccion_invalida(1,2);
                    }
                }
            }else cout<<"Este personaje no tiene pociones y tampoco tiene menos de 50 de vida"<<endl;
            break;
        }
        case 3:
            archivo<< "Cambio de personaje de: "<< Combatientes[turno]->getName();
            Combatientes[turno]=seleccionar(Partida[turno]->getLista_Personajes());
            archivo<< " a: "<< Combatientes[turno]->getName()<<endl;
            turno=turno_opuesto;
            (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
            archivo<< "Cambio de turno"<<endl;
            break;
        case 4:
            if(dynamic_cast<Mago*>(Combatientes[turno]))
            {
                LanzarHechizo(Partida,dynamic_cast<Mago*>(Combatientes[turno]),turno,archivo);
                (turno==1) ? turno_opuesto=0 : turno_opuesto=1;
            }else
            {
                Recorrer(Combatientes[turno]->getInventario());
                archivo<< "Impresion del inventario de: "<< Combatientes[turno]->getName()<<endl;
            }
            break;
        case 5:
            tecla=4;

        }
    }//Guardar equipo ganador

        archivo.close();
    }
void Funciones::LanzarPocion(Personajes *Combatiente, vector<Equipo *> &Partida, bool& turno, ofstream& archivo){
    int pociones=0, seleccionado=0;
    vector <Objetos*> inventariotemporal;
    tecla=0;
    while(tecla!=2){
        cout<<"Elige una pocion: "<<endl;
        for(auto objeto : Combatiente->getInventario()){
            if(dynamic_cast<Pociones*>(objeto)){
                pociones++;
                cout<<pociones<<". "<<objeto<<endl;
                inventariotemporal.push_back(objeto);
            }
        }
        seleccionado=seleccion_invalida(1,pociones);
        cout<<"Has elegido la pocion: "<<endl;
        cout<<*inventariotemporal[seleccionado]<<endl;
        cout<<"A quien le quieres lanzar la pocion? (Puedes elegir el personaje actual tambien)"<<endl;
        Personajes *recibe=seleccionar(Partida[turno]->getLista_Personajes());
        if(recibe->LanzarPocion(dynamic_cast<Pociones*>(inventariotemporal[seleccionado]))==1){
            archivo<<"El personaje "<<Combatiente->getName()<<" ha lanzado una pocion de "<<inventariotemporal[seleccionado]->getTipo()<<" al personaje "<<recibe->getName()<<endl;
            (turno==1) ? turno=0 : turno=1;
            tecla=2;
            archivo<<"Cambio de turno"<<endl;
        }else{
            cout<<"El personaje no ha podido lanzar la pocion, es posible que la pocion no sea compatible con este personaje"<<endl;
            cout<<"Desea seguir intentando con otro personaje/pocion o quiere salir"<<endl<<"1. SEGUIR"<<endl<<"2. SALIR"<<endl;
            tecla=seleccion_invalida(1,2);
        }
    }
}
bool Funciones::InicioCombate(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Cementerio){
    vector<Equipo*> Partida;
    vector <string*> Nombres;
    bool turno=0;
    DisplayLucha();
    cout<< "Nombre de los jugadores \nJugador 1:"<<endl;
    cin.clear();
    cin.ignore();
    getline(cin,*Nombres[0]);
    cout<<"Jugador 2:"<<endl;
    cin.clear();
    cin.ignore();
    getline(cin,*Nombres[1]);
    cout<<Nombres[0]<<", Elige el equipo con el que quieras jugar:" << endl;
    Partida.push_back(seleccionar_Equipo(Lista_Equipos));
    cout<<"\n"<<Nombres[1]<<", Elige el equipo con el que quieras jugar:\n" << endl;
    Partida.push_back(seleccionar_Equipo(Lista_Equipos));
    cout<< "Equipo rival: "<<Partida[0]->getName()<< endl;
    if(Partida[0]==Partida[1])
    {
        system("clear");
        cout<< "\nMismo equipo que tu rival, seleciona otro diferente"<<endl;
    }
    while(Partida[0]==Partida[1])
    {
        cout<<Nombres[1]<<", Elige el equipo con el que quieras jugar:\n" << endl;
        Partida[1] = seleccionar_Equipo(Lista_Equipos);
        cout<< "Equipo rival: "<<Partida[0]->getName()<< endl;
        if(Partida[1]==Partida[0])
        {
            cout<< "\nMismo equipo que tu rival, seleciona otro diferente"<<endl;
            cout<<"¿Quiere seguir probando? 1.SI 2.NO"<<endl;
            tecla=seleccion_invalida(1,2);
            if(tecla==2)
            {
                break; //Para salir del while
            }
        }
        system("clear");
    }
    system("clear");
    if(Partida[0]==Partida[1])
    {
        return 0;//Para salir del switch
    }
    menucombate(Partida,Cementerio,Nombres,turno);
    return 0;
}

    //-------------------------------------------Funciones----------------------------------------
void Funciones::comprobarSalud(Equipo *Defensor, Personajes* personaje, vector<Personajes *> &Muertos)
{
if(personaje->getAtributos(1)<=0)
{
    cout<<personaje->getName() << " Ha muerto. RIP"<<endl;
    Muertos.push_back(personaje);
    for(int i=0; i<static_cast<int>(Defensor->getLista_Personajes().size());i++)
    {
        if(Defensor->getLista_Personajes(i)==personaje)
        {
            Defensor->getLista_Personajes().erase(Defensor->getLista_Personajes().begin()+i);
        }
    }

}else
{
    cout<< "Estaba de parranda"<<endl;
}
}
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
