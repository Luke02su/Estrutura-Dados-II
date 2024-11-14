#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void troca(char v[], int a, int b) {
    char aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

// Complexidade de espaço: O(1) 
// Complexidade de tempo: O(n^2)
void bubbleSort(char v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
            }
        }
    }
}

bool anagrama(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return false;
    }

    bubbleSort(s1, len1);
    bubbleSort(s2, len2);

    for (int i = 0; i < len1; i++) { //pode ser len1 ou len2, pois ambos já estão ordenados de maneira igual, caso tenham a mesa quantidade de letas e as mesmas letras, mas em ordem diferente
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s1[1000], s2[1000];

    scanf("%s", s1);

    scanf("%s", s2);

    if (!anagrama(s1, s2)) {
        printf("nao\n");
    } else {
        printf("sim\n");
    }

    return 0;
}
