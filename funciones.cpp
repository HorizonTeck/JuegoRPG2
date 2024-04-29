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
                objetos.push_back( new Armas(TipoObjeto, name, Tipo, power));
            }
            else if(TipoObjeto=="Poción"){
                objetos.push_back( new Pociones(TipoObjeto, name, Tipo, power));
            }
            else{
                cout<<"El tipo de arma introducido en la fila "<< i+1 << " no es valido"<<endl;
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
    int* comprobacion=new int();
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
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,100),1);
        cout << "Dime el poder de tu personaje (0-30)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,12),3);
        cout << "Dime protecion de tu personaje (20-40)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,20,40),4);
        cout << "Dime la agilidad de tu personaje (1-10)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,10),5);
        cout << "Dime las flechas que tiene tu personaje en el carcaj (1-15)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,15),6);
    }
    delete comprobacion;
}
void Funciones::setAtributos(bool random, Guerrero* A)
{
    int* comprobacion=new int();
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
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,100),1);
        cout << "Dime el poder de tu personaje (0-30)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,30),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,12),3);
        cout << "Dime protecion de tu personaje (15-30)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,15,30),4);
        cout << "Dime el escudo de tu personaje (0-30)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,30),5);
        cout << "Dime la fuerza de tu personaje (1-15)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,15),6);
    }
    delete comprobacion;
}
void Funciones::setAtributos(bool random, Mago* A)
{
    int* comprobacion=new int();
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
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,100),1);
        cout << "Dime el poder de tu personaje (50-70)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,50,70),2);
        cout << "Dime precision de tu personaje (1-12)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,1,12),3);
        cout << "Dime protecion de tu personaje (50-60)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,50,60),4);
        cout << "Dime el mana de tu personaje (0-100)"<< endl;
        cin>> *comprobacion;
        A->setAtributos(comprobar(*comprobacion,0,100),5);
    }
    delete comprobacion;
}
void Funciones::setAtributos(bool random, Personajes* Personaje){
    if(Personaje->identificador()=="Arquero"){
        Arquero *tmp=dynamic_cast<Arquero*>(Personaje);
        setAtributos(random,tmp);
        tmp=new Arquero;
        delete tmp;
    } else if(Personaje->identificador()=="Mago"){
        Mago *tmp=dynamic_cast<Mago*>(Personaje);
        setAtributos(random,tmp);
        tmp=new Mago;
        delete tmp;
    }else if(Personaje->identificador()=="Guerrero"){
        Guerrero *tmp=dynamic_cast<Guerrero*>(Personaje);
        setAtributos(random,tmp);
        tmp=new Guerrero;
        delete tmp;
    }
}
void Funciones::setAtributos(bool random, Armas *Arma){

}
void Funciones::setAtributos(bool random, Pociones *Pocion){

}
void Funciones::setAtributos(bool random, Objetos* Objeto){

}
void Funciones::crear_objeto(){
    int tecla=0;
    string name;
    cout<<"Como quiere llamar al objeto?:"<<endl;
    cin>>name;
    cout<<"De que tipo quieres que sea el objeto?"<<endl<<"1. Arma"<<endl<<"2. Poción"<<endl;
    cin>>tecla;
    while(tecla!=1&&tecla!=2){
        tecla=seleccion_invalida();
    }
    if(tecla==1){
        cout<<"De que tipo quieres que sea el Arma?:"<<endl<<"1. Cortante"<<endl<<"2. Contundente"<<endl<<"3. Distancia"<<endl<<"4. Báculos"<<endl;
        cin>>tecla;
        while(tecla<1||tecla>4){
            tecla=seleccion_invalida();
        }
        if(tecla==1){
            Objetos *objeto=new Armas();
        }
    }
}
int Funciones::comprobar(int comprobacion, int LI, int LS)
{
    if(comprobacion>=LI&&comprobacion<=LS)
    {
        return comprobacion;
     } else
    {
        cout<< "VALOR INCORRECTO, SE ASIGNA EL LIMITE MAS CERCANO"<<endl;
        if(comprobacion<LI)
        {
            return LI;
        }else
        {
            return LS;
        }
    }
}

int Funciones::seleccion_invalida(){
    int tmp=0;
    cout << "Seleccion invalida" <<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>tmp;
    return tmp;
}
