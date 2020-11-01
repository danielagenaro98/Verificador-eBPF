#ifndef IMPRESOR
#define IMPRESOR
#include <string>
#include "Grafo.h"
#include "Parseador.h"

class Impresor{
	std::list<std::string> impresion;
	std::mutex mutex;

public:
	void almacenarResultado(std::string resultado);
	void imprimirResultados();
};

#endif
