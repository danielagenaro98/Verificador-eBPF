#ifndef MANEJADOR_ARCHIVOS
#define MANEJADOR_ARCHIVOS

#include <list>
#include <mutex>

class ManejadorArchivos{
	std::list<const char*> archivos;
	//std::mutex mutex;

public:
	const char* getArchivo(); //me devuelve un nombre de archivo para que el thread lo utilice y procese.
	void recibirArchivos(const char* archivo);
};

#endif