#ifndef PARSEADOR_H
#define PARSEADOR_H
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <list>

/*
* Clase Parseador, a partir de un string parsea
* su contenido y lo almacena.
*/

class Parseador{
	std::string instrucciones;
	std::string etiqueta;
	std::list<std::string> etiquetas_jmp;
	bool tiene_etiqueta;

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
	// Almacena la linea.
	void agregar_linea(std::string linea);
	// Devuelde true si tiene_etiqueta es true.
	// false en caso contrario.
	bool tieneEtiqueta();
	// Devuelve true si el nodo se inicializo vacio.
	// false en caso contrario.
	bool esNodoVacio();
	// Devuelve true si no es intruccion jmp
	// false en caso contrario.
	bool esInstruccion();
	// Devuelve true si es intruccion ret
	// false en caso contrario.
	bool esRet();
	// Devuelve true si es jmp incondicional
	// false en caso contrario.
	bool esJmpIncondicional();
	// Devuelve la lista de etiquetas_jmp
	// almacenada
	std::list<std::string> obtenerEtiquetaJmp();
	// Devuelve la etiqueta almacenada
	std::string obtenerEtiqueta();
	// Devuelve la instruccion almacenada.
	std::string obtenerInstruccion();
};	

#endif
