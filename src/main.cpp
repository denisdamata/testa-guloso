// src/main.cpp

#include "Grafo.hpp"
#include "Ordenacao.hpp"
#include "MeuMetodoOrdenacao.hpp"
#include <iostream>
#include <vector>

bool verificaColoracaoGulosa(const Grafo& grafo, const std::vector<int>& permutacao, const std::vector<int>& cores) {
    for (int i = 0; i < permutacao.size(); ++i) {
        int vertice = permutacao[i];
        int corAtual = cores[vertice];

        // Verifica se algum vizinho tem a mesma cor
        for (int vizinho : grafo.obterVizinhos(vertice)) {
            if (cores[vizinho] == corAtual) {
                return false; // Coloração não é gulosa
            }
        }
    }
    return true; // Coloração é gulosa
}

int main() {
    // Leitura dos dados
    char metodoOrdenacao;
    int numVertices;
    std::cin >> metodoOrdenacao >> numVertices;

    // Criar instância do Grafo
    Grafo grafo(numVertices);

    // Ler a vizinhança de cada vértice
    for (int i = 0; i < numVertices; ++i) {
        int numVizinhos;
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; ++j) {
            int vizinho;
            std::cin >> vizinho;
            grafo.adicionarAresta(i, vizinho);
        }
    }

    // Ler as cores dos vértices
    std::vector<int> cores(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        std::cin >> cores[i];
    }

    // Inicializar vetor de permutação
    std::vector<int> permutacao(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        permutacao[i] = i;
    }

    // Escolher e chamar o método de ordenação
    switch (metodoOrdenacao) {
        case 'b':
            bubbleSort(permutacao);
            break;
        case 's':
            selectionSort(permutacao);
            break;
        case 'y':
            meuMetodoOrdenacao(permutacao);
            break;
        // Adicione outros casos de ordenação, se necessário
        default:
            std::cerr << "Método de ordenação inválido" << std::endl;
            return 1;
    }

    // Verificar se a coloração é gulosa
    bool resultado = verificaColoracaoGulosa(grafo, permutacao, cores);

    // Imprimir o resultado
    if (resultado) {
        std::cout << "1";
        for (int i : permutacao) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}
