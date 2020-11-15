#ifndef GRAFO_H
#define GRAFO_H
#include<list>	
#include<string>
#include<bits/stdc++.h>
#include "Nodo.h"

/*
* Clase Grafo, genera un grafo dirigido a partir
* de nodos creados previamente.
*/
 
class Grafo{
    std::list<std::list<Nodo*>> *adyacentes; 
    bool esCiclico;
    bool instruccionSinUsar;
    // Dado un nodo obtiene todos sus adyacentes.
    // Pre: el nodo fue inicializado en la matriz adyacentes.
    std::list<Nodo*> obtenerNodosAdyacentes(Nodo* nodo);
    // Dado un nodo y una lista de nodos devuelve True en caso de
    // que el nodo se encuentre en la lista, o False en caso contrario
    // Pre: El nodo y la lista apuntan a direcciones de memoria validas.
    bool nodoEstaEnLista(Nodo *nodo, std::list<Nodo*> lista);
    // Dado un nodo y dos listas, visista en profundidad el grafo
    // si el nodo ya fue visitado con anterioridad setea esCiclico en
    // true. 
    // Pre: El nodo se encuentra en la matriz de adyacencias.
    void detectarCiclos(Nodo *nodo, 
        std::list<Nodo*> *visitados, std::list<Nodo*> *stack);
    // Dado un nodo, genera la lista de adyacencias para el mismo
    // y la almacena en la matriz.
    // Pre: el nodo y la matriz fueron inicializados.
    void agregarListaAdy(Nodo *nodo);
    // Agrega el nodo a la lista de adyacencias que contenga la misma
    // etiqueta que el.
    // Pre: el nodo tiene etiqueta.
    void agregarNodoConEtiqueta(Nodo *nodo);
    // Dado un nodo, agrega todos los adyacentes al mismo 
    // dependiendo el tipo de nodo obtenido.
    // Pre: el nodo fue inicializado.
    void agregarAdyacentesNodo(Nodo *nodo, Nodo *nodo_ant);
    // Dado un string (etiqueta), busca en la matriz un nodo que 
    // contenga la misma etiqueta y lo devuelve.
    // Pre: la matriz fue inicializada.
    Nodo* buscarNodoConEtiqueta(const std::string &etiqueta);
    // Dado un nodo, inicializa los adyacentes correspondientes
    // segun las etiquetas del mismo.
    // Pre: La matriz fue inicializada.
    int obtenerEtiquetasNodo(Nodo *nodo_ant);
    Grafo &operator=(const Grafo& s);
    Grafo(const Grafo &s); 
    
public: 
    Grafo();
    // Dado un nodo, lo agrega a la matriz de adyacencias
    // Pre: La matriz fue inicializada.
    void agregarNodo(Nodo *nodo);
    // Busca en profundidad en el grafo y setea las variables
    // esCiclico e instruccionesSinUsar
    // Pre: el grafo fue inicializado.
    void DFS();
    // Itera el grafo para liberar toda la memoria.
    // Pre: Los nodos fueron inicializados pidiendo memoria 
    // al heap.
    void destruirGrafo();
    // Finaliza la construccion del grafo.
    // Pre: el grafo fue inicializado.
    void ultimoNodo();
    // Devuelve true en caso de que esCiclico sea True
    // False en caso contrario.
    bool tieneCliclos();
    // Devuelve true en caso de que instruccionesSinUsar 
    // sea True, False en caso contrario.
    bool tieneInstruccionesSinUsar();
    ~Grafo();
};

#endif
