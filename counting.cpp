#include<stdio.h>

// Função para imprimir os elementos de um vetor
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Nova linha após imprimir todos os elementos
}

// Função para realizar o algoritmo Counting Sort
// O tempo é O(max(n, m)), onde 'n' é o número de elementos do vetor e 'm' é o maior valor presente no vetor.
// O espaço é O(m), pois estamos utilizando um vetor auxiliar com tamanho m+1.
void countingSort(int v[], int n, int m) {
    int tmp[m + 1];  // Vetor auxiliar para contar as ocorrências de cada valor (tamanho m + 1)

    // Inicializa o vetor auxiliar 'tmp' com zeros
    for (int i = 0; i < m + 1; i++) tmp[i] = 0;

    // Contabiliza as ocorrências de cada número no vetor 'v'
    for (int i = 0; i < n; i++) {
        tmp[v[i]]++;  // Incrementa a contagem do valor v[i] no vetor auxiliar
    }

    // Reconstrói o vetor 'v' com os valores ordenados
    for (int i = 0, j = 0; i < m + 1; i++) {
        // Enquanto houver ocorrências de tmp[i], coloca o valor i no vetor 'v'
        while(tmp[i] > 0) {
            v[j++] = i;  // Atribui o valor i em 'v[j]' e incrementa j
            tmp[i]--;  // Decrementa o contador de tmp[i] (uma ocorrência a menos)
        }
    }
}

int main() {
    // Vetor de entrada com números desordenados
    int v[] = { 1, 3, 5, 2, 4, 7, 8, 4, 1 };

    // Aplica o algoritmo Counting Sort no vetor 'v', considerando o tamanho do vetor 9 e o maior valor 8
    countingSort(v, 9, 8);

    // Imprime o vetor ordenado
    imprimir(v, 9);

    return 0;
}
