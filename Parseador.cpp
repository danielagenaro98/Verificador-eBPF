#include "Parseador.h"

void Parseador::agregar_linea(std::string linea){
	std::string str = "";
	if(linea.compare(str) == 0){
		this->instrucciones = linea;
		this->tiene_etiqueta = false;
	}else{
		std::string resultado = buscar_etiqueta(linea);
		parsear_instrucciones(resultado);
	}
}

std::string Parseador::buscar_etiqueta(std::string linea){
    size_t pos = 0;
    std::string instrucciones;

	if ((pos = linea.find(':')) != std::string::npos){
    	std::string token = linea.substr(0, pos);
    	this->etiqueta = token;
    	this->tiene_etiqueta = true;
    	instrucciones = linea.substr(pos+1, linea.length());
	}else{
    	this->tiene_etiqueta = false;
    	instrucciones = linea;
	}
	return instrucciones;
}

void Parseador::buscar_etiquetas_jmp(std::string delimitador, 
	std::string linea){

	size_t pos = 0;
	std::string aux = linea;
	std::string token;

	while ((pos = aux.find(delimitador)) != std::string::npos){
		token = aux.substr(0, pos);
		aux.erase(0, pos + 1);
		aux = trim(aux);
		this->etiquetas_jmp.push_back(aux);
	}
}

void Parseador::parsear_instrucciones(std::string linea){
	linea = trim(linea);
	size_t pos = 0;
	std::string segment;

	if(linea.at(0) != 'j'){
		this -> instrucciones = linea;
		return;
	}
	if((pos = linea.find(",")) != std::string::npos){ 
		buscar_etiquetas_jmp(",", linea);
	}else{
		buscar_etiquetas_jmp(" ", linea);
	}
	this -> instrucciones = linea;
}

std::string Parseador::trim(const std::string str){
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first){
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool Parseador::compararNodos(Parseador* nodo){
	if(nodo->obtenerInstruccion().compare(this->instrucciones) == 0){
		if((nodo->tieneEtiqueta()) && (this->tiene_etiqueta)){
			if(nodo->obtenerEtiqueta().compare(this->etiqueta) == 0){
			 	return true;
			}
		}else if((!nodo->tieneEtiqueta()) && 
			(!this->tiene_etiqueta)){
			return true;
		}
	}
	return false;
}

std::list<std::string> Parseador::obtenerEtiquetaJmp(){
	return this->etiquetas_jmp;
}

bool Parseador::esNodoVacio(){
	return (this->instrucciones.compare("") == 0);
}

bool Parseador::esInstruccion(){
	return (this->instrucciones.at(0) != 'j');
}

bool Parseador::esRet(){
	return (this->instrucciones.at(0) == 'r');
}

bool Parseador::tieneEtiqueta(){
	return this->tiene_etiqueta;
}

bool Parseador::esJmpIncondicional(){
	return ((this->instrucciones.find("jmp ") != std::string::npos) 
	|| (this->instrucciones.find("ja ") != std::string::npos));
}


std::string Parseador::obtenerEtiqueta(){
	return this->etiqueta;
}

std::string Parseador::obtenerInstruccion(){
	return this->instrucciones;
}
