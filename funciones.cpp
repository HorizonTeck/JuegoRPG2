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
void Funciones::cargar(vector<Personajes*>& personajes, const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    vector <Objetos*> tmp;
    vector <int> atributos;
    string  name, tipo, linea;
    if (archivo.is_open()) {
        archivo>>tipo>>name;
        while (getline(archivo, linea)) {
            archivo>>tipo>>name;
            if(tipo=="guerrero"||tipo=="Guerrero")
            {
                asignacionGuerrero(linea,atributos);
                personajes.push_back(new Guerrero(name,atributos,tmp));
            }else  if(tipo=="Arquero"||tipo=="arquero")
            {
                asignacionArquero(linea,atributos);
                personajes.push_back(new Arquero(name,atributos,tmp));
            }else if(tipo=="Mago"||tipo=="mago")
            {
                Prueba(linea);

                asignacionMago(linea,atributos);
                personajes.push_back(new Mago(name,atributos,tmp));
            }else
            {
                cout<< "Tipo erroneo (archivo corrupto)"<<endl;
            }
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
}


void Funciones::asignacionGuerrero(string linea,vector <int> atributos)
{
    size_t pos = linea.find(":"); // Busca el separador ":"
    if (pos != string::npos) { // Si se encuentra el separador
        string clave = linea.substr(0, pos); // Extrae la clave
        string valor = linea.substr(pos + 2); // Extrae el valor después del ":"
        if (clave == "Nivel") {
            atributos[0] = stoi(valor);
        } else if (clave == "Salud") {
            atributos[1] = stoi(valor);
        } else if (clave == "Poder") {
            atributos[2] = stoi(valor);
        }else if (clave == "Precision") {
            atributos[3] = stoi(valor);
        } else if (clave == "Proteccion") {
            atributos[4] = stoi(valor);
        } else if (clave == "Escudo") {
            atributos[5] = stoi(valor);
        }else if (clave == "Fuerza")
        {
            atributos[6] = stoi(valor);
        }else
            cout<< "Error en el archivo" <<endl;
    }
}

void Funciones::asignacionArquero(string linea,vector <int> atributos)
{
    size_t pos = linea.find(":"); // Busca el separador ":"
    if (pos != string::npos) { // Si se encuentra el separador
        string clave = linea.substr(0, pos); // Extrae la clave
        string valor = linea.substr(pos + 2); // Extrae el valor después del ":"
        if (clave == "Nivel") {
            atributos[0] = stoi(valor);
        } else if (clave == "Salud") {
            atributos[1] = stoi(valor);
        } else if (clave == "Poder") {
            atributos[2] = stoi(valor);
        }else if (clave == "Precision") {
            atributos[3] = stoi(valor);
        } else if (clave == "Proteccion") {
            atributos[4] = stoi(valor);
        } else if (clave == "Escudo") {
            atributos[5] = stoi(valor);
        }else if (clave == "Fuerza")
        {
            atributos[6] = stoi(valor);
        }else
            cout<< "Error en el archivo" <<endl;
    }
}

void Funciones::Prueba(string linea){
    std::vector<std::string> valores;

    // Variables para almacenar las posiciones
    size_t pos_actual = 0;
    size_t pos_dos_puntos;

    while ((pos_dos_puntos = linea.find(':', pos_actual)) != std::string::npos) {
        // Avanzar pos_dos_puntos al carácter después de ':'
        ++pos_dos_puntos;

        // Encontrar la siguiente palabra (desde pos_dos_puntos hasta el próximo espacio o el final de la línea)
        size_t pos_inicio_palabra = linea.find_first_not_of(' ', pos_dos_puntos);
        size_t pos_fin_palabra = linea.find(' ', pos_inicio_palabra);
        if (pos_fin_palabra == std::string::npos) {
            // Si no hay espacio, la palabra es la parte restante de la línea
            pos_fin_palabra = linea.length();
        }

        // Extraer la palabra y agregarla al vector
        std::string valor = linea.substr(pos_inicio_palabra, pos_fin_palabra - pos_inicio_palabra);
        valores.push_back(valor);

        // Actualizar pos_actual para continuar buscando desde el siguiente carácter después de la palabra encontrada
        pos_actual = pos_fin_palabra;
    }

    //valores (strings),
}
void Funciones::asignacionMago(string linea,vector <int>& atributos)
{
    size_t pos = linea.find(":"); // Busca el separador ":"
    if (pos != string::npos) { // Si se encuentra el separador
        string clave = linea.substr(0, pos); // Extrae la clave
        string valor = linea.substr(pos + 2); // Extrae el valor después del ":"
        if (clave == "Nivel") {
            atributos[0] = stoi(valor);
        } else if (clave == "Salud") {
            atributos[1] = stoi(valor);
        } else if (clave == "Poder") {
            atributos[2] = stoi(valor);
        }else if (clave == "Precision") {
            atributos[3] = stoi(valor);
        } else if (clave == "Proteccion") {
            atributos[4] = stoi(valor);
        } else if (clave == "Escudo") {
            atributos[5] = stoi(valor);
        }else if (clave == "Fuerza")
        {
            atributos[6] = stoi(valor);
        }else
            cout<< "Error en el archivo" <<endl;
    }
}

void Funciones::guardar(vector<Personajes*>& personajes, const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < static_cast<int>(personajes.size()); ++i) {
            personajes[i]->serializar(archivo);
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
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

void Funciones::crear_equipo(vector<Equipo*>& Lista_Equipos, vector<Personajes *> &Lista_Personajes){
    string *nombre=new string;
    cout<<"Como quieres nombrar el equipo: "<<endl;
    cin>>*nombre;
    Lista_Equipos.push_back(new Equipo(*nombre));
    delete nombre;
    cout<<"Quieres añadir algun personaje al Equipo?"<<endl<<"1. Si"<<endl<<"2. No"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        añadir_personaje(Lista_Equipos, Lista_Personajes);
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
    setAtributos(objeto);
    return objeto;
}

void Funciones::añadir_objeto(vector<Personajes*>& Lista_Personajes,vector<Equipo*>& Lista_Equipos, Objetos* objeto){
    cout<<"Quieres añadir el objeto a un personaje con o sin equipo?"<<endl<<"1. CON"<<endl<<"2. SIN"<<endl;
    tecla=seleccion_invalida(1,2);
    if(tecla==1){
        if(Lista_Equipos.size()>0){
            int tmp=tamaño_equipos(Lista_Equipos);
            if(tmp>0){
                seleccionar_Personaje(Lista_Equipos)->getInventario().push_back(objeto);
            }else{
                cout<<"Actualmente no hay Equipos con Personajes"<<endl;
            }
        }else{
            cout<<"Actualmente no hay ningun Equipo creado"<<endl;
        }
    }else{
        if(Lista_Personajes.size()>0){
            seleccionar_Personaje(Lista_Personajes)->setInventario(objeto);
        }else{
            cout<<"Actualmente no hay ningun Personaje sin equipo"<<endl;
        }
    }
}

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

int Funciones::tamaño_equipos(vector<Equipo*>& Lista_Equipos){
    int tmp=0;
    for(auto objeto : Lista_Equipos){
        if(objeto->getLista_Personajes().size()>0){
            tmp++;
        }
    }
    return tmp;
}

void Funciones::añadir_personaje(vector<Equipo*>& Lista_Equipos, vector<Personajes*>& Lista_Personajes){
    int tecla=0;
    while(tecla!=2){
        if(Lista_Personajes.size()<=0){
            cout<<"Actualmente no hay ningun Personaje sin Equipo o has asignado ya todos a un Equipo"<<endl;
            tecla=2;
        }else{
            cout<<"Actualmente hay: "<<Lista_Personajes.size()<<" Personajes sin Equipo"<<endl;
            for(int i=0; i< static_cast<int>(Lista_Personajes.size());i++){
                cout<<"Personaje numero: "<< i+1 <<" Nombre del Personaje: "<<Lista_Personajes[i]->getName()<<endl;
            }
            cout<<"Cual de ellos quieres añadir al equipo? "<<endl;
            tecla=seleccion_invalida(0,static_cast<int>(Lista_Personajes.size()));
            cout<<"Personaje seleccionado para añadir con nombre: "<<Lista_Personajes[tecla-1]->getName()<<endl;
            Lista_Equipos[Lista_Equipos.size()-1]->setLista_Personajes(Lista_Personajes[tecla-1]);
            auto it = Lista_Personajes.begin() + tecla - 1;
            //delete *it;
            Lista_Personajes.erase(it);
            cout << "El Personaje ha sido añadido correctamente. Desea añadir otro mas?" << endl;
            cout<<"1. SI"<<endl<<"2. NO"<<endl;
            tecla=seleccion_invalida(1,2);
        }
    }
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

