#ifndef LECTOR_ARCHIVOS
#define LECTOR_ARCHIVOS
#include <fstream>
#include <string>
#include <iostream>
#include "Grafo.h"
#include "Parseador.h"
#include "Nodo.h"

/*
* Clase LectorArchivos, dado un archivo 
* lo abre y lee todo su contenido.
*/

class LectorArchivos{
	Grafo g;
	const char* nombreArchivo;

public:
	LectorArchivos();
	// Dado un nombre de archivo, lo abre 
	// lee su contenido y cierra el archivo.
	// Pre: el nombre del archivo es valido.
	void leer_codigo(const char* archivo);
	// Dado el grafo devuelve el resultado de
	// aplicar busqueda en profundidad.
	// Pre: El grafo fue creado.
	std::string verificar();
};

#endif
