#include<stdio.h>

void troca (int v[], int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

// Complexidade de espaço (memória): O(1) constante. Pode ser correto, mas não viável. De espaço baixo.
// Complexidade de tempo: estrutura de repetição afeta bastante (for, while, do..while e função recursiva): O(n^2. De tempo alto.
// Até quando é viável usar bubblesort?


void bubbleSort(int v[], int n) { // passando por referêcia v[]
    for (int i = 0; i < n - 1; i++) { // vezes (n-1)
        for (int j = 0; j < n; j++) { // vezes (n-1) * (n-1) -> n^2
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {

    int v[] = {4, 1, 3, 2};
    bubbleSort(v, 4);
    imprimirVetor(v, 4);

    return 0;
}

// Complexidade de espaço e tempo.
