#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int info;
    struct Fila *prox;
} Fila;

void menu();

Fila *inicializa();
int enfileira(Fila **fila, int elemento);
int desenfileira(Fila **fila);
void frente(Fila **fila);
void imprimeFila(Fila **fila);

Fila *fila;

int main() {
    fila = inicializa();
    menu();

    return 0;
}

void menu() {
    int opcao = 0;
    int elemento = 0;

    do {
        system("cls");
        printf("FILA\n");
        printf("\n1 - ENFILEIRAR ELEMENTO\n");
        printf("2 - DESENFILEIRAR ELEMENTO\n");
        printf("\n3 - IMPRIMIR FRENTE\n");
        printf("4 - IMPRIMIR FILA\n");
        printf("\n0 - SAIR\n");
        printf("\n> ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            return;

        case 1:
            scanf("%d", &elemento);
            enfileira(&fila, elemento);
            break;

        case 2:
            desenfileira(&fila);
            break;

        case 3:
            frente(&fila);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        case 4:
            printf("\nPILHA: ");
            imprimeFila(&fila);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        default:
            printf("\nOPÇÃO INVÁLIDA\n");
            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;
        }
    } while (opcao != 0);
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

    Fila *filaAux = *fila;
    *fila = (*fila)->prox;
    free(filaAux);

    return 0;
}

void frente(Fila **fila) {
    if (*fila == NULL) {
        printf("\nFILA VAZIA\n");
        return;
    }

    printf("\nFRENTE: %d\n", (*fila)->info);
}

void imprimeFila(Fila **fila) {
    Fila *filaAux = *fila;

    while (filaAux != NULL) {
        printf("%d ", filaAux->info);
        filaAux = filaAux->prox;
    }

    printf("\n");
}
