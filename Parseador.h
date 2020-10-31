#ifndef PARSEADOR_H
#define PARSEADOR_H
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <list>

class Parseador{
	std::string instrucciones;
	std::string etiqueta;
	std::list<std::string> etiquetas_jmp;
	bool tiene_etiqueta;

	std::string buscar_etiqueta(std::string linea);
	void parsear_instrucciones(std::string linea);
	std::string trim(const std::string str);
	void buscar_etiquetas_jmp(char delimitador, std::string linea);
public:
	void agregar_linea(std::string linea);
	bool tieneEtiqueta();
	bool compararNodos(Parseador* nodo);
	bool esNodoVacio();
	bool esInstruccion();
	bool esRet();
	std::list<std::string> obtenerEtiquetaJmp();
	std::string obtenerEtiqueta();
	std::string obtenerInstruccion();
};	

#endif

//veiga@fiuba.ar