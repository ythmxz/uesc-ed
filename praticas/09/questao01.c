#include <stdio.h>
#include <stdlib.h>

struct No {
    int info;
    int balanceamento;
    struct No *esquerda;
    struct No *direita;
} typedef ArvoreAVL;

void swap(int *a, int *b);
int max(int a, int b);

ArvoreAVL *inserir(ArvoreAVL *raiz, int elemento);
ArvoreAVL *remover(ArvoreAVL *raiz, int elemento);
ArvoreAVL *rotacionar(ArvoreAVL *raiz);

int fatorBalanceamento(ArvoreAVL *raiz);
void calcularBalanceamento(ArvoreAVL *raiz);
void imprimir(ArvoreAVL *raiz);

int main(void) {
    return 0;
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

ArvoreAVL *inserir(ArvoreAVL *raiz, int elemento) {
    if (!raiz) {
        ArvoreAVL *folha = (ArvoreAVL *)malloc(sizeof(ArvoreAVL));

        folha->info = elemento;
        folha->esquerda = NULL;
        folha->direita = NULL;

        return folha;
    }

    if (elemento < raiz->info) {
        inserir(raiz->esquerda, elemento);
    }

    if (elemento > raiz->info) {
        inserir(raiz->direita, elemento);
    }

    return raiz;
}

ArvoreAVL *remover(ArvoreAVL *raiz, int elemento) {
    if (!raiz) {
        return;
    }

    if (elemento == raiz->info) {
        if (!raiz->esquerda && !raiz->direita) {
            raiz = NULL;
        }
        if (raiz->esquerda && !raiz->direita) {
            swap(raiz->info, raiz->esquerda->info);
            raiz->esquerda = NULL;
        }
        if (!raiz->esquerda && raiz->direita) {
            swap(raiz->info, raiz->direita->info);
            raiz->direita = NULL;
        }
        if (raiz->esquerda && raiz->direita) {}
    }

    remover(raiz->esquerda, elemento);
    remover(raiz->direita, elemento);
}

int altura(ArvoreAVL *raiz) {
    if (!raiz) {
        return -1;
    }

    return max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
}

int fatorBalanceamento(ArvoreAVL *raiz) {
    return 0;
}

void imprimir(ArvoreAVL *raiz) {
    if (!raiz) {
        return;
    }

    imprimir(raiz->esquerda);
    printf("%d ", raiz->info);
    imprimir(raiz->direita);

    printf("\n");
}
