#include "Grafo.h"

Grafo::Grafo(){
    adyacentes = new std::list<std::list<Nodo*>>; 
    this->esCiclico = false;
    this->instruccionSinUsar = false;
}

void Grafo::agregarNodoConEtiqueta(Nodo *nodo){
    std::list<std::list<Nodo*>>::iterator it;

    for (it = this->adyacentes->begin(); 
        it!= this->adyacentes->end(); ++it){
        Nodo *nodo_aux = (*it).front();
        std::string etiqueta_nodo = nodo->obtenerEtiqueta();
        std::string instruccion_nodo_aux = nodo_aux->obtenerInstruccion();
        if ((instruccion_nodo_aux.find(etiqueta_nodo)) != std::string::npos){
            (*it).push_back(nodo);
        }
    }   
}

Nodo* Grafo::buscarNodoConEtiqueta(std::string etiqueta){
    std::list<std::list<Nodo*>>::iterator it;

    for (it = this->adyacentes->begin(); 
        it!= this->adyacentes->end(); ++it){
        Nodo *nodo_aux = (*it).front();
        if ((nodo_aux->tieneEtiqueta()) && 
        (nodo_aux->obtenerEtiqueta().find(etiqueta) != std::string::npos)){
            return nodo_aux;
        }
    } 
    return NULL;
}

void Grafo::agregarListaAdy(Nodo *nodo){
    std::list<Nodo*> lista_nueva;
    lista_nueva.push_back(nodo);
    this->adyacentes->push_back(lista_nueva);
}

int Grafo::obtenerEtiquetasNodo(Nodo *nodo_ant){
    std::list<std::string> etiquetas_jmp = nodo_ant->obtenerEtiquetaJmp();
    std::list<std::string>::iterator it;

    for (it = etiquetas_jmp.begin(); it!= etiquetas_jmp.end(); ++it){
        Nodo* nodo_etiqueta = buscarNodoConEtiqueta((*it));
        if (nodo_etiqueta != NULL){
            this->adyacentes->back().push_back(nodo_etiqueta);
        }
    }
    return etiquetas_jmp.size();
}

void Grafo::agregarAdyacentesNodo(Nodo *nodo, Nodo *nodo_ant){
    if (nodo_ant->esInstruccion()){
        if (!(nodo_ant->esRet())){
            this->adyacentes->back().push_back(nodo);
        }
    }else{
        int cant_etiquetas = obtenerEtiquetasNodo(nodo_ant);
        if ((!nodo_ant->esJmpIncondicional()) && (cant_etiquetas == 1)){ 
            this->adyacentes->back().push_back(nodo);
        }
    }
}

void Grafo::ultimoNodo(){
    Nodo *nodo_ant = this->adyacentes->back().front();
    if (nodo_ant->esJmpIncondicional()){
        obtenerEtiquetasNodo(nodo_ant);
    }
}

void Grafo::agregarNodo(Nodo *nodo){
    if ((nodo->esNodoVacio())){
        delete nodo;
        return;
    }
    if (this->adyacentes->empty()){
        agregarListaAdy(nodo);
        return;
    }
    Nodo *nodo_ant = this->adyacentes->back().front();
    //busco adyacentes para nodo anterior.
    agregarAdyacentesNodo(nodo, nodo_ant);
    //busco adyacentes si tiene etiqueta nodo actual.
    if (nodo->tieneEtiqueta()){
        agregarNodoConEtiqueta(nodo);
    }
    agregarListaAdy(nodo);
}

std::list<Nodo*> Grafo::obtenerNodosAdyacentes(Nodo* nodo){
    std::list<Nodo*> ady;
    std::list<std::list<Nodo*>>::iterator it;

    for (it = this->adyacentes->begin(); 
        it!= this->adyacentes->end(); ++it){
        if (memcmp(nodo, (*it).front(), sizeof(*nodo)) == 0){
            std::list<Nodo*>::iterator it2;
            int contador = 0;

            for (it2 = (*it).begin(); it2!= (*it).end(); ++it2){
                if (contador == 0){
                    contador++;
                    continue;
                }
                Nodo *nodo_ady = (*it2);
                ady.push_back(nodo_ady);
                contador++;
            }
            return ady;
        }
    }
    return ady;
}

bool Grafo::nodoEstaEnLista(Nodo *nodo, 
    std::list<Nodo*> lista){
    bool estaEnLista = (std::find(lista.begin(),
        lista.end(), nodo) != lista.end());
    return estaEnLista;
}

void Grafo::detectarCiclos(Nodo *nodo, 
    std::list<Nodo*> *visitados, std::list<Nodo*> *stack){
    visitados->push_back(nodo);
    stack->push_back(nodo);

    std::list<Nodo*>adyacentes_nodo=
    obtenerNodosAdyacentes(nodo);
    std::list<Nodo*>::iterator it;

    for (it = adyacentes_nodo.begin(); 
        it!=adyacentes_nodo.end(); ++it){
        Nodo *nodo_act = (*it);
        if ((nodoEstaEnLista(nodo_act, *stack))){
            this->esCiclico = true;
            return;
        }else if (!nodoEstaEnLista(nodo_act,  *visitados)){
            detectarCiclos(nodo_act, visitados, stack);
        }
    }
    stack->pop_back();
    return;
}

void Grafo::DFS(){
    std::list<Nodo*> visitados;
    std::list<Nodo*> stack;

    Nodo *nodo_inicial = this->adyacentes->front().front();

    detectarCiclos(nodo_inicial, &visitados, &stack);

    if (visitados.size() < this->adyacentes->size()){
        this->instruccionSinUsar = true;
    }
}

bool Grafo::tieneCliclos(){
    return this->esCiclico;
}

bool Grafo::tieneInstruccionesSinUsar(){
    return this->instruccionSinUsar;
}

void Grafo::destruirGrafo(){
    std::list<std::list<Nodo*>>::iterator it;
    for (it = this->adyacentes->begin(); 
        it!= this->adyacentes->end(); ++it){
        std::list<Nodo*>::iterator it2;
        int contador = 0;
        for (it2 = (*it).begin(); it2!= (*it).end(); ++it2){
            if (contador == 0){
                Nodo *nodo = (*it2);
                delete nodo;
                break;
            }
        contador++;
        }
    }
}

Grafo::~Grafo(){
    destruirGrafo();
    delete this->adyacentes;
}
