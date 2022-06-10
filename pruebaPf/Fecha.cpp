#pragma once
#include "Fecha.h"
#include <ctime>
using namespace std;
bool Fecha::continuar(char mensaje[])
{
	char ch;
	printf(mensaje);
	do
	{
		scanf("%c",&ch);
		ch= toupper(ch);
	}while(ch!='S' && ch!='N');
	return(ch=='S'?true:false);
}

const string Fecha::obtenerFechaActual()
{
	time_t now = time(0); struct tm tstruct;
 	char buf[80]; tstruct = *localtime(&now);
 	strftime(buf, sizeof(buf), "%Y-%m-%d ", &tstruct);
	return buf;
}

int Fecha::rangoDia(string fechaI,string fechaS)
{
	string d,m;
	string d1,d2,m1,m2;//fecha de Ingreso
	string d3,d4,m3,m4;//fecha de Salida
	int dia1,dia2,mes1,mes2,diasD;
	d1=fechaI[8];
	d2=fechaI[9];
	m1=fechaI[5];
	m2=fechaI[6];
	d1+=d2;//dia de la  fecha de Ingreso
	dia1=stoi(d1)-1;
	m1+=m2;//mes de la fecha de Ingreso
	mes1=stoi(m1)-1;
	cout<<"FechaI:"<<dia1<<" "<<mes1;
	d3=fechaS[8];
	d4=fechaS[9];
	m3=fechaS[5];
	m4=fechaS[6];
	d3+=d4;//dia de la fecha de Salida
	dia2=stoi(d3)-1;
	m3+=m4;//mes de la fecha de Salida
	mes2=stoi(m3)-1;
	cout<<"FechaS:"<<dia2<<" "<<mes2;
	
 	struct tm fReg = {0,0,0,dia1,mes1,122};//comienza en 1900  
    struct tm fSalida = {0,0,0,dia2,mes2,122}; 
    
    time_t x = mktime(&fReg);
    time_t y = mktime(&fSalida);
    if ( x != (time_t)(-1) && y != (time_t)(-1) )
    {
        int diferencia = std::difftime(y, x) / (60 * 60 * 24);
        diasD=diferencia;
	}
    return diasD;
}

bool Fecha::validarIDia(string diaR,string diaI,string mes)//validar el numero de dias en funcion del mes de este año
{
	bool band;
	int diaReg=stoi(diaR);
	switch(stoi(mes))
	{
        case 6:{
        	if(diaReg>=stoi(diaI) && diaReg<=30)
				band=false;
			else
				band=true;
			break;
		}
        case 7:{
        	if(diaReg>=1 && diaReg<=31)
				band=false;
			else
				band=true;
			break;
		}
		case 8:{
			if(diaReg>=1 && diaReg<=31)
				band=false;
			else
				band=true;
			break;
		}
		case 9:{
			if(diaReg>=1 && diaReg<=30)
				band=false;
			else
				band=true;
			break;
		}
		case 10:{
			if(diaReg>=1 && diaReg<=31)
				band=false;
			else
				band=true;
			break;
		}
		case 11:{
			if(diaReg>=1 && diaReg<=30)
				band=false;
			else
				band=true;
			break;
		}
		case 12:{
			if(diaReg>=1 && diaReg<=31)
				band=false;
			else
				band=true;
			break;
		}
	}
		
	return band;

}

bool Fecha::validarIMes(string mesR,string mesI)
{
	bool band;
	int dato2=stoi(mesR);
	
	if(dato2>=stoi(mesI) && dato2<=12)
		band=false;
	else
		band=true;
		
	return band;
}

string Fecha::ingresoFecha(string fechaI)
{
	string d,m;
	string d1,d2,m1,m2;

	d1=fechaI[8];
	d2=fechaI[9];
	m1=fechaI[5];
	m2=fechaI[6];
	d1+=d2;//en d1 tenemos el dia a modificar, debemos validar d
	m1+=m2;//en m1 tenemos el mes a modificar, debemos validar m
	
	cout<<"Es"<<d1<<m1;
	cout << "\n\t Fecha de Salida\n" << endl;
	do
	{
		cout<<"\nIngrese el digito del Mes:"<<endl;
		cin>>m;
	}while(validarIMes(m,m1));
	
	do
	{
		cout<<"\nIngrese el digito del Dia:"<<endl;
		cin>>d;
	}while(validarIDia(d,d1,m));

	if(stoi(m)<10 && stoi(d)<10)
	{
		fechaI.replace(fechaI.find(m2),1, m);
		fechaI.replace(fechaI.find(d2),1, d);
	}
	else if(stoi(m)>=10 && stoi(d)>=10)
	{
		fechaI.replace(fechaI.find(m1),2, m);
		fechaI.replace(fechaI.find(d1),2, d);
	}
	else if(stoi(m)<10 && stoi(d)>=10)
	{
		fechaI.replace(fechaI.find(m2),1, m);
		fechaI.replace(fechaI.find(d1),2, d);
	}
	else
	{
		fechaI.replace(fechaI.find(m1),2, m);
		fechaI.replace(fechaI.find(d2),1, d);
	}
	
	return fechaI;
}

