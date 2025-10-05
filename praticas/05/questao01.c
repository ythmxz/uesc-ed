#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int info;
    struct Pilha *prox;
} Pilha;

Pilha *inicializa();
int empilha(Pilha **pilha, int elemento);
int desempilha(Pilha **pilha);
void imprimePilha(Pilha **pilha);

int main() {
    int tamanho = 0;
    do {
        Pilha *pilha = inicializa();

        scanf("%d", &tamanho);

        if (tamanho < 0 || tamanho >= 1000) {
            return 1;
        }

        for (int i = 0; i < tamanho; i++) {
            char acao = ' ';
            scanf(" %c", &acao);

            switch (acao) {
            case 'E':
                int valor = 0;
                scanf("%d", &valor);

                if (valor < 0 || valor > 10000) {
                    return 1;
                }

                empilha(&pilha, valor);
                break;

            case 'D':
                if (pilha == NULL) {
                    return 1;
                }

                desempilha(&pilha);
                break;

            default:
                return 1;
            }

            imprimePilha(&pilha);
        }

        free(pilha);
    } while (tamanho != 0);

    return 0;
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

void imprimePilha(Pilha **pilha) {
    if (*pilha == NULL) {
        printf("*\n");
        return;
    }

    Pilha *pilhaAux = *pilha;

    while (pilhaAux != NULL) {
        printf("%d ", pilhaAux->info);
        pilhaAux = pilhaAux->prox;
    }

    printf("\n");
}
