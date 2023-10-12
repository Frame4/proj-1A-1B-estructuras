// proyecto 1B.cpp
// 
// Para este proyecto se tiene la intención de construir
// un comparador de rendimiento entre las diferentes estructuras
// de datos vistas en clase; lista enlazada, árboles binarios de búsqueda, árboles AVL y árboles BTREE.
// 
// Realizado por:
// Marco Angulo Elizondo: 2023367218 
// Alana Calvo Bolaños: 2022040915
// Esteban Cortés Mora: 2023194497


#include <iostream>;
#include <chrono>
#include "AVL.h";
#include "BTREE.h";
#include "ListaSimple.h";
#include "cargaPadron.h";




using namespace std;


typedef struct T_Votante {     char cedula[10];    char codelec[7];    char sexo;    char fecha[9];    char numjun[6];    char nombre[31];    char papellido[27];    char sapellido[27];    T_Votante * PtrSiguiente;}*PtrT_Votante;



//tiempos de carga
int tiempoDeCargaPadron;

int tiempoDeListadoLE;
int tiempoDeListadoABB;
int tiempoDeListadoAVL;
int tiempoDeListadoBTREE;




int main()
{
    int option;
    int option1;
    char cedula[10];

    
    
    
    
    cout << "Proyecto 1B" << endl;
    cout << "Comparador de rendimiento de estructuras de datos\nInterfaz gráfica para la ultima entrega." << endl;
    
    cout << "Seleccione una opción: " << endl;
    cout << " 1) cargar datos" << endl;
    cout << " 2) salir" << endl;
    cin >> option1;

    switch (option1)
    {
    case 1: 
        PtrT_Votante listMaestra;
        //inicializarvotantes(listMaestra);
        //cargarDatos(listMaestra);
        

        
        break;
    case 2:
        break;
    default:
        break;
    }

    while (true) {
        cout << "Seleccione una opción:" << endl;
        cout << " 1) listar" << endl;
        cout << " 2) búsqueda" << endl;
        cout << " 3) liberar memoria" << endl;
        cout << " 4) reporte de tiempos" << endl;
        cout << " 5) salir" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Listado" << endl;
            //listar();
            break;
        case 2:
            cout << "Búsqueda" << endl;
            cout << "Ingrese el número de cédula" << endl;
            cin >> cedula;
            //busqueda(cedula);
            break;
        case 3:
            cout << "Liberando memoria..." << endl;
            //liberarMem();
            break;
        case 4:
            cout << "Reporte" << endl;
            //reporte();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            //liberarMem();
            return 0;
            break;
        default:
            cout << "opción no disponible." << endl;
            break;
        }
    }


}

void cargarDatos() {
    //Aquí se deben cargar los datos en la lista maestra, luego cargar la lista en todas las estructuras de datos.

    //falta ABB

    //AVL

    //BTREE
}

void listar() {
    cout << "" << endl;
    //duda*** de deben listar todos los millones de votantes con cada estructura??
}

void busqueda(char cedula[10]) {//se recibe cedula y se busca con cada estructura
    cout << "" << endl;
}

void liberarMem() {// usar la funcion de liberar memoria con cada una de las estructuras
    cout << "" << endl;
}

void reporte() { // generar el reporte a partir de las variables que deben almacenar los tiempos de cada ejecución.
    cout << "" << endl;
}