// include/Grafo.hpp

#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>

class Grafo {
public:
    Grafo(int numVertices);
    void adicionarAresta(int u, int v);
    const std::vector<int>& obterVizinhos(int vertice) const;

private:
    int numVertices;
    std::vector<std::vector<int>> listaAdjacencia;
};

#endif // GRAFO_HPP
