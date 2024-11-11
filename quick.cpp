#include<stdio.h>

// Função para preencher o vetor com valores fornecidos pelo usuário
void geraVetor(int v[], int n) {
    printf("Digite %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);  // Lê o valor do elemento do vetor
    }
}

// Função para imprimir os elementos de um vetor
void imprimir(int v[], int n) {
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);  // Imprime o valor do elemento v[i]
    }
    printf("\n");  // Nova linha após imprimir todos os elementos
}

// Função para trocar dois elementos do vetor
void swap(int v[], int a, int b) {
    if (a == b) return;  // Se os índices forem iguais, não há nada a fazer
    int tmp = v[a];  // Armazena o valor de v[a] temporariamente
    v[a] = v[b];     // Atribui o valor de v[b] para v[a]
    v[b] = tmp;      // Atribui o valor de v[a] (armazenado em tmp) para v[b]
}

// Função para realizar a partição do vetor no QuickSort
int partition(int v[], int s, int e) {
    int pivot = v[e];  // O pivot é o último elemento do vetor
    int i = s - 1;     // Índice do menor elemento
    for (int j = s; j < e; j++) {  // Laço para iterar pelos elementos
        if (v[j] < pivot) {  // Se o elemento atual for menor que o pivot
            swap(v, ++i, j);  // Troca o elemento v[j] com v[i]
        }
    }
    swap(v, i + 1, e);  // Coloca o pivot na posição correta
    return i + 1;  // Retorna o índice do pivot
}

// Função QuickSort
void quickSort(int v[], int s, int e) {
    if (s < e) {
        int p = partition(v, s, e);  // Chama a partição e obtém o índice do pivot
        quickSort(v, s, p - 1);  // Recursivamente ordena a parte esquerda do vetor
        quickSort(v, p + 1, e);  // Recursivamente ordena a parte direita do vetor
    }
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);  // Lê o tamanho do vetor
    
    int v[n];  // Declara o vetor de inteiros
    
    geraVetor(v, n);  // Preenche o vetor com valores fornecidos pelo usuário
    quickSort(v, 0, n - 1);  // Ordena o vetor usando o QuickSort
    
    imprimir(v, n);  // Imprime o vetor ordenado

    return 0;
}
