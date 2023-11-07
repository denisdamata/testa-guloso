// include/Ordenacao.hpp

#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

class Ordenacao {
public:
    static void bubbleSort(int* arranjoCores, int tamanho);
    static void selectionSort(int* arranjoCores, int tamanho);
    static void insertionSort(int* arranjoCores, int tamanho);
    static void quicksort(int* arranjoCores, int tamanho);
    static void mergesort(int* arranjoCores, int tamanho);
    static void heapsort(int* arranjoCores, int tamanho);
    static void spiralSort(int* arranjoCores, int tamanho);
};

#endif

