// src/Guloso.cpp

#include "Guloso.hpp"

bool Guloso::testeGulosidade(const Grafo& grafo, const std::vector<int>& permutacao, const std::vector<int>& cores) {
    for (int vertice : permutacao) {
        int corAtual = cores[vertice];

        // Verifica se algum vizinho tem a mesma cor
        for (int vizinho : grafo.obterVizinhos(vertice)) {
            if (cores[vizinho] == corAtual) {
                return false; // Coloração não é gulosa
            }
        }

        // Verifica se existe pelo menos um vizinho para cada cor menor
        for (int corMenor = 0; corMenor < corAtual; ++corMenor) {
            bool temVizinhoCorMenor = false;
            for (int vizinho : grafo.obterVizinhos(vertice)) {
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
