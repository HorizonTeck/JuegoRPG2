#include "funciones.h"

Funciones::Funciones(){

}

void Funciones::guardar(vector<Objetos*>& objetos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < static_cast<int>(objetos.size()); ++i) {
            objetos[i]->serializar(archivo);
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
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
    ifstream archivo(nombreArchivo);
    string TipoObjeto, name, Tipo;
    int power;
    int lineas = contarLineas(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas; ++i) {
            archivo >> TipoObjeto >> name >> Tipo >> power;
            if(TipoObjeto=="Arma"){
                objetos.push_back( new Armas(name, Tipo, power));
            }
            else if(TipoObjeto=="Poción"){
                objetos.push_back( new Pociones(name, Tipo, power));
            }
            else{
                cout<<"El tipo de objeto introducido en la fila "<< i+1 << " no es valido"<<endl;
            }
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
}

void Funciones::cargar(){
    cout<<"La version del juego corresponde con la entrega 2 del trabajo"<<endl;
    cout<<"por lo que esta parte no esta aun disponible"<<endl;
    cout<<"puedes usar las pequeñas 'demos' que estan abajo del main, descomentando las que quieras"<<endl;
    cout<<"Se te enviara al menu anterior en 5 segundos"<<endl;
    this_thread::sleep_for(chrono::seconds(4));
}

void Funciones::guardar(){

}

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
    int tecla;
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
    if(Arma->getTipo()=="Cortante"){
        Arma->setPower(setAtributos(random,0,30));
    }else if(Arma->getTipo()=="Contundente"){
        Arma->setPower(setAtributos(random,0,50));
    }else if(Arma->getTipo()=="Distancia"){
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
    int tecla;
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
Objetos* Funciones::crear_objeto(){
    int tecla=0;
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
            objeto=new Armas(name,"Cortante");
        }
        else if(tecla==2){
            objeto=new Armas(name,"Contundente");
        }
        else if(tecla==3){
            objeto=new Armas(name,"Distancia");
        }
        else{
            objeto=new Armas(name,"Baculo");
        }
        setAtributos(objeto);
    } else{
        cout<<"De que tipo quieres que sea la pocion?: "<<endl<<"1. Salud"<<endl<<"2. Mana"<<endl;
       tecla=seleccion_invalida(1,2);
        if(tecla==1){
            objeto=new Pociones(name,"Salud");
        }
        else{
            objeto=new Pociones(name,"Mana");
        }
    }

    return objeto;
}

int Funciones::seleccion_invalida(int LI,int LS){
    int tmp=0;
    cin.clear();
    cin>>tmp;
    while(tmp<LI||tmp>LS)
    {
        cout << "Seleccion invalida" <<endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin>>tmp;
    }
    return tmp;
}
