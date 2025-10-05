#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int info;
    struct Fila *prox;
} Fila;

Fila *inicializa();
int enfileira(Fila **fila, int elemento);
int desenfileira(Fila **fila);
void imprimeFila(Fila **fila);

int main() {
    Fila *fila = inicializa();
    int capacidade = 0;
    char acao = ' ';

    do {

        scanf(" %c", &acao);

        switch (acao) {
        case 'E':
            int valor = 0;
            scanf("%d", &valor);

            if (capacidade == MAX) {
                printf("fila cheia\n");
                break;
            }

            enfileira(&fila, valor);
            capacidade++;

            break;

        case 'D':
            desenfileira(&fila);
            capacidade--;

            break;

        case 'P':
            imprimeFila(&fila);
            break;

        case 'F':
            break;

        default:
            return 1;
        }
    } while (acao != 'F');

    return 0;
}

Fila *inicializa() {
    return NULL;
}

int enfileira(Fila **fila, int elemento) {
    Fila *filaNova = (Fila *)malloc(sizeof(Fila));

    if (filaNova == NULL) {
        exit(1);
    }

    filaNova->info = elemento;
    filaNova->prox = NULL;

    if (*fila == NULL) {
        *fila = filaNova;
        return 0;
    }

    Fila *filaAux = *fila;

    while (filaAux->prox != NULL) {
        filaAux = filaAux->prox;
    }

    filaAux->prox = filaNova;
    return 0;
}

int desenfileira(Fila **fila) {
    if (*fila == NULL) {
        return 1;
    }

    printf("%d\n", (*fila)->info);

    Fila *filaAux = *fila;
    *fila = (*fila)->prox;
    free(filaAux);

    return 0;
}

void imprimeFila(Fila **fila) {
    if (*fila == NULL) {
        printf("fila vazia\n");
        return;
    }

    Fila *filaAux = *fila;

    while (filaAux != NULL) {
        printf("%d ", filaAux->info);
        filaAux = filaAux->prox;
    }

    printf("\n");
}
