#define MAX 1002

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    char info;
    struct Pilha *prox;
} Pilha;

Pilha *inicializa();
int empilha(Pilha **pilha, char elemento);
int desempilha(Pilha **pilha);
char topo(Pilha **pilha);

int main() {
    Pilha *pilha = inicializa();
    char buffer[MAX];

    fgets(buffer, MAX, stdin);

    if (strlen(buffer) == 1 || strcmp(buffer, "0\n") == 0) {
        return 0;
    }

    int valido = 1;

    for (int i = 0; buffer[i] != '\n'; i++) {
        char c = buffer[i];

        if (c == '(' || c == '{' || c == '[') {
            empilha(&pilha, c);
        }

        else if (c == ')' || c == '}' || c == ']') {
            if (pilha == NULL) {
                valido = 0;
                break;
            }

            if ((c == ')' && topo(&pilha) != '(') || (c == '}' && topo(&pilha) != '{') ||
                (c == ']' && topo(&pilha) != '[')) {
                valido = 0;
                break;
            }

            desempilha(&pilha);
        }

        else {
            continue;
        }
    }

    if (pilha != NULL) {
        valido = 0;
    }

    if (valido) {
        printf("Sim\n");
        return 0;
    }

    printf("Não\n");
    return 0;
}

Pilha *inicializa() {
    return NULL;
}

int empilha(Pilha **pilha, char elemento) {
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

char topo(Pilha **pilha) {
    if (*pilha == NULL) {
        return ' ';
    }

    return (*pilha)->info;
}
