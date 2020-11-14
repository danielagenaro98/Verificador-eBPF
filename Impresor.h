#ifndef IMPRESOR
#define IMPRESOR
#include <string>
#include <list>
#include "Grafo.h"
#include "Parseador.h"

/*
* Clase Impresor: se encarga de imprimir todos
* los resultados obtenidos de los N threads 
* ejecutados.
*/

class Impresor{
	std::list<std::string> impresion;
	std::mutex mutex;

public:
	// Almacena un resultado en lista impresion.
	// Pre: la lista fue inicializada.
	void almacenarResultado(std::string resultado);
	// Imprime los resultados almacenados en 
	// impresion en orden alfabetico.
	// Pre: la lista fue inicializada.
	void imprimirResultados();
};

#endif
