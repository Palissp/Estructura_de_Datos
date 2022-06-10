#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Persona.h"
#include "Auto.h"
#include "Menu2.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sstream>

class Lista
{
	private:
		Nodo *primero;
		Nodo *ultimo;
	public:
		void insertarCabeza(Auto carro,Persona persona);
		Lista(){
			this->primero=NULL;
			this->ultimo=NULL;
		}
		void buscaPersona(string cedula);
		void imprimir();
		Nodo *getPrimero();
		bool buscarDuplicado(string cedula);
		bool buscarDuplicadoPlaca(string placa);
		void archivo();
};

#endif