#ifndef GRAFO_H
#define GRAFO_H
#include<list>	
#include<bits/stdc++.h>
#include "Parseador.h"
using namespace std;
 
class Grafo{
    list<list<Parseador*>> *adyacentes; //puntero a lista de adyacencias. 
    bool esCiclico;
    bool instruccionSinUsar;
    void agregarNodoAdyacente(Parseador* nodo);
    void agregarAdyacenteEtiqueta(Parseador* nodo);
    std::list<Parseador*> obtenerNodosAdyacentes(Parseador* nodo);
    bool nodoEstaEnLista(Parseador *nodo, std::list<Parseador*> lista);
    void detectarCiclos(Parseador *nodo, std::list<Parseador*> *visitados, std::list<Parseador*> *stack);
    void agregarListaAdy(Parseador *nodo);
    void agregarNodoConEtiqueta(Parseador *nodo);
    void agregarAdyacentesNodo(Parseador *nodo, Parseador *nodo_ant);
    Parseador* buscarNodoConEtiqueta(std::string etiqueta);
    int obtenerEtiquetasNodo(Parseador *nodo_ant);
    
public: 
    Grafo(); // Constructor 
    void agregarNodo(Parseador *nodo); // to agrega un nodo al grafo to graph 
    void DFS();
    void imprimirGrafo();
    void destruirGrafo();
    void ultimoNodo();
    bool tieneCliclos();
    bool tieneInstruccionesSinUsar();
};

#endif