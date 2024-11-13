#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void geraVetor(char v[][100], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", v[i]);
    }
}

void swap(char v[][100], int a, int b) {
    if (a == b) return;
    char temp[100];
    strcpy(temp, v[a]);
    strcpy(v[a], v[b]);
    strcpy(v[b], temp);
}

int partition(char v[][100], int s, int e) {
    char pivot[100];
    strcpy(pivot, v[e]);  
    int i = s - 1; 
    for (int j = s; j < e; j++) { 
        if (strcmp(v[j], pivot) < 0) {  
            swap(v, ++i, j);  
        }
    }
    swap(v, i + 1, e);
    return i + 1;  
}

void quickSort(char v[][100], int s, int e) {
    if (s < e) {
        int p = partition(v, s, e);
        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);  
    }
}

int buscaBinaria(char arr[][100], int l, int r, char* x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = strcmp(arr[m], x);

        if (res == 0)
            return m;
        if (res < 0)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, m;
    char dicionario[500][100], checagem[50][100];

    scanf("%d", &n);
    geraVetor(dicionario, n);

    quickSort(dicionario, 0, n - 1);

    scanf("%d", &m);
    geraVetor(checagem, m);

    quickSort(checagem, 0, m - 1);

    int cont = 0;
    for (int i = 0; i < m; i++) {
        if (buscaBinaria(dicionario, 0, n - 1, checagem[i]) != -1) {
            cont++;
        }
    }

    printf("%d\n", cont);

    return 0;
}
