#include "Threadverificador.h"

ThreadVerificador::ThreadVerificador(ManejadorArchivos* 
	manejadorRef, Impresor* impresorRef){
	this->manejador = manejadorRef;
	this->impresor = impresorRef;
}

void ThreadVerificador::run(){
	const char* archivo;
	while((archivo = this->manejador->getArchivo())){
    	LectorArchivos lector;
    	lector.leer_codigo(archivo);
    	std::string resultado = lector.verificar();
    	this->impresor->almacenarResultado(resultado);
    }
}