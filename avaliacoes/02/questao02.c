#include <stdio.h>

void imprimir(int vetor[], int tamanho);
int diferenca(int vetor[], int tamanho, int chave);

int main(void) {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    imprimir(vetor, tamanho);
    printf("Menor diferença: %d\n", diferenca(vetor, tamanho, 10));

    return 0;
}

void imprimir(int vetor[], int tamanho) {
    printf("Vetor: {");

    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);

        if ((i + 1) < tamanho) {
            printf(", ");
        }
    }

    printf("}\n");
}

int diferenca(int vetor[], int tamanho, int chave) {
    if (tamanho == 0) {
        return -1;
    }

    int inicio = 0, meio = 0, fim = tamanho - 1;
    float diferencaAtual = 0.0, menorDiferenca = 0.0;
    int indiceMenor = 0;

    while (fim >= inicio) {
        meio = (inicio + fim) / 2;
        diferencaAtual = (float)(vetor[meio] - chave) / (float)chave;

        if (diferencaAtual < 0.0) {
            diferencaAtual *= -1;
        }

        if (inicio == 0 && fim == tamanho - 1) {
            menorDiferenca = diferencaAtual;
            indiceMenor = meio;
        }

        if (diferencaAtual == menorDiferenca) {
            indiceMenor = (vetor[meio] < vetor[indiceMenor]) ? meio : indiceMenor;
        }

        if (diferencaAtual < menorDiferenca) {
            menorDiferenca = diferencaAtual;
            indiceMenor = meio;
        }
    }

    return menorDiferenca;
}
