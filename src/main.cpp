// src/main.cpp

#include "Grafo.hpp"
#include "Ordenacao.hpp"
#include "Guloso.hpp"  // Adicione esta linha
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
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
            Ordenacao::bubbleSort(permutacao);
            break;
        case 's':
            Ordenacao::selectionSort(permutacao);
            break;
        case 'i':
            Ordenacao::insertionSort(permutacao);
            break;
        case 'q':
            Ordenacao::quicksort(permutacao);
            break;
        case 'm':
            Ordenacao::mergesort(permutacao);
            break;
        case 'p':
            Ordenacao::heapsort(permutacao);
            break;
        // Adicione outros casos de ordenação, se necessário
        default:
            std::cerr << "Método de ordenação inválido" << std::endl;
            return 1;
    }

    // Verificar se a coloração é gulosa
    bool resultado = Guloso::testeGulosidade(grafo, permutacao, cores);  // Chamada da função testeGulosidade

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
