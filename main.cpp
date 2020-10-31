#include <string>
#include <thread>
#include "lectorArchivos.h"
#include "manejadorArchivos.h"
#include "Impresor.h"


int main(int argc, char *argv[]){
  
  if(argc < 3){
    return -1;
  }
  //argv[1] = numero hilos
  const char* archivo;
  ManejadorArchivos manejador;
  Impresor impresor;
  //ThreadVerificador thread;

  for(int i=2; i<argc; i++){
    manejador.recibirArchivos(argv[i]);
  }

  //thread.run();

  //esto es lo que tiene que hacer el thread;
  while((archivo = manejador.getArchivo())){
    LectorArchivos lector;
    lector.leer_codigo(archivo);
    std::string resultado = lector.verificar();
    impresor.almacenarResultado(resultado);
  }

  impresor.imprimirResultados();
}