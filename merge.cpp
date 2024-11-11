#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas metades do vetor
void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];  // Vetor temporário para armazenar os elementos ordenados
    int i = s, j = m + 1, k = 0;
    
    // Mescla as duas metades enquanto houver elementos em ambas
    while (i <= m && j <= e) {
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }
    
    // Copia os elementos restantes da metade esquerda (se houver)
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    
    // Copia os elementos restantes da metade direita (se houver)
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    
    // Copia os elementos ordenados de volta para o vetor original
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

// Função para ordenar o vetor usando o Merge Sort
void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;  // Calcula o ponto médio
        mergeSort(v, s, m);    // Ordena a metade esquerda
        mergeSort(v, m + 1, e); // Ordena a metade direita
        merge(v, s, m, e);     // Mescla as duas metades
    }
}

// Função para imprimir o vetor
void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

// Função para imprimir o vetor em ordem reversa
void imprimirVetorC(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", v[i]);
    }
}

int main() {
    int n, x, cp = 0, ci = 0;
    scanf("%d", &n);  // Lê o número de elementos
    int pares[n], impares[n];  // Vetores para armazenar os números pares e ímpares

    // Lê os números e os divide entre pares e ímpares
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares[cp++] = x;  // Adiciona aos pares se o número for par
        } else {
            impares[ci++] = x;  // Adiciona aos ímpares se o número for ímpar
        }
    }

    // Ordena os vetores de pares e ímpares
    mergeSort(pares, 0, cp - 1);
    mergeSort(impares, 0, ci - 1);

    // Imprime os números pares em ordem crescente
    imprimirVetor(pares, cp);
    // Imprime os números ímpares em ordem decrescente
    imprimirVetorC(impares, ci);

    return 0;
}
