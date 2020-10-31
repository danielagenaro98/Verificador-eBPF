#include "Impresor.h"

//esta lleva mutex
void Impresor::almacenarResultado(std::string resultado){
	this->impresion.push_back(resultado);
}

void Impresor::imprimirResultados(){
	this->impresion.sort();
	std::list<std::string>::iterator it;
	for(it = this->impresion.begin(); it!= this->impresion.end(); it++){
		std::cout << (*it) << '\n';
	}
}