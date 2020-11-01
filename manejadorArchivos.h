#ifndef MANEJADOR_ARCHIVOS
#define MANEJADOR_ARCHIVOS
#include <list>
#include <mutex>

class ManejadorArchivos{
	std::list<const char*> archivos;
	std::mutex mutex;

public:
	const char* getArchivo();
	void recibirArchivos(const char* archivo);
};

#endif
