#include "manejadorArchivos.h"

void ManejadorArchivos::recibirArchivos(const char* archivo){
	this->archivos.push_back(archivo);
}

const char* ManejadorArchivos::getArchivo(){
	std::lock_guard<std::mutex> lock(this->mutex);
	if(archivos.empty()){
		return NULL;
	}
	const char* arc = this->archivos.back();
	this->archivos.pop_back();
	return arc;
}
