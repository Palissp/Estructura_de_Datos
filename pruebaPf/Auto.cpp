#include "Auto.h"
Auto::Auto()
{
	this->placa = "";
	this->modelo = "";
	this->descripcionM = "";
	this->fechaIngreso="";
	this->fechaSalida="";
	this->diasM=0;
	this->piezas="";
}

Auto::~Auto()
{
}

Auto::Auto(string fechaIngreso,string placa, string marca,string modelo,string color, string descripcionM,string piezas,string costo){
	this->fechaIngreso = fechaIngreso;
	this->fechaSalida = "";
	this->placa = placa;
	this->marca=marca;
	this->color=color;
	this->modelo = modelo;
	this->descripcionM = descripcionM;
	this->diasM=0;
	this->piezas=piezas;
	this->costo=costo;
}
void Auto::setFechaIngreso(string _fechaI){
	this->fechaIngreso = _fechaI;
}

string Auto::getFechaIngreso(){
	return this->fechaIngreso;
}

void Auto::setFechaSalida(string _fechaS){
	this->fechaSalida = _fechaS;
}
string Auto::getFechaSalida(){
	return this->fechaSalida;
}

void Auto::setPlaca(string _placa){
	this->placa = _placa;
}
string Auto::getPlaca(){
	return this->placa;
}

void Auto::setMarca(string _marca)
{
	this->marca=_marca;
}
string Auto::getMarca()
{
	return this->marca;
}

void Auto::setColor(string _color)
{
	this->color=_color;
}
string Auto::getColor()
{
	return this->color;
}

void Auto::setModelo(string _modelo){
	this->modelo = _modelo;
}
string Auto::getModelo(){
	return this->modelo;
}


void Auto::setDescripcionM(string _descripcion){
	this->descripcionM = _descripcion;
}
string Auto::getDescripcionM(){
	return this->descripcionM;
}

void Auto::setDiasM(int _diasM){
	this->diasM = _diasM;
}
int Auto::getDiasM(){
	return this->diasM;
}

void Auto::setPiezas(string _piezas){
	this->piezas = _piezas;
}
string Auto::getPiezas(){
	return this->piezas;
}

void Auto::setCosto(string _costo){
	this->costo = _costo;
}
string Auto::getCosto(){
	return this->costo;
}
