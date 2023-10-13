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
//#include "AVL.h";
//#include "BTREE.h";
//#include "ListaSimple.h";
//#include "cargaPadron.h";

using namespace std;

//tiempos de carga
int tiempoDeCargaPadron;

int tiempoDeListadoLE;
int tiempoDeListadoABB;
int tiempoDeListadoAVL;
int tiempoDeListadoBTREE;


//estructura de votantes
typedef struct T_Votante { 
    char cedula[10];
    char codelec[7];
    char sexo;
    char fecha[9];
    char numjun[6];
    char nombre[31];
    char papellido[27];
    char sapellido[27];
    T_Votante * PtrSiguiente;
}*PtrT_Votante;



//=======================================================================================================================
//funciones de lo que debería ir en los headers (arreglar después)

//Funcion para agregar un votante, recibe como parametro la lista de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo de la lista de votantes
void agregarvotante(PtrT_Votante& ListaV, char agregado[118]) {
    PtrT_Votante Aux = new (T_Votante);
    Aux->PtrSiguiente = ListaV;
    ListaV = Aux;

    for (int ce = 0; ce < 9; ce++) {
        ListaV->cedula[ce] = agregado[ce];
    }
    ListaV->cedula[9] = '\0';

    for (int co = 10; co < 16; co++) {
        ListaV->codelec[co - 10] = agregado[co];
    }
    ListaV->codelec[6] = '\0';

    ListaV->sexo = agregado[17];


    for (int fe = 19; fe < 27; fe++) {
        ListaV->fecha[fe - 19] = agregado[fe];
    }
    ListaV->fecha[8] = '\0';

    for (int nu = 28; nu < 33; nu++) {
        ListaV->numjun[nu - 28] = agregado[nu];
    }
    ListaV->numjun[5] = '\0';

    for (int nom = 34; nom < 64; nom++) {
        ListaV->nombre[nom - 34] = agregado[nom];
    }
    ListaV->nombre[30] = '\0';

    for (int pa = 65; pa < 91; pa++) {
        ListaV->papellido[pa - 65] = agregado[pa];
    }
    ListaV->papellido[26] = '\0';

    for (int sa = 92; sa < 118; sa++) {
        ListaV->sapellido[sa - 92] = agregado[sa];
    }
    ListaV->sapellido[26] = '\0';

}



//Funcion para cargar los votantes, se encarga de tomar cada una de las lineas
//directo del archivo de texto y enviarlo a la funci�n encargada de extraer cad uno
// de los datos e incorporarlos en un nodo de la lista.
void CargarVotantes(PtrT_Votante& ListaV) {
    int cont = 1;
    time_t inicio, fin;
    inicio = time(NULL);
    FILE* archivo;
    fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo");
    }
    else {
        char agregado[119];
        while (fgets(agregado, 119, archivo) != NULL) {
            if (cont % 2 != 0) {
                agregarvotante(ListaV, agregado);
            }
            cont++;
        }
        fclose(archivo);
    }

    fin = time(NULL);
    cout << "----------------------------Padron cargado--------------------------------" << endl;
    printf("\nEl cargado del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
    cout << "----------------------------Padron cargado--------------------------------" << endl;
    system("pause");
}


//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista enlazada hasta dejar la lista en NULL

void LiberarVotantes(PtrT_Votante& ListaV) {
    PtrT_Votante Aux = ListaV;
    time_t inicio, fin;

    inicio = time(NULL);

    while (Aux != NULL) {
        ListaV = ListaV->PtrSiguiente;
        delete(Aux);
        //Globalfree(Aux);
        Aux = ListaV;
    }

    fin = time(NULL);

    cout << "----------------------------Padron liberado--------------------------------" << endl;
    printf("\nLa liberacion del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
    cout << "----------------------------Padron liberado--------------------------------" << endl;
    system("pause");
}


//Funci�n para inicializar la lista de votantes
void inicializarvotantes(PtrT_Votante& ListaV) {
    ListaV = NULL;
}

PtrT_Votante BuscarVotante(PtrT_Votante& Lista, char cual[9])
{
    bool encontro = false;
    PtrT_Votante Aux;
    Aux = Lista;

    while ((!encontro == true) && (Aux != NULL))
    {
        if (strncmp(Aux->cedula, cual, 9) == 0)
            encontro = true;
        else
            Aux = Aux->PtrSiguiente;
    }
    return Aux;
}

//==========================================================================================================================









void cargarDatos(PtrT_Votante& ListaV) {
    //Aquí se deben cargar los datos en la lista maestra, luego cargar la lista en todas las estructuras de datos.

    CargarVotantes(ListaV);

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

void liberarMem(PtrT_Votante& ListaV) {// usar la funcion de liberar memoria con cada una de las estructuras
    cout << "" << endl;
    LiberarVotantes(ListaV);
}

void reporte() { // generar el reporte a partir de las variables que deben almacenar los tiempos de cada ejecución.
    cout << "" << endl;
}


int main()
{
    int option;
    int option1;
    char cedula[10];

    PtrT_Votante listMaestra;
    inicializarvotantes(listMaestra);
    
    
    
    cout << "Proyecto 1B" << endl;
    cout << "Comparador de rendimiento de estructuras de datos\nInterfaz gráfica para la ultima entrega.\n" << endl;
    
    cout << "Seleccione una opción: " << endl;
    cout << " 1) cargar datos" << endl;
    cout << " 2) salir" << endl;
    cin >> option1;

    switch (option1)
    {
    case 1: 
        cout << "Espere mientras se cargan los datos en la lista maestra..." << endl;
        cargarDatos(listMaestra);
        
        break;
    default:
        return 0;
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
            liberarMem(listMaestra);
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



