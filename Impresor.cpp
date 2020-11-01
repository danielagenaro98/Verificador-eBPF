#include "Impresor.h"

void Impresor::almacenarResultado(std::string resultado){
	mutex.lock();
	this->impresion.push_back(resultado);
	mutex.unlock();
}

void Impresor::imprimirResultados(){
	this->impresion.sort();
	std::list<std::string>::iterator it;
	for(it = this->impresion.begin(); it!= 
		this->impresion.end(); it++){
		std::cout << (*it) << '\n';
	}
}