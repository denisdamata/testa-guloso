// src/main.cpp

// Arquivo principal. 
// É o arquivo que está no topo do programa, então se for ler o programa de cima para baixo, o leitor deve começar por aqui. Começar a leitura por aqui é bom para ter uma ideia geral e modularizada do programa, mas não é bom para  ter uma visão detalhada. 

#include "Grafo.hpp"
#include "Ordenacao.hpp"
#include "Guloso.hpp"
#include <iostream>
#include <cstdlib>  // Para usar a função malloc

int main(int argc, char* argv[]) {
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
    int* cores = static_cast<int*>(malloc(numVertices * sizeof(int)));
    for (int i = 0; i < numVertices; ++i) {
        std::cin >> cores[i];
    }

    // Inicializar vetor de permutação
    int* permutacao = static_cast<int*>(malloc(numVertices * sizeof(int)));
    for (int i = 0; i < numVertices; ++i) {
        permutacao[i] = i;
    }

    // Escolher e chamar o método de ordenação
    switch (metodoOrdenacao) {
    case 'b':
        Ordenacao::bubbleSort(permutacao, numVertices);
        break;
    case 's':
        Ordenacao::selectionSort(permutacao, numVertices);
        break;
    case 'i':
        Ordenacao::insertionSort(permutacao, numVertices);
        break;
    case 'q':
        Ordenacao::quicksort(permutacao, numVertices);
        break;
    case 'm':
        Ordenacao::mergesort(permutacao, numVertices);
        break;
    case 'p':
        Ordenacao::heapsort(permutacao, numVertices);
        break;
    // Adicione outros casos de ordenação, se necessário
    default:
        std::cerr << "Método de ordenação inválido" << std::endl;
        free(cores);
        free(permutacao);
        return 1;
    }

    // Verificar se a coloração é gulosa
    bool resultado = Guloso::testeGulosidade(grafo, permutacao, cores);  // Chamada da função testeGulosidade

    // Imprimir o resultado
    if (resultado) {
        std::cout << "1";
        for (int i = 0; i < numVertices; ++i) {
            std::cout << " " << permutacao[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    // Liberar memória alocada dinamicamente
    free(cores);
    free(permutacao);

    return 0;
}
