#ifndef THREAD_VERIFICADOR
#define THREAD_VERIFICADOR
#include "Thread.h"
#include "lectorArchivos.h"
#include "manejadorArchivos.h"
#include "Impresor.h"

class ThreadVerificador : public Thread{
	ManejadorArchivos* manejador;
	Impresor* impresor;

public:
	ThreadVerificador(ManejadorArchivos* manejador, 
		Impresor* impresor);
	void run() override;
};

#endif
