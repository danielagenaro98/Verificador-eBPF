#ifndef MANEJADOR_ARCHIVOS
#define MANEJADOR_ARCHIVOS
#include <list>
#include <mutex>

/*
* Clase ManejadorArchivos, dada una cantidad N
* de nombre de archivos los almacena en lista, 
* archivos para luego al ser solicitados por los
* threads entregarlos en forma ordenada.
*/

class ManejadorArchivos{
	std::list<const char*> archivos;
	std::mutex mutex;

public:
	// devuelve un nombre de archivo.
	// Pre: la lista archivos fue inicializada.
	const char* getArchivo();
	// almacena en lista archivos el nombre de 
	// archivo
	// Pre: la lista archivos fue inicializada.
	void recibirArchivos(const char* archivo);
};

#endif
