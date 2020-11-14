#include "Nodo.h"

Nodo::Nodo(){
	this->tiene_etiqueta = false;
}

void Nodo::agregarInstrucciones(const std::string &inst){
	this->instrucciones = inst;
}

void Nodo::agregarEtiqueta(const std::string &etiq){
	this->etiqueta = etiq;
}

void Nodo::agregarEtiquetasJmp(const std::list<std::string> &etiquetas){
	this->etiquetas_jmp = etiquetas;
}

void Nodo::setEtiqueta(bool etiq){
	this->tiene_etiqueta = etiq;
}

std::list<std::string> Nodo::obtenerEtiquetaJmp(){
	return this->etiquetas_jmp;
}

bool Nodo::esNodoVacio(){
	return (this->instrucciones.compare("") == 0);
}

bool Nodo::esInstruccion(){
	return (this->instrucciones.at(0) != 'j');
}

bool Nodo::esRet(){
	return (this->instrucciones.at(0) == 'r');
}

bool Nodo::tieneEtiqueta(){
	return this->tiene_etiqueta;
}

bool Nodo::esJmpIncondicional(){
	return ((this->instrucciones.find("jmp ") != std::string::npos) 
	|| (this->instrucciones.find("ja ") != std::string::npos));
}


std::string Nodo::obtenerEtiqueta(){
	return this->etiqueta;
}

std::string Nodo::obtenerInstruccion(){
	return this->instrucciones;
}
