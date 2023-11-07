// src/Grafo.cpp

#include "Grafo.hpp"

Grafo::Grafo(int numVertices) : numVertices(numVertices) { 
    listaAdjacencia = new int[numVertices * numVertices]; // Usando um array unidimensional para armazenar as arestas.
    for (int i = 0; i < numVertices * numVertices; ++i) {
        listaAdjacencia[i] = -1; // Inicializando com -1 para indicar ausência de aresta.
    }
}

void Grafo::adicionarAresta(int u, int v) {
    // Encontrar o primeiro elemento não utilizado na linha de u
    int i = u * numVertices;
    while (listaAdjacencia[i] != -1) {
        ++i;
    }
    listaAdjacencia[i] = v;

    // Encontrar o primeiro elemento não utilizado na linha de v
    int j = v * numVertices;
    while (listaAdjacencia[j] != -1) {
        ++j;
    }
    listaAdjacencia[j] = u;
}

const int* Grafo::obterVizinhos(int vertice) const {
    return &listaAdjacencia[vertice * numVertices];
}
