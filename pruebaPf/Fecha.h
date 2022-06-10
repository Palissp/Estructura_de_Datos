#ifndef FECHA_H
#define FECHA_H

class Fecha
{
	public:
		bool continuar(char mensaje[]);
		bool validarIMes(string,string);
		bool validarIDia(string,string,string);
		string registrarFechaS(string);
		string ingresoFecha(string);
		const string obtenerFechaActual();
		int rangoDia(string ,string);
	protected:		
	private:
};

#endif