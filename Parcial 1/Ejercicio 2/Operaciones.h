#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once
using namespace std;
template <typename T >
class Operaciones{
	public:
		void menu();		
		int convertirEntero(T);
		float convertirDecimal(T);
		string convertirCadena(T);
	private:
};
