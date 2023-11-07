// src/Ordenacao.cpp

#include "Ordenacao.hpp"

void Ordenacao::bubbleSort(int* permutacao, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (permutacao[j] > permutacao[j + 1]) {
                std::swap(permutacao[j], permutacao[j + 1]);
            }
        }
    }
}

void Ordenacao::selectionSort(int* permutacao, int n) {
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

void Ordenacao::insertionSort(int* permutacao, int n) {
    for (int i = 1; i < n; ++i) {
        int key = permutacao[i];
        int j = i - 1;

        while (j >= 0 && permutacao[j] > key) {
            permutacao[j + 1] = permutacao[j];
            --j;
        }

        permutacao[j + 1] = key;
    }
}

namespace {

void quicksortImpl(int* permutacao, int low, int high) {
    if (low < high) {
        int pivot = permutacao[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (permutacao[j] < pivot) {
                ++i;
                std::swap(permutacao[i], permutacao[j]);
            }
        }

        std::swap(permutacao[i + 1], permutacao[high]);
        int partitionIndex = i + 1;

        quicksortImpl(permutacao, low, partitionIndex - 1);
        quicksortImpl(permutacao, partitionIndex + 1, high);
    }
}

}

void Ordenacao::quicksort(int* permutacao, int n) {
    int low = 0;
    int high = n - 1;
    quicksortImpl(permutacao, low, high);
}

namespace {

void merge(int* permutacao, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i)
        L[i] = permutacao[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = permutacao[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            permutacao[k] = L[i];
            ++i;
        } else {
            permutacao[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        permutacao[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        permutacao[k] = R[j];
        ++j;
        ++k;
    }

    free(L);
    free(R);
}

void mergesortImpl(int* permutacao, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesortImpl(permutacao, l, m);
        mergesortImpl(permutacao, m + 1, r);

        merge(permutacao, l, m, r);
    }
}

}

void Ordenacao::mergesort(int* permutacao, int n) {
    int l = 0;
    int r = n - 1;
    mergesortImpl(permutacao, l, r);
}

namespace {

void heapify(int* permutacao, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && permutacao[left] > permutacao[largest])
        largest = left;

    if (right < n && permutacao[right] > permutacao[largest])
        largest = right;

    if (largest != i) {
        std::swap(permutacao[i], permutacao[largest]);

        heapify(permutacao, n, largest);
    }
}

}

void Ordenacao::heapsort(int* permutacao, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(permutacao, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(permutacao[0], permutacao[i]);

        heapify(permutacao, i, 0);
    }
}

void Ordenacao::spiralSort(int* permutacao, int n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int direction = 0;

    while (left <= right && top <= bottom) {
        if (direction == 0) { // Mover para a direita
            for (int i = left; i <= right; ++i) {
                if (i < right && permutacao[i] > permutacao[i + 1]) {
                    std::swap(permutacao[i], permutacao[i + 1]);
                }
            }
            top++;
            direction = 1;
        } else if (direction == 1) { // Mover para baixo
            for (int i = top; i <= bottom; ++i) {
                if (i < bottom && permutacao[i] > permutacao[i + 1]) {
                    std::swap(permutacao[i], permutacao[i + 1]);
                }
            }
            right--;
            direction = 2;
        } else if (direction == 2) { // Mover para a esquerda
            for (int i = right; i >= left; --i) {
                if (i > left && permutacao[i] < permutacao[i - 1]) {
                    std::swap(permutacao[i], permutacao[i - 1]);
                }
            }
            bottom--;
            direction = 3;
        } else if (direction == 3) { // Mover para cima
            for (int i = bottom; i >= top; --i) {
                if (i > top && permutacao[i] < permutacao[i - 1]) {
                    std::swap(permutacao[i], permutacao[i - 1]);
                }
            }
            left++;
            direction = 0;
        }
    }
}
