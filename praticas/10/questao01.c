#include <stdio.h>
#include <stdlib.h>

int *adicionaElemento(int vetor[], int *tamanho, int elemento);
void imprimeVetor(int vetor[], int tmamanho);

void swap(int *a, int *b);
int buscaBinaria(int vetor[], int tamanho, int elemento);

int particiona(int vetor[], int inicio, int fim);
void quickSort(int vetor[], int inicio, int fim);

int main(void) {
    // int tamanhoDesejado = 0;
    // scanf("%d", &tamanhoDesejado);

    // int *vetor = NULL;
    // int tamanhoVetor = 0;
    //  adicionaElemento(vetor, &tamanhoVetor, 1);
    int vetor[] = {1, 2, 3};
    imprimeVetor(vetor, 3);

    return 0;
}

int *adicionaElemento(int *vetor, int *tamanho, int elemento) {
    vetor = (vetor) ? (int *)realloc(vetor, (*tamanho + 1) * sizeof(int)) : (int *)malloc(sizeof(int));
    vetor[*tamanho] = elemento;
    *tamanho++;

    return vetor;
}

void imprimeVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int buscaBinaria(int vetor[], int tamanho, int elemento) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == elemento) {
            return meio;
        }

        if (vetor[meio] < elemento) {
            inicio = meio + 1;
        }

        if (vetor[meio] > elemento) {
            fim = meio - 1;
        }
    }

    return -1;
}

int particiona(int vetor[], int inicio, int fim) {
    int pivo = vetor[inicio];

    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }

    swap(&vetor[i + 1], &vetor[fim]);

    return (i + 1);
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = particiona(vetor, inicio, fim);

        quickSort(vetor, inicio, meio - 1);
        quickSort(vetor, meio + 1, fim);
    }
}
