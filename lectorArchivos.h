#ifndef LECTOR_ARCHIVOS
#define LECTOR_ARCHIVOS
#include <fstream>
#include <string>
#include <iostream>
#include "Grafo.h"
#include "Parseador.h"

class LectorArchivos{
	Grafo g;
	const char* nombreArchivo;

public:
	void leer_codigo(const char* archivo);
	std::string verificar();
};

#endif
