#include "manejadorArchivos.h"

void ManejadorArchivos::recibirArchivos(const char* archivo){
	this->archivos.push_back(archivo);
}

const char* ManejadorArchivos::getArchivo(){
	if(archivos.empty()){
		return NULL;
	}
	mutex.lock();
	const char* arc = this->archivos.back();
	this->archivos.pop_back();
	mutex.unlock();
	return arc;
}
