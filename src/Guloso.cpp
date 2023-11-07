// src/Guloso.cpp

#include "Grafo.hpp"
#include "Guloso.hpp"
#include <cstdlib>  // Para usar a função malloc

bool Guloso::testeGulosidade(const Grafo& grafo, const int* arranjoCores, const int* cores) {
    for (int i = 0; i < grafo.obterNumVertices(); ++i) {
        int vertice = arranjoCores[i];
        int corAtual = cores[vertice];

        // Verifica se algum vizinho tem a mesma cor
        for (int j = 0; j < grafo.obterNumVizinhos(vertice); ++j) {
            int vizinho = grafo.obterVizinho(vertice, j);
            if (cores[vizinho] == corAtual) {
                return false; // Coloração não é gulosa
            }
        }

        // Verifica se existe pelo menos um vizinho para cada cor menor
        for (int corMenor = 0; corMenor < corAtual; ++corMenor) {
            bool temVizinhoCorMenor = false;
            for (int j = 0; j < grafo.obterNumVizinhos(vertice); ++j) {
                int vizinho = grafo.obterVizinho(vertice, j);
                if (cores[vizinho] == corMenor) {
                    temVizinhoCorMenor = true;
                    break;
                }
            }

            if (!temVizinhoCorMenor) {
                return false; // Coloração não é gulosa
            }
        }
    }

    return true; // Coloração é gulosa
}
