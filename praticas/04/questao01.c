#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int valor;
    struct Lista *proximo;
} Lista;

Lista *inicializa();
Lista *adiciona(Lista *lista, int valor);
Lista *reordenaLista(Lista *lista);
void imprimeLista(Lista *lista);

Lista *listaImpar;
Lista *listaPar;

int main() {
    int tamanho = 0;
    scanf("%d", &tamanho);

    if (tamanho < 0 || tamanho > 100) {
        printf("O valor de N fora do intervalo");
        return 1;
    }

    listaImpar = inicializa();
    listaPar = inicializa();

    for (int i = 0; i < tamanho; i++) {
        int valor = 0;
        scanf("%d", &valor);

        if (valor % 2 == 0)
            listaPar = adiciona(listaPar, valor);
        else
            listaImpar = adiciona(listaImpar, valor);
    }

    Lista *listaOrdenada = inicializa();
    listaOrdenada = reordenaLista(listaOrdenada);
    imprimeLista(listaOrdenada);

    free(listaImpar);
    free(listaPar);
    free(listaOrdenada);

    return 0;
}

Lista *inicializa() {
    return NULL;
}

Lista *adiciona(Lista *lista, int valor) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL)
        exit(1);

    listaNova->valor = valor;
    listaNova->proximo = NULL;

    if (lista == NULL)
        return listaNova;

    Lista *listaAux = lista;

    while (listaAux->proximo != NULL)
        listaAux = listaAux->proximo;

    listaAux->proximo = listaNova;

    return lista;
}

Lista *reordenaLista(Lista *lista) {
    Lista *listaImparAux = listaImpar;
    Lista *listaParAux = listaPar;

    while (listaImparAux != NULL) {
        lista = adiciona(lista, listaImparAux->valor);
        listaImparAux = listaImparAux->proximo;
    }

    while (listaParAux != NULL) {
        lista = adiciona(lista, listaParAux->valor);
        listaParAux = listaParAux->proximo;
    }

    return lista;
}

void imprimeLista(Lista *lista) {
    Lista *listaAux = lista;

    while (listaAux != NULL) {
        printf("%d ", listaAux->valor);
        listaAux = listaAux->proximo;
    }

    printf("\n");
}
