#include <stdio.h>

typedef struct Fila {
    int info;
    struct Fila *prox;
} Fila;

Fila *inicializar();
Fila *enfileirar(Fila *F, int num);
Fila *duplicar_pares(Fila *F, int L);

int main() {
    Fila *F = inicializar();

    int n = 0;
    scanf("%d", &n);

    if (n < 0) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int num = 0;
        scanf("%d", &num);

        F = enfileirar(F, num);
    }

    int L = 0;
    scanf("%d", &L);

    F = duplicar_pares(F, L);

    Fila *P_aux = F;

    while (P_aux->prox != NULL) {
        printf("%d ", P_aux->info);
        P_aux = P_aux->prox;
    }

    printf("\n");

    return 0;
}

Fila *inicializar() {
    return NULL;
}

Fila *enfileirar(Fila *F, int num) {
    Fila *F_novo = (Fila *)malloc(sizeof(Fila));

    if (F_novo == NULL) {
        exit(1);
    }

    F_novo->info = num;
    F_novo->prox = NULL;

    if (F == NULL) {
        return F_novo;
    }

    Fila *F_aux = F;

    while (F_aux->prox != NULL) {
        F_aux = F_aux->prox;
    }

    F_aux->prox = F_novo;

    return F;
}

Fila *duplicar_pares(Fila *F, int L) {
    Fila *F_novo = (Fila *)malloc(sizeof(Fila));

    while (F != NULL) {
        F_novo = enfileirar(F_novo, F->info);
        if ((F->info % 2) == 0 && F->info <= L) {
            F_novo = enfileirar(F_novo, F->info);
        }

        F = F->prox;
    }

    return F_novo;
}
