#if !defined(__Menu_h)
#define __Menu_h
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "Persona.cpp"
#include "Auto.cpp"
#include "Lista.cpp"
#include "Nodo.cpp"
#include "Fecha.cpp"
#include "Validacion.h"
using namespace std;

Persona agregarPersonas(Lista &lista);
Auto agregarAuto(Lista &lista);

class Menu {
public:
Menu() {

*(menuHead + 0) = "\tRegistrar";//0
*(menuHead + 1) = "\tMostrar";//1
*(menuHead + 2) = "\tBuscar";//2
*(menuHead + 3) = "\tArchivar";//3
*(menuHead + 4) = "\tAyuda";//4

*(menuHead + 5) = "\tSalir";//3

*(continuar + 0) = "Si";
*(continuar + 1) = "No";
}
~Menu(){
}
int menu() {
	int cursor = 0;
	char tecla;
	for (;;) {
	system("cls");
	cout <<"\t\t--------------------------" << endl;
	cout << "\t\t REGISTRO DE AUTOMOVILES" << endl;
	cout <<"\t\t--------------------------\n" << endl;
	for (int i = 0; i < 6; i++) {
	if (cursor == i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	cout << *(menuHead + i) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	else {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << *(menuHead + i) << endl;
	}
	}
	for (;;) {
	tecla = _getch();
	if (tecla == 80) {
	cursor++;
	if (cursor == 6) {
	cursor = 0;
	}
	break;
	}
	if (tecla == 72) {
	cursor--;
	if (cursor == -1) {
	cursor = 6;
		}
		break;
		}
			if (tecla == 13) {
			return cursor;
			}
		}
	}
}

void menuPrincipal()
{
    bool repite = true;
    int opcion,num;	
	Lista lista;
	
	do{
		opcion = menu();
        switch(opcion){
        case 0:
        	system("cls");
            lista.insertarCabeza(agregarAuto(lista),agregarPersonas(lista));
            system("pause");
            break;
        case 1:{
        	system("cls");
        	cout <<"\n\t\t-----------------" << endl;
        	cout<<"\t\tDATOS INGRESADOS\n";
        	cout <<"\t\t------------------\n" << endl;
        	lista.imprimir();
            cout<<endl;
            system("pause");
			break;
		}
        case 2:{
        	system("cls");
        	string id;
        	cout <<"\t\t----------------\n" << endl;
        	cout<<"\t\tBUSCAR CLIENTE\n";
        	cout <<"\t\t----------------\n" << endl;
        	cout<<"\n\tIngrese cedula:  ";
        	cin>>id;
        	lista.buscaPersona(id);
        	system("pause");
			break;
		}
		
  		case 3:{
			lista.archivo();
			break;
		}
		case 4:{
			
			cout<<"\nLa ventana de ayuda se activo, cierrela para continuar"<<endl;
			system("Ayuda.chm");
			system("pause");
			break;
		}
        case 5:{
            cout << "\nGracias por utilizar nuestro programa" << endl;
            repite = false;
            system("pause");
			break;
		}
		
    }
     }while(repite);
}



private:
string* menuHead = new string[6];
string* continuar = new string[2];
};
#endif


Persona agregarPersonas(Lista &lista)
{
    string direccion;
	string primerNombre;
    string segundoNombre;
    string apellido;
    string placa;
    string dir;
    string telefono;
    int cedula;
    cout<<"\t------------------------";
    cout<<"\n\tREGISTRO DE INFORMACION";
    cout<<"\n\t------------------------\n\n";
    
    cout<<"\n\tDatos Cliente ";
    cout<<"\n\tIngresar la cedula: ";
    fflush(stdin);
    cedula=ingresarEntero();
    
    while(!validarCedula(to_string(cedula)))
    {
        cout<<"\n\tNumero de cedula no valido, reingrese: ";
        cedula=ingresarEntero();
        
    }
    
	cout<<"\n\tIngrese primer nombre: ";
    primerNombre = ingresarLetra();
    cout<<"\n\tIngrese el segundo nombre: ";
    segundoNombre = ingresarLetra();
    cout<<"\n\tIngrese su apellido: ";
    apellido= ingresarLetra();
    fflush(stdin);
	cout<<"\n\tIngrese la direccion: ";
	getline(cin, direccion);

	do{
		cout<<"\n\tIngrese # de celular: ";
    	fflush(stdin);
    	telefono = ingresarEnteroT();
	}while(telefono.size()!=10);

    Persona persona(to_string(cedula),primerNombre,segundoNombre,apellido,direccion,telefono);
    return persona;
}

Auto agregarAuto(Lista &lista)
{
	Fecha fecha;
	string placa;
	string fechaI=fecha.obtenerFechaActual(); 
    string modelo;
    string color;
    string marca;
    string descripcion;
    string piezas;
    string costo;
      cout<<"\n\tDatos Auto "<<endl;
    cout<<"\n\tIngrese la Marca: ";
    fflush(stdin);
    marca= ingresarLetra();
    cout<<"\n\tIngrese el Modelo: ";
    fflush(stdin);
   	getline(cin, modelo);
    cout<<"\n\tIngrese el color: ";
    fflush(stdin);
    color= ingresarLetra();
    cout<<"\n\tIngrese Placa: ";
    fflush(stdin);
    cin>>placa;
    while(!lista.buscarDuplicadoPlaca(placa))
    {
        cout<<"\n\tLa placa ya esta ingresada, reingrese: ";
        cin>>placa;
    }
    while(!validarPlaca(placa.size())){
    	cout<<"\n\tNo valido, reingrese: ";
    	cin>>placa;
	}
    cout<<"\n\tIngrese el problema mecanico del auto:";
    fflush(stdin);
	getline(cin, descripcion);
    cout<<"\n\tIngrese las piezas necesarias:";
    fflush(stdin);
    getline(cin, piezas);
    do{
	    cout<<"\n\tIngrese el costo:";
	    fflush(stdin);
	    getline(cin, costo);
    }while(!validarDecimal(costo));

    Auto carro(fechaI,placa,marca,modelo,color,descripcion,piezas,costo);
    cout<<"\n\tSe ha ingresado correctamente los datos del cliente y el auto \n"<<endl;
    return carro;
}