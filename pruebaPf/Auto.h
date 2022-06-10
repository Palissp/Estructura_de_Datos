#ifndef AUTO_H
#define AUTO_H

#include <iostream>

using namespace std;

class Auto
{
	public:
		Auto();
		~Auto();
		Auto(string fechaIngreso,string placa, string marca,string modelo,string color, string descripcionM,string piezas,string costo);	
			
		void setFechaSalida(string _fechaS);
		string getFechaSalida();
		
		void setFechaIngreso(string _fechaI);
		string getFechaIngreso();
			
		void setPlaca(string _placa);
		string getPlaca();
		
		void setMarca(string _marca);
		string getMarca();
	
		void setModelo(string _modelo);
		string getModelo();
		
		void setColor(string _color);
		string getColor();
		
		void setDescripcionM(string descripcionM);
		string getDescripcionM();
		
		void setDiasM(int diasM);
		int getDiasM();
		
		void setPiezas(string piezas);
		string getPiezas();
		
		void setCosto(string costo);
		string getCosto();
		
	protected:

	private:
		string fechaIngreso;
		string fechaSalida;
		string placa;
		string modelo;
		string marca;
		string color;
		string descripcionM;
		string piezas;
		string costo;
		int diasM;
};

#endif