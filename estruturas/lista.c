#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int info;
    struct Lista *prox;
} Lista;

void menu();

Lista *inicializa();

Lista *insereInicio(Lista *lista, int elemento);
Lista *insereFinal(Lista *lista, int elemento);
Lista *removeInicio(Lista *lista);
Lista *removeFinal(Lista *lista);

void insereInicioPtr(Lista **lista, int elemento);
void insereFinalPtr(Lista **lista, int elemento);
void removeInicioPtr(Lista **lista);
void removeFinalPtr(Lista **lista);

void imprimeLista(Lista *lista);

Lista *lista;
Lista *listaPtr;

int main() {
    lista = inicializa();
    listaPtr = inicializa();
    menu();

    return 0;
}

void menu() {
    int opcao = 0;
    int elemento = 0;

    do {
        system("cls");
        printf("LISTA SIMPLESMENTE ENCADEADA\n");
        printf("\n1 - INSERIR ELEMENTO NO INÍCIO\n");
        printf("2 - INSERIR ELEMENTO NO FINAL\n");
        printf("\n3 - REMOVER PRIMEIRO ELEMENTO\n");
        printf("4 - REMOVER ÚLTIMO ELEMENTO\n");
        printf("\n5 - IMPRIMIR LISTA\n");
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
            printf("\nLISTA: ");
            imprimeLista(lista);
            printf("LISTA (PTR): ");
            imprimeLista(listaPtr);

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

Lista *inicializa() {
    return NULL;
}

Lista *insereInicio(Lista *lista, int elemento) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = lista;

    return listaNova;
}

Lista *insereFinal(Lista *lista, int elemento) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL) {
        exit(1);
    }

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

Lista *removeInicio(Lista *lista) {
    if (lista == NULL) {
        return lista;
    }

    Lista *listaNova = lista->prox;
    free(lista);

    return listaNova;
}

Lista *removeFinal(Lista *lista) {
    if (lista == NULL) {
        return lista;
    }

    Lista *listaAux1 = lista;

    while (listaAux1->prox != NULL) {
        listaAux1 = listaAux1->prox;
    }

    Lista *listaAux2 = lista;

    while (listaAux2->prox != listaAux1) {
        listaAux2 = listaAux2->prox;
    }

    listaAux2->prox = NULL;
    free(listaAux1);

    return lista;
}

void insereInicioPtr(Lista **lista, int elemento) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = *lista;

    *lista = listaNova;
}

void insereFinalPtr(Lista **lista, int elemento) {
    Lista *listaNova = (Lista *)malloc(sizeof(Lista));

    if (listaNova == NULL) {
        exit(1);
    }

    listaNova->info = elemento;
    listaNova->prox = NULL;

    if (*lista == NULL) {
        *lista = listaNova;
        return;
    }

    Lista *listaAux = *lista;

    while (listaAux->prox != NULL) {
        listaAux = listaAux->prox;
    }

    listaAux->prox = listaNova;
}

void removeInicioPtr(Lista **lista) {
    if (*lista == NULL) {
        return;
    }

    Lista *listaAux = *lista;
    *lista = (*lista)->prox;
    free(listaAux);
}

void removeFinalPtr(Lista **lista) {
    if (*lista == NULL) {
        return;
    }

    Lista *listaAux1 = *lista;

    while (listaAux1->prox != NULL) {
        listaAux1 = listaAux1->prox;
    }

    Lista *listaAux2 = *lista;

    while (listaAux2->prox != listaAux1) {
        listaAux2 = listaAux2->prox;
    }

    listaAux2->prox = NULL;
    free(listaAux1);
}

void imprimeLista(Lista *lista) {
    Lista *listaAux = lista;

    while (listaAux != NULL) {
        printf("%d ", listaAux->info);
        listaAux = listaAux->prox;
    }

    printf("\n");
}
