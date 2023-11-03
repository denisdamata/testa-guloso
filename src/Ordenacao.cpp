// src/Ordenacao.cpp

#include "Ordenacao.hpp"

void bubbleSort(std::vector<int>& permutacao) {
    int n = permutacao.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (permutacao[j] > permutacao[j + 1]) {
                std::swap(permutacao[j], permutacao[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& permutacao) {
    int n = permutacao.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (permutacao[j] < permutacao[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(permutacao[i], permutacao[minIndex]);
    }
}

// Implemente outras funções de ordenação, se necessário
