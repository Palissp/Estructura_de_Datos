#include "Lista.h"
#include "Fecha.cpp"
#include "Menu2.h"
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>

using namespace std;
void Lista::insertarCabeza(Auto carro,Persona persona)
{
	
    Nodo *nuevo = new Nodo(carro,persona);
    if(primero==NULL)
	{
		primero=nuevo;
		primero->setSiguiente(nuevo);
		primero->setAnterior(nuevo);
		ultimo=nuevo;
		
	}else{
		ultimo->setSiguiente(nuevo);
		nuevo->setSiguiente(primero);
		nuevo->setAnterior(ultimo);
		ultimo=nuevo;
		
	}
	ultimo->setSiguiente(primero);
}




void Lista::buscaPersona(string cedula)
{
	Fecha fecha;
	Menu2 mn;
	char mensaje[]={"\nDesea registrar la fecha de salida?S/N:"};
	Auto carro;
	int cont=1;
	if(primero!=NULL)
	{
		 Nodo *auxiliar=primero;
		do{
			if(cedula.compare(auxiliar->getPersona().getCedula()) == 0)
			{
				system("cls");
				cout<<"\n";
				Persona persona = auxiliar->getPersona();
			    carro = auxiliar->getCarro();
				cout<<"\t-----------------------------------------\n"; 
				cout<<"\n\tFecha de Ingreso: "<<carro.getFechaIngreso()<<endl;
				cout<<"\n\n\t\tDatos del Cliente"<<endl;
	            cout<<"\n\tCedula:   | "<<persona.getCedula()<<endl;
	            cout<<"\tNombre:   | "<<persona.getPrimerNombre()<<" "<<persona.getSegundoNombre()<<endl;
	            cout<<"\tApellido: | "<<persona.getApellido()<<endl;
	            cout<<"\tDireccion:| "<<persona.getDireccion()<<endl;
	            cout<<"\tTelefono: | "<<persona.getTelefono()<<endl;
	            cout<<"\n\n\t\tDatos del Auto #"<<cont<<endl;
				cout<<"\tPlaca:"<<carro.getPlaca()<<endl;
				cout<<"\tMarca:"<<carro.getMarca()<<endl;
				cout<<"\tModelo:"<<carro.getModelo()<<endl;
				cout<<"\tColor:"<<carro.getColor()<<endl;
				cout<<"\tDescripcion:"<<carro.getDescripcionM()<<endl;
				cout<<"\tPiezas:"<<carro.getPiezas()<<endl;
				cout<<"\tCosto:"<<carro.getCosto()<<"$"<<endl;
				if(auxiliar->getCarro().getFechaSalida()=="")			
					cout<<"\tFecha de Salida: No registrada"<<endl;	
				else
					cout<<"\tFecha de Salida: "<<carro.getFechaSalida()<<endl;
				if(fecha.continuar(mensaje))
					carro.setFechaSalida(mn.subMenu(carro.getFechaIngreso(),carro.getFechaSalida()));
					
				if(carro.getFechaSalida()!="")
					carro.setDiasM(fecha.rangoDia(carro.getFechaIngreso(),carro.getFechaSalida()));
					
				auxiliar->setCarro(carro);//se guardan los cambios
       		 }
            auxiliar = auxiliar->getSiguiente();
		}while(auxiliar!=primero);	
	}	
	else
	{
		cout<<"\n\tLista Vacia\n";
	}
}


