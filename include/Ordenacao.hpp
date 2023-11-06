// include/Ordenacao.hpp

#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include <vector>

class Ordenacao {
public:
    static void bubbleSort(std::vector<int>& permutacao);
    static void selectionSort(std::vector<int>& permutacao);
    static void insertionSort(std::vector<int>& permutacao);
    static void quicksort(std::vector<int>& permutacao);
    static void mergesort(std::vector<int>& permutacao);
    static void heapsort(std::vector<int>& permutacao);
    static void spiralSort(std::vector<int>& permutacao);
};

#endif

