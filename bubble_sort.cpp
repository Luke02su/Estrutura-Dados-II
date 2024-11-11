#include<stdio.h>  // Inclui a biblioteca para entrada e saída (printf)
#include<stdlib.h> // Inclui a biblioteca para funções de alocação de memória e geração de números aleatórios
#include<time.h>   // Inclui a biblioteca para manipulação de tempo (não usada diretamente no código)

// Função para trocar dois elementos no vetor
void troca(int v[], int a, int b) {
    int aux = v[a];  // Cria uma variável auxiliar para armazenar temporariamente o valor de v[a]
    v[a] = v[b];     // Substitui o valor de v[a] pelo valor de v[b]
    v[b] = aux;      // Atribui o valor original de v[a] (armazenado em aux) a v[b]
}

// ==============================
// Algoritmo Bubble Sort
// ==============================
// Complexidade de espaço: O(1) (não há uso de memória adicional significativa)
// Complexidade de tempo: O(n^2) (tempo quadrático devido aos dois laços aninhados)
void bubbleSort(int v[], int n) {
    // Laço externo que percorre o vetor n-1 vezes
    for (int i = 0; i < n - 1; i++) {
        // Laço interno para comparar cada par de elementos adjacentes
        for (int j = 0; j < n - 1; j++) {
            // Se o elemento atual for maior que o próximo, realiza a troca
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);  // Chama a função troca para substituir v[j] e v[j + 1]
            }
        }
    }
}

// Função para imprimir os elementos de um vetor
void imprimirVetor(int v[], int n) {
    // Laço para percorrer e imprimir cada elemento do vetor
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Após imprimir todos os elementos, pula para a linha seguinte
}

int main() {
    // Definição manual de um vetor fixo
    int n = 10;  // Número de elementos no vetor
    int v[] = {34, 7, 23, 32, 5, 62, 32, 32, 12, 56}; // Vetor fixo com 10 elementos

    // Imprime o vetor original
    printf("Vetor original:\n");
    imprimirVetor(v, n);  // Chama a função imprimirVetor para exibir o vetor antes da ordenação

    // Ordena o vetor usando o algoritmo Bubble Sort
    bubbleSort(v, n);  // Chama a função bubbleSort para ordenar o vetor v

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    imprimirVetor(v, n);  // Chama a função imprimirVetor para exibir o vetor após a ordenação

    return 0;  // Retorna 0, indicando que o programa foi executado com sucesso
}
