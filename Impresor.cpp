#include "Impresor.h"

void Impresor::almacenarResultado(std::string resultado){
	std::lock_guard<std::mutex> lock (this->mutex);
	this->impresion.push_back(resultado);
}

void Impresor::imprimirResultados(){
	this->impresion.sort();
	std::list<std::string>::iterator it;
	for(it = this->impresion.begin(); it!= 
		this->impresion.end(); it++){
		std::cout << (*it) << '\n';
	}
}
