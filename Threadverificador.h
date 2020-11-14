#ifndef THREAD_VERIFICADOR
#define THREAD_VERIFICADOR
#include <string>
#include "Thread.h"
#include "lectorArchivos.h"
#include "manejadorArchivos.h"
#include "Impresor.h"

/*
* Clase ThreadVerificador, hilo de ejecucion 
* al ser llamado, lee un archivo verifica si es
* ciclico o tiene instrucciones sin usar 
* y almacena los resultados.
*/

class ThreadVerificador : public Thread{
	ManejadorArchivos* manejador;
	Impresor* impresor;

public:
	// Inicializa el hilo. 
	ThreadVerificador(ManejadorArchivos* manejador, 
		Impresor* impresor);
	// Invoca a las respectivas clases para obtener 
	// los resultados.
	// Pre: el hilo fue creado con parametros 
	// ManejadorArchivos e Impresor.
	void run() override;
};

#endif
