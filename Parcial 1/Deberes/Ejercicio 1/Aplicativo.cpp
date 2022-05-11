/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Programa: Ingreso de un numero 
 * Autor:  Marco Perez, Jorge Nasimba
 * Fecha de creacion: Martes, Mayo 10, 2022
 * Fecha de modificacion: Martes, Mayo 10, 2022
 * Grupo 10 
 * Github:https://github.com/Palissp/Estructura_de_Datos 
 * Version 1
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
#include <iostream>
#include "Ingresar.cpp"



int main(int argc, char** argv) {
	Ingresar ingreso;
	string num;
	
	num=ingreso.ingresar("Ingrese el numero:");
	cout<<"\nNumero transformado: "<<stoi(num);
	return 0;
}