void Lista::imprimir()
{
	if(primero!=NULL)
	{
		 Nodo *auxiliar=primero;
		do{
			cout<<"\n";
			Persona persona = auxiliar->getPersona();
		    Auto carro = auxiliar->getCarro();
			cout<<"\t-----------------------------------------\n"; 
			cout<<"\n\tFecha de Ingreso: "<<carro.getFechaIngreso()<<endl;
			cout<<"\n\n\t\tDatos del Cliente"<<endl;
            cout<<"\n\tCedula:   | "<<persona.getCedula()<<endl;
            cout<<"\tNombre:   | "<<persona.getPrimerNombre()<<" "<<persona.getSegundoNombre()<<endl;
            cout<<"\tApellido: | "<<persona.getApellido()<<endl;
            cout<<"\tDireccion:| "<<persona.getDireccion()<<endl;
            cout<<"\tTelefono: | "<<persona.getTelefono()<<endl;
            cout<<"\n\n\t\tDatos del Auto"<<endl;
			cout<<"\tPlaca:"<<carro.getPlaca()<<endl;//auxiliar->getCarro().getPlaca();tambien funciona
			cout<<"\tMarca:"<<carro.getMarca()<<endl;
			cout<<"\tModelo:"<<carro.getModelo()<<endl;
			cout<<"\tColor:"<<carro.getColor()<<endl;
			cout<<"\tDescripcion:"<<carro.getDescripcionM()<<endl;
			cout<<"\tPiezas:"<<carro.getPiezas()<<endl;
			cout<<"\tCosto:"<<carro.getCosto()<<"$"<<endl;
			if(auxiliar->getCarro().getFechaSalida()=="")			
				cout<<"\tFecha de Salida: No registrada"<<endl;
			else
				cout<<"\tFecha de Salida: "<<carro.getFechaSalida();
            cout<<"\tDias entre fechas: "<<carro.getDiasM()<<endl;
         	cout<<"\n\t-----------------------------------------\n"; 
            auxiliar = auxiliar->getSiguiente();
		}while(auxiliar!=primero);	
	}	
	else
	{
		cout<<"\n\tLista Vacia\n";
	}
    
}


void Lista ::archivo(){
	int cont=1;
	if(primero!=NULL)
	{
		Nodo *auxiliar=primero;
		do{
			ofstream guardar;
			guardar.open("registroClientes.txt",ios::out | ios::app);
			if(guardar.fail()){
				cout<<"No se pudo crear el archivo";
				exit(1);
			}
			
			Persona persona = auxiliar->getPersona();
			Auto carro = auxiliar->getCarro();
			guardar<<"\n-------------------------------------------------------"<<endl;
			guardar<<"\tDATOS CLIENTE Y AUTO"<<endl;
			guardar<<"Cedula: "<<persona.getCedula()<<endl;
			guardar<<"Primer nombre: "<<persona.getPrimerNombre()<<endl;
			guardar<<"Segundo nombre: "<<persona.getSegundoNombre()<<endl;
			guardar<<"Apellido: "<<persona.getApellido()<<endl;
			guardar<<"Direccion: "<<persona.getDireccion()<<endl;
			guardar<<"Telefono: "<<persona.getTelefono()<<endl;
			guardar<<"Placa:"<<carro.getPlaca()<<endl;
			guardar<<"Marca:"<<carro.getMarca()<<endl;
			guardar<<"Modelo:"<<carro.getModelo()<<endl;
			guardar<<"Color:"<<carro.getColor()<<endl;
			guardar<<"Descripcion del problema mecanico:"<<carro.getDescripcionM()<<endl;
			guardar<<"Piezas:"<<carro.getPiezas()<<endl;
			guardar<<"Costo:"<<carro.getCosto()<<"$"<<endl;
			guardar<<"Fecha de Registro del Auto:"<<carro.getFechaIngreso()<<endl;
			guardar<<"Fecha de Salida del Auto:"<<carro.getFechaSalida()<<endl;
			guardar<<"Dias entre fechas: "<<carro.getDiasM();
			guardar<<"-------------------------------------------------------"<<endl;
			guardar.close();
		    auxiliar = auxiliar->getSiguiente();
		}while(auxiliar!=primero);	
		cout<<"\nLos datos se guardaron correctamente en el archivo...";
		system("pause");
	}	
	else
	{
		cout<<"\n\tLista Vacia\n";
		system("pause");
	}	  
}

Nodo *Lista::getPrimero()
{
    return this->primero;
}



bool Lista::buscarDuplicado(string cedula){
	if(primero!=NULL)
	{
		Nodo *auxiliar=primero;
		do{
			if(auxiliar->getPersona().getCedula().compare(cedula)==0)
			{
            	return false;
       	    }
            auxiliar = auxiliar->getSiguiente();
		}while(auxiliar!=primero);	
	}	
	
	return true;
}

bool Lista::buscarDuplicadoPlaca(string placa){
    if(primero!=NULL)
	{
		Nodo *auxiliar=primero;
		do{
			if(auxiliar->getCarro().getPlaca().compare(placa)==0)
			{
            	return false;
       	    }
            auxiliar = auxiliar->getSiguiente();
		}while(auxiliar!=primero);	
	}	
	
	return true;
}

