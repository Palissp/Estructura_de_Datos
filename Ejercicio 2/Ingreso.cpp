#include "Ingreso.h"
#include <string>
#include <iostream>
using namespace std;
template <typename T >
T Ingreso<T>::ingresarDatos(char *msg){
	char *dato= new char[10];
	char c;
	string dat;
	int i=0;
	printf("%s\n",msg);
	while((c=getch())!=13)
	{
		if(c>='0' && c<='9'|| c>='a' && c<='z'|| c>='A' && c<='Z' || c=='.')
		{
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	dat=dato;
	return dat;
}


