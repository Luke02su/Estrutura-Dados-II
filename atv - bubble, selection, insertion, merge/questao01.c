#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_NOMES 1000

void exibirMenu() {
    printf("Escolha um algoritmo de ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Sair\n");
    printf("Digite a sua opcao: ");
}

void bubbleSort(char nomes[][MAX_NOME], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char temp[MAX_NOME];
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp);
            }
        }
    }
}

void selectionSort(char nomes[][MAX_NOME], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nomes[j], nomes[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char temp[MAX_NOME];
            strcpy(temp, nomes[i]);
            strcpy(nomes[i], nomes[minIndex]);
            strcpy(nomes[minIndex], temp);
        }
    }
}

void insertionSort(char nomes[][MAX_NOME], int n) {
    for (int i = 1; i < n; i++) {
        char key[MAX_NOME];
        strcpy(key, nomes[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(nomes[j], key) > 0) {
            strcpy(nomes[j + 1], nomes[j]);
            j--;
        }
        strcpy(nomes[j + 1], key);
    }
}

void merge(char nomes[][MAX_NOME], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char leftArray[n1][MAX_NOME], rightArray[n2][MAX_NOME];

    for (int i = 0; i < n1; i++)
        strcpy(leftArray[i], nomes[left + i]);
    for (int i = 0; i < n2; i++)
        strcpy(rightArray[i], nomes[mid + 1 + i]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(leftArray[i], rightArray[j]) <= 0) {
            strcpy(nomes[k], leftArray[i]);
            i++;
        } else {
            strcpy(nomes[k], rightArray[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(nomes[k], leftArray[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(nomes[k], rightArray[j]);
        j++;
        k++;
    }
}

void mergeSort(char nomes[][MAX_NOME], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nomes, left, mid);
        mergeSort(nomes, mid + 1, right);
        merge(nomes, left, mid, right);
    }
}

int lerArquivo(char nomes[][MAX_NOME], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (!feof(arquivo) && count < MAX_NOMES) {
        if (fgets(nomes[count], MAX_NOME, arquivo) != NULL) {
            // Remove o caractere de nova linha, se existir
            nomes[count][strcspn(nomes[count], "\n")] = '\0';
            count++;
        }
    }

    fclose(arquivo);
    return count;
}

void imprimirNomes(char nomes[][MAX_NOME], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }
}

int main() {
    char nomes[MAX_NOMES][MAX_NOME];
    int n, opcao;
    n = lerArquivo(nomes, "nomes2.txt");

    if (n == 0) {
        printf("Nenhum nome foi lido do arquivo.\n");
        return 1;
    }

    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do enter após a leitura

        switch (opcao) {
            case 1:
                bubbleSort(nomes, n);
                printf("Nomes ordenados com Bubble Sort:\n");
                imprimirNomes(nomes, n);
                break;
            case 2:
                selectionSort(nomes, n);
                printf("Nomes ordenados com Selection Sort:\n");
                imprimirNomes(nomes, n);
                break;
            case 3:
                insertionSort(nomes, n);
                printf("Nomes ordenados com Insertion Sort:\n");
                imprimirNomes(nomes, n);
                break;
            case 4:
                mergeSort(nomes, 0, n - 1);
                printf("Nomes ordenados com Merge Sort:\n");
                imprimirNomes(nomes, n);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
