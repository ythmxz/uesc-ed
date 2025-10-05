#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int info;
    struct Fila *prox;
} Fila;

Fila *inicializa();
int enfileira(Fila **fila, int elemento);

int main() {
    int tamanho = 0;
    scanf("%d", &tamanho);

    if (tamanho < 1) {
        return 1;
    }

    do {
        Fila *fila = inicializa();

        int alunos = 0;
        scanf("%d", &alunos);

        if (alunos < 1 || alunos > 1000) {
            return 1;
        }

        for (int i = 0; i < alunos; i++) {
            int nota = 0;
            scanf("%d", &nota);

            if (nota < 0) {
                return 1;
            }

            enfileira(&fila, nota);
        }

        int trocas = 0;

        Fila *filaAux = fila;

        while (filaAux->prox != NULL) {
            if (filaAux->info < filaAux->prox->info) {
                trocas += 2;
            }

            filaAux = filaAux->prox;
        }

        printf("%d\n", alunos - trocas);
        tamanho--;
    } while (tamanho != 0);

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
