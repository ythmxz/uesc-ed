#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int valor;
    struct Lista *proximo;
} Lista;

Lista *inicializa();
Lista *adicionaP(Lista *lista, int valor);
Lista *adicionaU(Lista *lista, int valor);
void imprimeLista(Lista *lista);

int main() {
    int tamanho = 0;

    do {
        Lista *lista = inicializa();

        scanf("%d", &tamanho);

        if (tamanho <= 0 || tamanho >= 1000) {
            return 1;
        }

        for (int i = 0; i < tamanho; i++) {
            char acao = ' ';
            int valor = 0;

            scanf(" %c %d", &acao, &valor);

            if (valor < 0 || valor > 10000)
                return 1;

            switch (acao) {
            case 'P':
                lista = adicionaP(lista, valor);
                break;

            case 'U':
                lista = adicionaU(lista, valor);
                break;

            default:
                return 1;
            }
        }

        imprimeLista(lista);
        free(lista);
    }

    while (tamanho != 0);

    return 0;
}

Lista *inicializa() {
    return NULL;
}

Lista *adicionaP(Lista *lista, int valor) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL)
        exit(1);

    listaNova->valor = valor;
    listaNova->proximo = lista;

    return listaNova;
}

Lista *adicionaU(Lista *lista, int valor) {
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

void imprimeLista(Lista *lista) {
    Lista *listaAux = lista;

    while (listaAux != NULL) {
        printf("%d ", listaAux->valor);
        listaAux = listaAux->proximo;
    }

    printf("\n");
}
