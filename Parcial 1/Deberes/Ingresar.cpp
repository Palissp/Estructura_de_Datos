#include "Ingresar.h"
#include <string.h>

string Ingresar::ingresar(char *msj){
	string dato;
	printf("%s",msj);
	cin>>dato;
	return dato;
}
void Ingresar::transformar(){
	string num;
	num=ingresar("Ingrese el numero:");
	cout<<"\nNumero transformado: "<<stoi(num);
}

