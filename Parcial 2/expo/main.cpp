#include <iostream>
#include"Operaciones.h"
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Programa: Busqueda binaria
 * Autor:  Marco Perez, Jorge Nasimba
 * Fecha de creacion: Lunes, Junio 20, 2022
 * Fecha de modificacion: Martes, Junio 21, 2022
 * Grupo 10 
 * Github:https://github.com/Palissp/Estructura_de_Datos 
 * Version 1
 * NRC: 4683
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
 
 
using namespace std;
int main(int argc, char** argv) {
	
	int clave =0;
    int tam ;
    
    Operaciones op;
    cout<<"Ingrese el tamanio:";
    cin>>tam;
    int* arreglo =new int[tam];
    //int *arreglo=(int*)malloc(tam*sizeof(int));
    //arreglo=(int*)realloc(arreglo,10*sizeof(int));
   
    
    
    op.ingresarDatos(arreglo,tam);
    cout << "Elementos del arreglo: " << endl;
    op.ordenarArreglo(arreglo,tam);
    op.mostrarArreglo(arreglo,tam);
    cout << "Indique un valor a buscar y se le devolvera el indice: ";
    cin >> clave;
    if(op.busquedaBinaria(arreglo,tam,clave)!=-1)
    	cout<< "Su valor se encuentra en arreglo["<<op.busquedaBinaria(arreglo,tam,clave)<<"]" << endl;
	else
		cout<<"El valor ingresado no se encuentra registrado"<<endl;
	return 0;
}




