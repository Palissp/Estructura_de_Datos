#include "Operaciones.h"
#include "Ingreso.cpp" 
#include <string>
#pragma once

template <typename T >
int Operaciones<T>::convertirEntero(T cad)
{
	int contL=0,contP=0;
	for(int i=0;i<cad.length();i++)
	{
		if(cad[i]>='a' && cad[i]<='z'|| cad[i]>='A' && cad[i]<='Z')
		{
			contL++;
		}
		if(cad[i]=='.')
		{
			contP++;
		}
	}
	if(contL>=1 || contP>=2)//es string
		return 0;
	else
		return stoi(cad);
}
template <typename T >
float Operaciones<T>::convertirDecimal(T cad)
{
	int contL=0,contP=0;
	float numer;
	for(int i=0;i<cad.length();i++)
	{
		if(cad[i]>='a' && cad[i]<='z'|| cad[i]>='A' && cad[i]<='Z')
		{
			contL++;
		}
		if(cad[i]=='.')
		{
			contP++;
		}
	}
	if(contL>=1 || contP>=2)//es string
		return 0;
	else
		return stof(cad);
}
template <typename T >
string Operaciones<T>::convertirCadena(T cad)
{
	int contL=0,contP=0;
	string c;
	for(int i=0;i<cad.length();i++)
	{
		if(cad[i]>='a' && cad[i]<='z'|| cad[i]>='A' && cad[i]<='Z')
		{
			contL++;
		}
		if(cad[i]=='.')
		{
			contP++;
		}
	}
	if(contL>=1 || contP>=2)//es string
		return cad;
	else
		return "0";
}

template <typename T >
void Operaciones<T>::menu(){
	string dat3,dat1,dat2;
	int valor,num1;
	
	Ingreso<string> ingreso;
	
	int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Convertir a entero" << endl;
        cout << "2. Convertir a decimal" << endl;
        cout << "3. Convertir a char" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1://convertir a entero
            {   
				system("cls");          
				try{
					dat1=ingreso.ingresarDatos("Ingrese:");
                	if(convertirEntero(dat1)==0)
                		throw "No se puede convertir el numero entero existen caracteres alfabeticos y especiales";
                	else
                		cout<<"\nEl numero entero es:"<<convertirEntero(dat1)<<endl;
            	}
            	catch(const char *error){
            		cout<<"\nError: "<<error<<endl;
				}
				system("pause"); // Pausa
                break;
        	}
        	
            case 2://convertir a decimal
			{   
				system("cls");          
				try{
					dat2=ingreso.ingresarDatos("Ingrese:");
                	if(convertirDecimal(dat2)==0)
                		throw "No se puede convertir el numero decimal existen caracteres alfabeticos y especiales";
                	else
                		printf("\nEl numero decimal es: %.3f\n",convertirDecimal(dat2));
            	}
            	catch(const char *error){
            		cout<<"\nError: "<<error<<endl;
				}
				system("pause"); // Pausa
                break;
        	}
                
            case 3://convertir a string
			{   
				system("cls");          
				try{
					dat3=ingreso.ingresarDatos("Ingrese:");
                	if(convertirCadena(dat3)=="0")
                		throw "No se puede convertir es un numero";
                	else
                		cout<<"\nLa cadena es: "<<convertirCadena(dat3)<<endl;
            	}
            	catch(const char *error){
            		cout<<"\nError: "<<error<<endl;
				}
				system("pause"); // Pausa
                break;
        	}
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);	
}


