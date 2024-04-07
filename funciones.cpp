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

