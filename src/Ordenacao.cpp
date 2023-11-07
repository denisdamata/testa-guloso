// src/Ordenacao.cpp

#include "Ordenacao.hpp"
#include <cstdlib>  // Para usar a função malloc

void Ordenacao::bubbleSort(int* arranjoCores, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arranjoCores[j] > arranjoCores[j + 1]) {
                std::swap(arranjoCores[j], arranjoCores[j + 1]);
            }
        }
    }
}

void Ordenacao::selectionSort(int* arranjoCores, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arranjoCores[j] < arranjoCores[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arranjoCores[i], arranjoCores[minIndex]);
    }
}

void Ordenacao::insertionSort(int* arranjoCores, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arranjoCores[i];
        int j = i - 1;

        while (j >= 0 && arranjoCores[j] > key) {
            arranjoCores[j + 1] = arranjoCores[j];
            --j;
        }

        arranjoCores[j + 1] = key;
    }
}

namespace {

void quicksortImpl(int* arranjoCores, int low, int high) {
    if (low < high) {
        int pivot = arranjoCores[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arranjoCores[j] < pivot) {
                ++i;
                std::swap(arranjoCores[i], arranjoCores[j]);
            }
        }

        std::swap(arranjoCores[i + 1], arranjoCores[high]);
        int partitionIndex = i + 1;

        quicksortImpl(arranjoCores, low, partitionIndex - 1);
        quicksortImpl(arranjoCores, partitionIndex + 1, high);
    }
}

}

void Ordenacao::quicksort(int* arranjoCores, int n) {
    int low = 0;
    int high = n - 1;
    quicksortImpl(arranjoCores, low, high);
}

namespace {

void merge(int* arranjoCores, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = static_cast<int*>(malloc(n1 * sizeof(int)));
    int* R = static_cast<int*>(malloc(n2 * sizeof(int)));

    for (int i = 0; i < n1; ++i)
        L[i] = arranjoCores[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arranjoCores[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arranjoCores[k] = L[i];
            ++i;
        } else {
            arranjoCores[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arranjoCores[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arranjoCores[k] = R[j];
        ++j;
        ++k;
    }

    free(L);
    free(R);
}

void mergesortImpl(int* arranjoCores, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesortImpl(arranjoCores, l, m);
        mergesortImpl(arranjoCores, m + 1, r);

        merge(arranjoCores, l, m, r);
    }
}

}

void Ordenacao::mergesort(int* arranjoCores, int n) {
    int l = 0;
    int r = n - 1;
    mergesortImpl(arranjoCores, l, r);
}

namespace {

void heapify(int* arranjoCores, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arranjoCores[left] > arranjoCores[largest])
        largest = left;

    if (right < n && arranjoCores[right] > arranjoCores[largest])
        largest = right;

    if (largest != i) {
        std::swap(arranjoCores[i], arranjoCores[largest]);

        heapify(arranjoCores, n, largest);
    }
}

}

void Ordenacao::heapsort(int* arranjoCores, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arranjoCores, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arranjoCores[0], arranjoCores[i]);

        heapify(arranjoCores, i, 0);
    }
}

void Ordenacao::spiralSort(int* arranjoCores, int n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int direction = 0;

    while (left <= right && top <= bottom) {
        if (direction == 0) { // Mover para a direita
            for (int i = left; i <= right; ++i) {
                if (i < right && arranjoCores[i] > arranjoCores[i + 1]) {
                    std::swap(arranjoCores[i], arranjoCores[i + 1]);
                }
            }
            top++;
            direction = 1;
        } else if (direction == 1) { // Mover para baixo
            for (int i = top; i <= bottom; ++i) {
                if (i < bottom && arranjoCores[i] > arranjoCores[i + 1]) {
                    std::swap(arranjoCores[i], arranjoCores[i + 1]);
                }
            }
            right--;
            direction = 2;
        } else if (direction == 2) { // Mover para a esquerda
            for (int i = right; i >= left; --i) {
                if (i > left && arranjoCores[i] < arranjoCores[i - 1]) {
                    std::swap(arranjoCores[i], arranjoCores[i - 1]);
                }
            }
            bottom--;
            direction = 3;
        } else if (direction == 3) { // Mover para cima
            for (int i = bottom; i >= top; --i) {
                if (i > top && arranjoCores[i] < arranjoCores[i - 1]) {
                    std::swap(arranjoCores[i], arranjoCores[i - 1]);
                }
            }
            left++;
            direction = 0;
        }
    }
}
