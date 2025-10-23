#include <stdio.h>

typedef struct Pilha {
    int info;
    struct Pilha *prox;
} Pilha;

Pilha *inicializar();
Pilha *empilhar(Pilha *P, int num);
Pilha *mover_multiplos_para_topo(Pilha *P, int m);

int main() {
    Pilha *P = inicializar();

    int n = 0;
    scanf("%d", &n);

    if (n < 0) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int num = 0;
        scanf("%d", &num);

        P = empilhar(P, num);
    }

    int m = 0;
    scanf("%d", &m);

    P = mover_multiplos_para_topo(P, m);

    Pilha *P_aux = P;

    while (P_aux->prox != NULL) {
        printf("%d ", P_aux->info);
        P_aux = P_aux->prox;
    }

    printf("\n");

    return 0;
}

Pilha *inicializar() {
    return NULL;
}

Pilha *empilhar(Pilha *P, int num) {
    Pilha *P_novo = (Pilha *)malloc(sizeof(Pilha));

    if (P_novo == NULL) {
        exit(1);
    }

    P_novo->info = num;
    P_novo->prox = P;

    return P_novo;
}

Pilha *mover_multiplos_para_topo(Pilha *P, int m) {
    if (P == NULL) {
        return P;
    }

    Pilha *P_multiplos = (Pilha *)malloc(sizeof(Pilha));
    Pilha *P_nao_multiplos = (Pilha *)malloc(sizeof(Pilha));

    while (P != NULL) {
        if ((P->info % m) == 0) {
            P_multiplos = empilhar(P_multiplos, P->info);
        } else {
            P_nao_multiplos = empilhar(P_nao_multiplos, P->info);
        }

        P = P->prox;
    }

    Pilha *P_novo = (Pilha *)malloc(sizeof(Pilha));

    while (P_nao_multiplos != NULL) {
        P_novo = empihar(P_novo, P_nao_multiplos->info);
        P_nao_multiplos = P_nao_multiplos->prox;
    }

    while (P_multiplos != NULL) {
        P_novo = empihar(P_novo, P_multiplos->info);
        P_multiplos = P_multiplos->prox;
    }

    return P_novo;
}
