#include "manejadorArchivos.h"

void ManejadorArchivos::recibirArchivos(const char* archivo){
	this->archivos.push_back(archivo);
}

const char* ManejadorArchivos::getArchivo(){
	if(archivos.empty()){
		return NULL;
	}
	std::lock_guard<std::mutex> lock(this->mutex);
	const char* arc = this->archivos.back();
	this->archivos.pop_back();
	return arc;
}
