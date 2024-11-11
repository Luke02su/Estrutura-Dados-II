#include <stdio.h>
#include <stdbool.h>

// Função de busca sequencial - Complexidade O(n)
bool buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return true; // Encontrou o valor
        }
    }
    return false; // Não encontrou o valor
}

// Função de busca binária - Complexidade O(log n), Complexidade de espaço O(1)
bool buscaBinaria(int v[], int n, int x) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (v[m] == x) {
            return true; // Encontrou o valor
        } else if (v[m] > x) {
            e = m - 1; // Buscar na metade esquerda
        } else {
            s = m + 1; // Buscar na metade direita
        }
    }
    return false; // Não encontrou o valor
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17}; // Vetor ordenado
    int n = sizeof(v) / sizeof(v[0]); // Tamanho do vetor
    int x;

    // Entrada do valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &x);

    // Busca sequencial
    if (buscaSequencial(v, n, x)) {
        printf("Valor %d encontrado na busca sequencial.\n", x);
    } else {
        printf("Valor %d não encontrado na busca sequencial.\n", x);
    }

    // Busca binária
    if (buscaBinaria(v, n, x)) {
        printf("Valor %d encontrado na busca binária.\n", x);
    } else {
        printf("Valor %d não encontrado na busca binária.\n", x);
    }

    return 0;
}
