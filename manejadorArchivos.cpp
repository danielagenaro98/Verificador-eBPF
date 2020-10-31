#include "manejadorArchivos.h"


void ManejadorArchivos::recibirArchivos(const char* archivo){
	this->archivos.push_back(archivo);
}

//esta lleva mutex
const char* ManejadorArchivos::getArchivo(){
	if(archivos.empty()){
		return NULL;
	}
	const char* arc = this->archivos.back();
	this->archivos.pop_back();
	return arc;
}