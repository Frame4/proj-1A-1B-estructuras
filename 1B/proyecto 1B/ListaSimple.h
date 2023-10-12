
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



using namespace std;
//******************************************
typedef struct TArticulo
{	
	char cedula[10];
	char codelec[7];
	char sexo;
	char fecha[9];
	char numjun[6];
	char nombre[31];
	char papellido[27];
	char sapellido[27];
	/*
	int Codigo;
	char Nombre[20];
	int Disponible;
	float Precio;
	*/
	TArticulo *Siguiente;
}*PtrTArticulo;


//******************************************

int i;  //parametro global


void InicializarInventario(PtrTArticulo &Lista)
{
	Lista = NULL;
}
void DestruirInventario(PtrTArticulo &Lista)
{
	PtrTArticulo Aux;
	Aux = Lista;
	while (Aux != NULL)
	{
		Lista = Lista->Siguiente;
		delete(Aux);
		Aux = Lista;
	}
}
/*
PtrTArticulo CrearArticulo(int NCodigo, int NDisponible, float NPrecio)
{
	PtrTArticulo Pieza = new(TArticulo);
	char buffer[5];

	Pieza->Codigo = NCodigo;
	Pieza->Disponible = NDisponible;
	Pieza->Precio = NPrecio;

	strcpy_s(Pieza->Nombre, "Pieza");
	_itoa_s(NCodigo, buffer, 10);
	strcat_s(Pieza->Nombre, buffer);

	Pieza->Siguiente = NULL;
	return Pieza;
}
*/
void AgregarInicioInventario(PtrTArticulo &Lista, PtrTArticulo &Nuevo)
{
	Nuevo->Siguiente = Lista;
	Lista = Nuevo;
}
void AgregarFinalInventario(PtrTArticulo &Lista, PtrTArticulo &Nuevo)
{
	PtrTArticulo Aux;
	Aux = Lista;
	if (Aux != NULL)
	{
		while (Aux->Siguiente != NULL)
		{
			Aux = Aux->Siguiente;
		}

		Aux->Siguiente = Nuevo;
	}
	else
	{
		Lista = Nuevo;
	}


}
void ListarInventario(PtrTArticulo &Lista)
{
	int Contador = 1;
	PtrTArticulo Aux;
	Aux = Lista;
	while (Aux != NULL)
	{
		cout << "Ce'dula: " << Aux->cedula << endl;
		cout << "Nombre: " << Aux->nombre << endl;
		cout << "Primer Apellido: " << Aux->papellido << endl;
		cout << "Segundo Apellido: " << Aux->sapellido << endl;
		cout << "Sexo: " << Aux->sexo << endl;
		cout << "Fecha: " << Aux->fecha << endl;
		cout << "Co'digo Electoral:  " << Aux->codelec << endl;
		cout << "Nu'mero Junta: " << Aux->numjun << endl;
		Aux = Aux->Siguiente;
		Contador++;
	}
}
PtrTArticulo BuscarArticulo(PtrTArticulo &Lista, char cual[10])
{
	bool encontro = false;
	PtrTArticulo Aux;
	Aux = Lista;

	while (encontro != true && Aux != NULL)
		if (Aux->cedula == cual)
			encontro = true;
		else
			Aux = Aux->Siguiente;
	return Aux;
}

/*
void GuardarInventario(PtrTArticulo Lista){
	FILE *archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "w+");
	if (NULL == archivo){
		printf("No se pudo abrir el archivo.");
	}
	else{
		PtrTArticulo AUX = Lista;
		while (AUX != NULL){
			fprintf(archivo, "%i\n", AUX->Codigo);
			fprintf(archivo, "%s\n", AUX->Nombre);
			fprintf(archivo, "%i\n", AUX->Disponible);
			fprintf(archivo, "%f\n", AUX->Precio);
			AUX = AUX->Siguiente;
		}


	}
	fclose(archivo);
}
*/

/*
void CargarInventario(PtrTArticulo &Lista){
	PtrTArticulo Nuevo;
	FILE *archivo;
	fopen_s(&archivo, "ARCHIVO.txt", "r");
	if (NULL == archivo){
		printf("No se pudo abrir el archivo");
	}
	else{


		while (!feof(archivo)){
			Nuevo = new(TArticulo);
			char Cadena[20];
			fscanf_s(archivo, "%i\n", &Nuevo->Codigo);
			fscanf_s(archivo, "%s\n", Cadena, 20);
			fscanf_s(archivo, "%i\n", &Nuevo->Disponible);
			fscanf_s(archivo, "%f\n", &Nuevo->Precio);
			strcpy_s(Nuevo->Nombre, Cadena);
			Nuevo->Siguiente = NULL;
			AgregarFinalInventario(Lista, Nuevo);

		}
	}
	fclose(archivo);
}
*/



/*
void main(int argc, char* argv[])
{
	//************************************************************************
	PtrTArticulo Llantas;
	PtrTArticulo Abarrotes;
	PtrTArticulo Nuevo;
	PtrTArticulo Prueba;

	//************************************************************************	
	InicializarInventario(Abarrotes);

	for (int i = 100; i <= 200; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarInicioInventario(Abarrotes, Nuevo);
	}
	GuardarInventario(Abarrotes);
	ListarInventario(Abarrotes);
	DestruirInventario(Abarrotes);
	system("cls");
	//*************************PRUEBA DE CARGAR********************************
	InicializarInventario(Prueba);
	CargarInventario(Prueba);
	ListarInventario(Prueba);
	system("pause");
	DestruirInventario(Prueba);
	//************************************************************************
	InicializarInventario(Abarrotes);
	for (i = 200; i <= 300; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarFinalInventario(Abarrotes, Nuevo);
	}
	ListarInventario(Abarrotes);
	DestruirInventario(Abarrotes);




	//************************************************************************	
	InicializarInventario(Llantas);
	for (i = 100; i <= 200; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarInicioInventario(Llantas, Nuevo);
	}
	ListarInventario(Llantas);
	DestruirInventario(Llantas);

	//************************************************************************
	InicializarInventario(Llantas);
	for (i = 200; i <= 300; i++)
	{
		Nuevo = CrearArticulo(i, i, i);
		AgregarFinalInventario(Llantas, Nuevo);
	}
	ListarInventario(Llantas);
	DestruirInventario(Llantas);


}
*/
