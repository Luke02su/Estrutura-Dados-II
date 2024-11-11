#include<stdio.h>  // Inclui a biblioteca para entrada e saída (printf)
#include<stdbool.h>  // Inclui a biblioteca para usar o tipo de dado bool (verdadeiro/falso)

// Função para trocar dois elementos no vetor
void troca(int v[], int a, int b) {
    int aux = v[a];  // Cria uma variável auxiliar para armazenar temporariamente o valor de v[a]
    v[a] = v[b];     // Substitui o valor de v[a] pelo valor de v[b]
    v[b] = aux;      // Atribui o valor original de v[a] (armazenado em aux) a v[b]
}

// ==============================
// Algoritmo Bubble Sort Otimizado
// ==============================
// Complexidade de espaço: O(1)
// Complexidade de tempo: O(n^2) (melhora o tempo para vetores parcialmente ordenados)
void bubbleSortOtimizado(int v[], int n) {
    // Laço para percorrer o vetor n-1 vezes (do primeiro ao penúltimo elemento)
    for (int i = 0; i < n - 1; i++) {
        bool houveTroca = false;  // Variável que controla se houve troca durante a iteração
        // Laço interno para comparar elementos adjacentes
        for (int j = 0; j < (n - 1) - i; j++) {
            // Se o elemento atual for maior que o próximo, troca os elementos
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);  // Chama a função troca para trocar os elementos v[j] e v[j + 1]
                houveTroca = true;    // Marca que houve troca durante esta iteração
            }
        }
        // Se não houve nenhuma troca, significa que o vetor já está ordenado
        if (!houveTroca) return;  // Se o vetor já está ordenado, encerra a execução da função
    }
}

// Função para imprimir o vetor
void imprimirVetor(int v[], int n) {
    // Laço para percorrer e imprimir cada elemento do vetor
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Após imprimir todos os elementos, pula para a linha seguinte
}

int main() {
    // Definindo vetores diretamente
    int v1[] = { 5, 3, 8, 1, 2, 7 };  // Vetor v1 com 6 elementos
    int v2[] = { 12, 11, 15, 10, 5, 6, 7 };  // Vetor v2 com 7 elementos

    // Definindo o tamanho dos vetores manualmente
    int n1 = 6;  // Número de elementos no vetor v1
    int n2 = 7;  // Número de elementos no vetor v2

    // Imprimindo o vetor original (v1)
    printf("\nVetor original (v1):\n");
    imprimirVetor(v1, n1);  // Chama a função para imprimir o vetor v1

    // Ordenando o vetor v1 com o Bubble Sort Otimizado
    bubbleSortOtimizado(v1, n1);  // Chama a função bubbleSortOtimizado para ordenar o vetor v1
    
    // Imprimindo o vetor ordenado (Bubble Sort Otimizado - v1)
    printf("\nVetor ordenado (Bubble Sort Otimizado - v1):\n");
    imprimirVetor(v1, n1);  // Chama a função para imprimir o vetor v1 já ordenado

    return 0;  // Retorna 0, indicando que o programa foi executado com sucesso
}
