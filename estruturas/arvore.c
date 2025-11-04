#include <stdio.h>

struct No {
    int info;
    struct No *esquerda;
    struct No *direita;
} typedef ArvoreBinaria;

ArvoreBinaria *inserir(ArvoreBinaria *raiz, int elemento);

int main() {
    return 0;
}

ArvoreBinaria *inserir(ArvoreBinaria *raiz, int elemento) {
    if (raiz == NULL) {
        ArvoreBinaria *folha = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));

        folha->info = elemento;
        folha->esquerda = NULL;
        folha->direita = NULL;

        return folha;
    }

    if (elemento > raiz->info) {
        raiz->direita = inserir(raiz->direita, elemento);
    }

    if (elemento < raiz->info) {
        raiz->esquerda = inserir(raiz->esquerda, elemento);
    }

    return raiz;
}
