#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int info;
    struct Pilha *prox;
} Pilha;

void menu();

Pilha *inicializa();

int empilha(Pilha **pilha, int elemento);
int desempilha(Pilha **pilha);

void topo(Pilha **pilha);
void imprimePilha(Pilha **pilha);

Pilha *pilha;

int main() {
    pilha = inicializa();
    menu();

    return 0;
}

void menu() {
    int opcao = 0;
    int elemento = 0;

    do {
        system("cls");
        printf("PILHA\n");
        printf("\n1 - EMPILHAR ELEMENTO\n");
        printf("2 - DESEMPILHAR ELEMENTO\n");
        printf("\n3 - IMPRIMIR TOPO\n");
        printf("4 - IMPRIMIR PILHA\n");
        printf("\n0 - SAIR\n");
        printf("\n> ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            return;

        case 1:
            scanf("%d", &elemento);
            empilha(&pilha, elemento);
            break;

        case 2:
            desempilha(&pilha);
            break;

        case 3:
            topo(&pilha);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        case 4:
            printf("\nPILHA: ");
            imprimePilha(&pilha);

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

Pilha *inicializa() {
    return NULL;
}

int empilha(Pilha **pilha, int elemento) {
    Pilha *pilhaNova = (Pilha *)malloc(sizeof(Pilha));

    if (pilhaNova == NULL) {
        exit(1);
    }

    pilhaNova->info = elemento;
    pilhaNova->prox = *pilha;
    *pilha = pilhaNova;

    return 0;
}

int desempilha(Pilha **pilha) {
    if (*pilha == NULL) {
        return 1;
    }

    Pilha *pilhaAux = *pilha;
    *pilha = (*pilha)->prox;
    free(pilhaAux);

    return 0;
}

void topo(Pilha **pilha) {
    if (*pilha == NULL) {
        printf("\nPILHA VAZIA\n");
        return;
    }

    printf("\nTOPO: %d\n", (*pilha)->info);
}

void imprimePilha(Pilha **pilha) {
    Pilha *pilhaAux = *pilha;

    while (pilhaAux != NULL) {
        printf("%d ", pilhaAux->info);
        pilhaAux = pilhaAux->prox;
    }

    printf("\n");
}
