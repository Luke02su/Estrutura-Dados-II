#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMES 20
#define MAX_NOME 30

typedef struct {
    char nome[MAX_NOME];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int saldo_gols;
} Time;

// Funções de ordenação
void bubble_sort(Time times[], int n);
void selection_sort(Time times[], int n);
void insertion_sort(Time times[], int n);
void merge(Time times[], int left, int mid, int right);
void merge_sort(Time times[], int left, int right);

void calcular_resultados(const char *arquivo, Time times[], int *num_times);

int main() {
    Time times[MAX_TIMES];
    int num_times = 0;

    calcular_resultados("dados.txt", times, &num_times);

    // Perguntar método de ordenação
    int metodo;
    printf("Escolha o método de ordenacao:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Digite o numero do metodo: ");
    scanf("%d", &metodo);

    // Ordenar a tabela
    switch (metodo) {
        case 1:
            bubble_sort(times, num_times);
            break;
        case 2:
            selection_sort(times, num_times);
            break;
        case 3:
            insertion_sort(times, num_times);
            break;
        case 4:
            merge_sort(times, 0, num_times - 1);
            break;
        default:
            printf("Método inválido!\n");
            return 1;
    }

    // Exibir a tabela
    printf("\nTabela do Campeonato Mineiro 2022 - Módulo 1 (Até a 7ª Rodada)\n");
    printf("Time                | Pontos | Vitórias | Empates | Derrotas | Saldo de Gols | Gols Pró | Gols Contra\n");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_times; i++) {
        printf("%-20s | %d     | %d       | %d      | %d       | %d            | %d       | %d\n",
            times[i].nome, times[i].pontos, times[i].vitorias, times[i].empates,
            times[i].derrotas, times[i].saldo_gols, times[i].gols_pro, times[i].gols_contra);
    }

    return 0;
}

void calcular_resultados(const char *arquivo, Time times[], int *num_times) {
    FILE *file = fopen(arquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[50];
    while (fgets(linha, sizeof(linha), file)) {
        char time1[MAX_NOME], time2[MAX_NOME];
        int gols1, gols2;

        // Lê a linha e armazena os resultados
        sscanf(linha, "%s %dX%d %s", time1, &gols1, &gols2, time2);

        // Atualiza estatísticas do time 1
        int index1 = -1, index2 = -1;
        for (int i = 0; i < *num_times; i++) {
            if (strcmp(times[i].nome, time1) == 0) {
                index1 = i;
            }
            if (strcmp(times[i].nome, time2) == 0) {
                index2 = i;
            }
        }

        // Se o time não foi encontrado, adiciona
        if (index1 == -1) {
            strcpy(times[*num_times].nome, time1);
            index1 = (*num_times)++;
            times[index1].pontos = 0;
            times[index1].vitorias = 0;
            times[index1].empates = 0;
            times[index1].derrotas = 0;
            times[index1].gols_pro = 0;
            times[index1].gols_contra = 0;
        }
        if (index2 == -1) {
            strcpy(times[*num_times].nome, time2);
            index2 = (*num_times)++;
            times[index2].pontos = 0;
            times[index2].vitorias = 0;
            times[index2].empates = 0;
            times[index2].derrotas = 0;
            times[index2].gols_pro = 0;
            times[index2].gols_contra = 0;
        }

        // Atualiza gols
        times[index1].gols_pro += gols1;
        times[index1].gols_contra += gols2;
        times[index2].gols_pro += gols2;
        times[index2].gols_contra += gols1;

        // Atualiza resultados
        if (gols1 > gols2) {
            times[index1].pontos += 3;
            times[index1].vitorias++;
            times[index2].derrotas++;
        } else if (gols1 < gols2) {
            times[index2].pontos += 3;
            times[index2].vitorias++;
            times[index1].derrotas++;
        } else {
            times[index1].pontos++;
            times[index2].pontos++;
            times[index1].empates++;
            times[index2].empates++;
        }
    }

    fclose(file);

    // Calcular saldo de gols
    for (int i = 0; i < *num_times; i++) {
        times[i].saldo_gols = times[i].gols_pro - times[i].gols_contra;
    }
}

// Implementação dos métodos de ordenação
void bubble_sort(Time times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j].pontos < times[j + 1].pontos ||
                (times[j].pontos == times[j + 1].pontos && times[j].vitorias < times[j + 1].vitorias) ||
                (times[j].pontos == times[j + 1].pontos && times[j].vitorias == times[j + 1].vitorias && times[j].saldo_gols < times[j + 1].saldo_gols) ||
                (times[j].pontos == times[j + 1].pontos && times[j].vitorias == times[j + 1].vitorias && times[j].saldo_gols == times[j + 1].saldo_gols && times[j].gols_pro < times[j + 1].gols_pro)) {
                Time temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
}

void selection_sort(Time times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (times[j].pontos > times[max_idx].pontos ||
                (times[j].pontos == times[max_idx].pontos && times[j].vitorias > times[max_idx].vitorias) ||
                (times[j].pontos == times[max_idx].pontos && times[j].vitorias == times[max_idx].vitorias && times[j].saldo_gols > times[max_idx].saldo_gols) ||
                (times[j].pontos == times[max_idx].pontos && times[j].vitorias == times[max_idx].vitorias && times[j].saldo_gols == times[max_idx].saldo_gols && times[j].gols_pro > times[max_idx].gols_pro)) {
                max_idx = j;
            }
        }
        Time temp = times[i];
        times[i] = times[max_idx];
        times[max_idx] = temp;
    }
}

void insertion_sort(Time times[], int n) {
    for (int i = 1; i < n; i++) {
        Time key = times[i];
        int j = i - 1;
        while (j >= 0 && (key.pontos > times[j].pontos ||
                          (key.pontos == times[j].pontos && key.vitorias > times[j].vitorias) ||
                          (key.pontos == times[j].pontos && key.vitorias == times[j].vitorias && key.saldo_gols > times[j].saldo_gols) ||
                          (key.pontos == times[j].pontos && key.vitorias == times[j].vitorias && key.saldo_gols == times[j].saldo_gols && key.gols_pro > times[j].gols_pro))) {
            times[j + 1] = times[j];
            j--;
        }
        times[j + 1] = key;
    }
}

void merge(Time times[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Time *L = (Time *)malloc(n1 * sizeof(Time));
    Time *R = (Time *)malloc(n2 * sizeof(Time));

    for (int i = 0; i < n1; i++)
        L[i] = times[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = times[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].pontos > R[j].pontos ||
            (L[i].pontos == R[j].pontos && L[i].vitorias > R[j].vitorias) ||
            (L[i].pontos == R[j].pontos && L[i].vitorias == R[j].vitorias && L[i].saldo_gols > R[j].saldo_gols) ||
            (L[i].pontos == R[j].pontos && L[i].vitorias == R[j].vitorias && L[i].saldo_gols == R[j].saldo_gols && L[i].gols_pro > R[j].gols_pro)) {
            times[k++] = L[i++];
        } else {
            times[k++] = R[j++];
        }
    }

    while (i < n1) {
        times[k++] = L[i++];
    }
    while (j < n2) {
        times[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(Time times[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(times, left, mid);
        merge_sort(times, mid + 1, right);
        merge(times, left, mid, right);
    }
}
