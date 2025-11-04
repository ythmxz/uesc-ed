#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int info;
    struct Lista *prox;
} typedef Lista;

struct ArvoreBinaria {
    int info;
    struct ArvoreBinaria *esquerda;
    struct ArvoreBinaria *direita;
} typedef ArvoreBinaria;

Lista *inserirLista(Lista *lista, int elemento);

ArvoreBinaria *inserirArvore(ArvoreBinaria *arvore, int elemento);
Lista *encontrarFilhos(ArvoreBinaria *arvore, int elemento);

void imprimirLista(Lista *lista);

int existe = 0;

int main() {
    ArvoreBinaria *arvore = NULL;

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int valor = 0;
            scanf("%d", &valor);
            inserirArvore(arvore, valor);
        }

        int alvo = 0;
        scanf("%d", &alvo);

        Lista *filhos = encontrarFilhos(arvore, alvo);
        imprimirLista(filhos);
    }

    return 0;
}

Lista *inserirLista(Lista *lista, int elemento) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    listaNova->info = elemento;
    listaNova->prox = NULL;

    if (lista == NULL) {
        return listaNova;
    }

    Lista *listaAux = lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux->prox = listaNova;

    return lista;
}

ArvoreBinaria *inserirArvore(ArvoreBinaria *arvore, int elemento) {
    if (arvore == NULL) {
        ArvoreBinaria *folha = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));

        if (folha == NULL) {
            exit(1);
        }

        folha->info = elemento;
        folha->esquerda = NULL;
        folha->direita = NULL;

        return folha;
    }

    if (elemento < arvore->info) {
        arvore->esquerda = inserirArvore(arvore->esquerda, elemento);
    }

    if (elemento > arvore->info) {
        arvore->direita = inserirArvore(arvore->direita, elemento);
    }

    return arvore;
}

Lista *encontrarFilhos(ArvoreBinaria *arvore, int elemento) {
    if (arvore == NULL) {
        return NULL;
    }

    if (elemento == arvore->info) {
        existe = 1;

        Lista *filhos = NULL;

        if (arvore->esquerda != NULL) {
            filhos = inserirLista(filhos, arvore->esquerda->info);
        }

        if (arvore->direita != NULL) {
            filhos = inserirLista(filhos, arvore->direita->info);
        }

        return filhos;
    }

    if (elemento < arvore->info) {
        encontrarFilhos(arvore->esquerda, elemento);
    }

    if (elemento > arvore->info) {
        encontrarFilhos(arvore->direita, elemento);
    }
}

void imprimirLista(Lista *lista) {
    printf("%d |", existe);

    while (lista != NULL) {
        printf("%d", lista->info);

        if (lista->prox != NULL) {
            printf(", ");
        }

        lista = lista->prox;
    }

    printf("|\n");
}
