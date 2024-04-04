#include <equipo.h>
#include <guerrero.h>
#include <armas.h>
#include <pociones.h>

using namespace std;

void guardarObjetos(vector<Objetos*> objetos, int numObjetos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < numObjetos; ++i) {
            objetos[i]->serializar(archivo);
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }
}

void cargarObjetos(vector<Objetos*> objetos, int numObjetos, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string TipoObjeto, name, Tipo;
    int power;
    if (archivo.is_open()) {
        for (int i = 0; i < numObjetos; ++i) {
            archivo >> TipoObjeto >> name >> Tipo >> power;
            if(TipoObjeto=="Arma"){
                objetos[i] = new Armas(TipoObjeto, name, Tipo, power);
            }
            else if(TipoObjeto=="Poción"){
                objetos[i] = new Pociones(TipoObjeto, name, Tipo, power);
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

int contarLineas(const string& nombreArchivo) {
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

int main(){
    int Ndeobjetos = 1;                                          //Ejemplo de guardar objetos en txt
    vector<Objetos*> Lista_Objetos;
    Lista_Objetos.push_back(new Armas("Arma", "Juan", "Cortante", 46));
    Lista_Objetos.push_back(new Armas("Arma", "Pepe", "Contundente", 50));
    guardarObjetos(Lista_Objetos, Ndeobjetos, "ObjetosPrueba.txt");


    /* int Ndeobjetos = contarLineas("objetos.txt");      //Ejemplo de como se cargarian objetos desde txt en el programa
    if(Ndeobjetos<0) cout<<"No hay suficientes objetos"<<endl;
    else{
        Objetos** Lista_Objetos= new Objetos*[Ndeobjetos];
        cargarObjetos(Lista_Objetos,Ndeobjetos,"objetos.txt");
        for (int i = 0; i < Ndeobjetos; ++i){
            Lista_Objetos[i]->display();
            Lista_Objetos[i]=nullptr;
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

}
