#ifndef PARSEADOR_H
#define PARSEADOR_H
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include "Nodo.h"

/*
* Clase Parseador, a partir de un string parsea
* su contenido y lo genera un Nodo.
*/

class Parseador{
	Nodo *nodo;

	// Dado un string, obtiene la etiqueta que contenga
	// y la almacena en etiqueta. Devuelve las instrucciones
	// a continuacion de la etiqueta.
	// Pre: el string es valido.
	std::string buscar_etiqueta(std::string linea);
	// Dado un string, obtiene todas las intrucciones que
	// contiene.
	// Pre: el string es valido.
	void parsear_instrucciones(std::string linea);
	// Dado un string, elimina todos los espacios en blanco
	// iniciales.
	std::string trim(const std::string str);
	// Dado un string y un delimitador separa el string
	// por el delimitador y almacena el la lista de
	// etiquetas_jmp lo obtenido.
	// Pre: la lista de etiquetas fue inicializada.
	void buscar_etiquetas_jmp(std::string delimitador, 
		std::string linea);
public:
	Parseador();
	// Dada una linea la parsea y devuelve un nodo.
	Nodo* parsear_linea(std::string linea);
};	

#endif
