#include "lectorArchivos.h"

void LectorArchivos::leer_codigo(const char* archivo){
	this->nombreArchivo = archivo;
	std::string line;
	std::ifstream myfile (archivo);

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
  }else{
  		std::cout << "Unable to open file";
  }

}

std::string LectorArchivos::verificar(){
	g.DFS();
  std::string resultado;
  std::string nombre(this->nombreArchivo);

	if(g.tieneCliclos()){
    	resultado = " FAIL: cycle detected";
  	}else if(g.tieneInstruccionesSinUsar()){
    	resultado = " FAIL: unused instructions detected";
  	}else{
    	resultado = " GOOD";
  }
	return nombre+resultado;
}
