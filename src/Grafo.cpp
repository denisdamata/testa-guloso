// src/Grafo.cpp

#include "Grafo.hpp"

Grafo::Grafo(int numVertices) : numVertices(numVertices), listaAdjacencia(numVertices) {}

void Grafo::adicionarAresta(int u, int v) {
    listaAdjacencia[u].push_back(v);
    listaAdjacencia[v].push_back(u);
}

const std::vector<int>& Grafo::obterVizinhos(int vertice) const {
    return listaAdjacencia[vertice];
}
