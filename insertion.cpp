#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos no vetor
void troca(int v[], int a, int b) {
    int aux = v[a];  // Armazena temporariamente o valor de v[a]
    v[a] = v[b];     // Substitui o valor de v[a] com o valor de v[b]
    v[b] = aux;      // Atribui o valor de v[a] (armazenado em aux) a v[b]
}

// ==============================
// Algoritmo Insertion Sort
// ==============================
// Complexidade de espaço: O(1) (não há uso de memória adicional significativa)
// Complexidade de tempo: O(n^2) (tempo quadrático devido ao laço aninhado)
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i], j = i - 1;
        while(j >= 0 && aux < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

// Função para imprimir o vetor
void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Nova linha após imprimir todos os elementos
}

int main() {
    int n = 10;  // Número de elementos no vetor
    int v[] = {34, 7, 23, 32, 5, 62, 32, 32, 12, 56}; // Vetor fixo com 10 elementos

    // Imprimindo o vetor original
    printf("Vetor original:\n");
    imprimirVetor(v, n);

    // Ordenando o vetor usando Insertion Sort
    insertionSort(v, n);

    // Imprimindo o vetor ordenado
    printf("Vetor ordenado (Insertion Sort):\n");
    imprimirVetor(v, n);

    return 0;
}
