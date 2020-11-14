#include <string>
#include <thread>
#include <vector>
#include "lectorArchivos.h"
#include "manejadorArchivos.h"
#include "Impresor.h"
#include "Threadverificador.h"

int main(int argc, char *argv[]){ 
  if (argc < 3){
    return -1;
  }
  std::vector<ThreadVerificador*> listaThreads;

  int numeroHilos = std::atoi(argv[1]);
  ManejadorArchivos manejador;
  Impresor impresor;
  int count = 0;
  for (int i=2; i<argc; i++){
    manejador.recibirArchivos(argv[i]);
    count++;
  }
  if(count < numeroHilos){
    numeroHilos = count;
  }
  for (int i=0; i<count; i++){
    listaThreads.push_back(new ThreadVerificador(&manejador, &impresor));
  }
  for (int i=0; i<count; i++){
    listaThreads[i]->start();
  }
  for (int i=0; i<count; i++){
    listaThreads[i]->join();
    delete listaThreads[i];
  }

  impresor.imprimirResultados();
}
