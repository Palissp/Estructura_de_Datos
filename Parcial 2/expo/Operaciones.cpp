#include<iostream>
#include "Operaciones.h"
using namespace std;
void Operaciones::ingresarDatos(int *arreglo,int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("Ingrese el valor entero: ");
		scanf("%d",*(&arreglo)+i);
	}
}
void Operaciones::mostrarArreglo( int *arreglo, int tam)
{
	for (int i = 0 ; i < tam ; i++)
    cout << *(arreglo+i) << endl;
} 
int Operaciones::busquedaBinaria( int *arreglo, int tam, int clave)
{
	int Iarriba = tam-1;
    int Iabajo = 0;
    int Icentro;
    while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (*(arreglo+Icentro) == clave)
 	  	return Icentro;
      else
 	  	if (clave < *(arreglo+Icentro))
   	  		Iarriba=Icentro-1;
      	else
      		Iabajo=Icentro+1;
    }
  return -1;
}
void Operaciones::ordenarArreglo(int* arreglo, int tam)
{
	for (int i = 0; i< tam -1 ; i++)
    for (int j = 0; j< tam -1 ; j++)
      if (*(arreglo+j) > *(arreglo+j+1))
			 intercambiar(*(arreglo+j),*(arreglo+j+1));
}
void Operaciones::intercambiar(int &a, int &b) 
{
	int tmp = b;
  	b = a;
  	a = tmp;
}