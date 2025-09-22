#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListaDupla {
    int info;
    struct ListaDupla *prox;
    struct ListaDupla *ant;
} ListaDupla;

void menu();

ListaDupla *inicializa();

ListaDupla *insereInicio(ListaDupla *lista, int elemento);
ListaDupla *insereFinal(ListaDupla *lista, int elemento);
ListaDupla *removeInicio(ListaDupla *lista);
ListaDupla *removeFinal(ListaDupla *lista);

void insereInicioPtr(ListaDupla **lista, int elemento);
void insereFinalPtr(ListaDupla **lista, int elemento);
void removeInicioPtr(ListaDupla **lista);
void removeFinalPtr(ListaDupla **lista);

int buscaElemento(ListaDupla *lista, int elemento);
ListaDupla *buscaAntecessor(ListaDupla *lista, int elemento);
void imprimeCrescente(ListaDupla *lista);
void imprimeDecrescente(ListaDupla *lista);

ListaDupla *lista;
ListaDupla *listaPtr;

int main() {
    lista = inicializa();
    listaPtr = inicializa();
    menu();

    return 0;
}

void menu() {
    int opcao = 0;
    int elemento = 0;
    int resultado = 0;
    ListaDupla *listaResultado = inicializa();

    do {
        system("cls");
        printf("LISTA DUPLAMENTE ENCADEADA\n");
        printf("\n1 - INSERIR ELEMENTO NO INÍCIO\n");
        printf("2 - INSERIR ELEMENTO NO FINAL\n");
        printf("\n3 - REMOVER PRIMEIRO ELEMENTO\n");
        printf("4 - REMOVER ÚLTIMO ELEMENTO\n");
        printf("\n5 - BUSCAR ELEMENTO\n");
        printf("6 - BUSCAR ANTECESSOR\n");
        printf("\n7 - IMPRIMIR LISTA CRESCENTE\n");
        printf("8 - IMPRIMIR LISTA DECRESCENTE\n");
        printf("\n0 - SAIR\n");
        printf("\n> ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            return;

        case 1:
            scanf("%d", &elemento);
            lista = insereInicio(lista, elemento);
            insereInicioPtr(&listaPtr, elemento);
            break;

        case 2:
            scanf("%d", &elemento);
            lista = insereFinal(lista, elemento);
            insereFinalPtr(&listaPtr, elemento);
            break;

        case 3:
            lista = removeInicio(lista);
            removeInicioPtr(&listaPtr);
            break;

        case 4:
            lista = removeFinal(lista);
            removeFinalPtr(&listaPtr);
            break;

        case 5:
            scanf("%d", &elemento);
            resultado = buscaElemento(lista, elemento);
            printf("\nPOSIÇÃO: %d\n", resultado);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        case 6:
            scanf("%d", &elemento);
            listaResultado = buscaAntecessor(lista, elemento);
            printf("\nLISTA: ");
            imprimeCrescente(listaResultado);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        case 7:
            printf("\nLISTA: ");
            imprimeCrescente(lista);
            printf("LISTA (PTR): ");
            imprimeCrescente(listaPtr);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        case 8:
            printf("\nLISTA: ");
            imprimeDecrescente(lista);
            printf("LISTA (PTR): ");
            imprimeDecrescente(listaPtr);

            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
            break;

        default:
            printf("\nOPÇÃO INVÁLIDA\n");
            printf("\nPRESSIONE QUALQUER TELCA PARA CONTINUAR");
            getch();
        }
    } while (opcao != 0);
}

ListaDupla *inicializa() {
    return NULL;
}

ListaDupla *insereInicio(ListaDupla *lista, int elemento) {
    ListaDupla *listaNova = (ListaDupla *)malloc(sizeof(ListaDupla));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = lista;
    listaNova->ant = NULL;

    if (lista != NULL) {
        lista->ant = listaNova;
    }

    return listaNova;
}

ListaDupla *insereFinal(ListaDupla *lista, int elemento) {
    ListaDupla *listaNova = (ListaDupla *)malloc(sizeof(ListaDupla));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = NULL;
    listaNova->ant = NULL;

    if (lista == NULL) {
        return listaNova;
    }

    ListaDupla *listaAux = lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux->prox = listaNova;
    listaNova->ant = listaAux;

    return lista;
}

ListaDupla *removeInicio(ListaDupla *lista) {
    if (lista == NULL) {
        return lista;
    }

    ListaDupla *listaNova = lista->prox;

    if (listaNova != NULL) {
        listaNova->ant = NULL;
    }

    free(lista);
    return listaNova;
}

ListaDupla *removeFinal(ListaDupla *lista) {
    if (lista == NULL) {
        return lista;
    }

    ListaDupla *listaAux = lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux = listaAux->ant;
    listaAux->prox = NULL;

    return lista;
}

void insereInicioPtr(ListaDupla **lista, int elemento) {
    ListaDupla *listaNova = (ListaDupla *)malloc(sizeof(ListaDupla));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = *lista;
    listaNova->ant = NULL;

    if (*lista != NULL) {
        (*lista)->ant = listaNova;
    }

    *lista = listaNova;
}

void insereFinalPtr(ListaDupla **lista, int elemento) {
    ListaDupla *listaNova = (ListaDupla *)malloc(sizeof(ListaDupla));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = NULL;
    listaNova->ant = NULL;

    if (*lista == NULL) {
        *lista = listaNova;
        return;
    }

    ListaDupla *listaAux = *lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux->prox = listaNova;
    listaNova->ant = listaAux;
}

void removeInicioPtr(ListaDupla **lista) {
    if (lista == NULL) {
        return;
    }

    ListaDupla *listaAux = *lista;
    *lista = (*lista)->prox;

    if (*lista != NULL) {
        (*lista)->ant = NULL;
    }

    free(listaAux);
}

void removeFinalPtr(ListaDupla **lista) {
    if (lista == NULL) {
        return;
    }

    ListaDupla *listaAux = *lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux = listaAux->ant;
    listaAux->prox = NULL;
}

int buscaElemento(ListaDupla *lista, int elemento) {
    ListaDupla *listaAux = lista;
    int posicao = 0;

    while (listaAux != NULL) {
        if (listaAux->info == elemento) {
            return posicao;
        }

        listaAux = listaAux->prox;
        posicao++;
    }

    return -1;
}

ListaDupla *buscaAntecessor(ListaDupla *lista, int elemento) {
    ListaDupla *listaAux = lista;
    int posicao = 0;

    while (listaAux != NULL) {
        if (listaAux->info == elemento) {
            return listaAux->ant;
        }

        listaAux = listaAux->prox;
        posicao++;
    }

    return NULL;
}

void imprimeCrescente(ListaDupla *lista) {
    ListaDupla *listaAux = lista;

    while (listaAux != NULL) {
        printf("%d ", listaAux->info);
        listaAux = listaAux->prox;
    }

    printf("\n");
}

void imprimeDecrescente(ListaDupla *lista) {
    ListaDupla *listaAux = lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    while (listaAux != NULL) {
        printf("%d ", listaAux->info);
        listaAux = listaAux->ant;
    }

    printf("\n");
}
