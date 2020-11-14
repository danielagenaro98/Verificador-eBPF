#ifndef NODO_H
#define NODO_H
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <list>

/*
* Clase Nodo, tiene toda la informacion
* que se almacenara en el grafo.
*/

class Nodo{
	std::string instrucciones;
	std::string etiqueta;
	std::list<std::string> etiquetas_jmp;
	bool tiene_etiqueta;

public:
	Nodo();
	// Almacena en instrucciones el string recibido.
	void agregarInstrucciones(const std::string &inst);
	// Almacena en etiqueta el string recibido.
	void agregarEtiqueta(const std::string &etiq);
	// Almacena la lista de etiquetas recibida.
	void agregarEtiquetasJmp(const std::list<std::string> &etiquetas);
	// Setea tiene_etiqueta;
	void setEtiqueta(bool etiq);
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