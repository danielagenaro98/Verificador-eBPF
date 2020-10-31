#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include "Parseador.h"
using namespace std;

//En manejador de archivos agregar validaciones de argv.

int main(int argc, char *argv[]) {
  string line;
  ifstream myfile (argv[2]);
  Grafo g;

  if (myfile.is_open()){
    while (1){
      if(!getline(myfile, line)){
        g.ultimoNodo();
        break;
      }
    	Parseador* nodo = new Parseador();
    	nodo->agregar_linea(line);
    	g.agregarNodo(nodo);
    }
    myfile.close();
  } else{
  	std::cout << "Unable to open file";
  } 

  g.imprimirGrafo();
  g.DFS();

  if(g.tieneCliclos()){
    std::cout << argv[2] << " FAIL: cycle detected" << '\n';
  }else if(g.tieneInstruccionesSinUsar()){
    std::cout << argv[2] << " FAIL: unused instructions detected"<< '\n';
  }else{
    std::cout << argv[2] << " GOOD"<< '\n';
  }

  g.destruirGrafo();

  return 0;
}