#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para converter uma string para letras minúsculas
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Função de busca binária para encontrar o primeiro nome que corresponde ao prefixo
int buscaBinaria(char *nomes[], int n, char *prefixo) {
    int inicio = 0, fim = n - 1, posicao = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (strncmp(nomes[meio], prefixo, strlen(prefixo)) == 0) {
            posicao = meio;
            fim = meio - 1;  // Continua procurando para a esquerda
        } else if (strcmp(nomes[meio], prefixo) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return posicao;
}

// Função para ler os nomes do arquivo e armazená-los em um vetor
int lerNomes(char *nomes[], int maxNomes, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int i = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) && i < maxNomes) {
        linha[strcspn(linha, "\n")] = '\0';  // Remove o newline
        nomes[i] = strdup(linha);            // Aloca e copia a linha para o vetor
        toLowerCase(nomes[i]);               // Converte para minúsculas para ignorar case
        i++;
    }
    fclose(arquivo);
    return i;
}

int main() {
    const int MAX_NOMES = 1000;
    char *nomes[MAX_NOMES];
    int numNomes = lerNomes(nomes, MAX_NOMES, "nomes.txt");

    if (numNomes == 0) {
        return 1;
    }

    // Solicita o prefixo ao usuário
    char prefixo[50];
    printf("Digite o prefixo para a busca: ");
    scanf("%s", prefixo);
    toLowerCase(prefixo);  // Converte o prefixo para minúsculas

    // Realiza a busca binária para encontrar o primeiro índice que corresponde ao prefixo
    int posicao = buscaBinaria(nomes, numNomes, prefixo);
    if (posicao == -1) {
        printf("Nenhum nome encontrado com o prefixo \"%s\".\n", prefixo);
    } else {
        printf("Nomes encontrados:\n");
        // Imprime todos os nomes que começam com o prefixo encontrado
        for (int i = posicao; i < numNomes && strncmp(nomes[i], prefixo, strlen(prefixo)) == 0; i++) {
            printf("%s\n", nomes[i]);
        }
    }

    // Libera a memória alocada para os nomes
    for (int i = 0; i < numNomes; i++) {
        free(nomes[i]);
    }

    return 0;
}
