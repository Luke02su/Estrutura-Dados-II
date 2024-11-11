#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Função para trocar dois elementos no vetor
void troca(int v[], int a, int b) {
    int aux = v[a];  // Armazena temporariamente o valor de v[a]
    v[a] = v[b];     // Substitui o valor de v[a] com o valor de v[b]
    v[b] = aux;      // Atribui o valor de v[a] (armazenado em aux) a v[b]
}

// ==============================
// Algoritmo Selection Sort
// ==============================
// Complexidade de espaço: O(1) (não há uso de memória adicional significativa)
// Complexidade de tempo: O(n^2) (tempo quadrático devido aos dois laços aninhados)
void selectionSort(int v[], int n) {
    // Laço externo percorre o vetor inteiro
    for (int i = 0; i < n - 1; i++) {
        // Laço interno encontra o menor elemento à direita de v[i]
        for (int j = i + 1; j < n; j++) {
            // Se o elemento v[j] for menor que v[i], faz a troca
            if (v[i] > v[j]) {
                troca(v, i, j);  // Troca os elementos v[i] e v[j]
            }
        }
    }
}

// Função para imprimir o vetor
void imprimirVetor(int v[], int n) {
    // Laço para imprimir cada elemento do vetor
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Nova linha após imprimir todos os elementos
}

int main() {
    // Definindo um vetor manualmente
    int n = 10;  // Número de elementos no vetor
    int v[] = {34, 7, 23, 32, 5, 62, 32, 32, 12, 56}; // Vetor fixo com 10 elementos

    // Imprimindo o vetor original
    printf("Vetor original:\n");
    imprimirVetor(v, n);  // Chama a função para exibir o vetor antes da ordenação

    // Ordenando o vetor usando Selection Sort
    selectionSort(v, n);  // Chama a função selectionSort para ordenar o vetor v

    // Imprimindo o vetor ordenado
    printf("Vetor ordenado (Selection Sort):\n");
    imprimirVetor(v, n);  // Chama a função para exibir o vetor após a ordenação

    return 0;  // Retorna 0, indicando que o programa foi executado com sucesso
}
