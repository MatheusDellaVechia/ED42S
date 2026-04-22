#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "22-04.h"

struct item {
  int chave;
};

struct lista
{
    Item vetItem[MAX_TAM];
    int ultimo;
};

Lista *criaListaVazia() {
    Lista *lista = malloc(sizeof(Lista));
    lista->ultimo = -1;
    return lista;
};

int verificaListaVazia(Lista *lista) {
    return lista->ultimo == -1;
}

int verificaListaCheia(Lista *lista) {
   return lista->ultimo == MAX_TAM - 1; 
}

void imprimeLista(Lista *lista) {
    if (verificaListaVazia(lista)) {
        printf("A lista esta vazia");
        return;
    }

    for (int i = 0; i <= lista->ultimo; i++) {
        printf("%d ", lista->vetItem[i].chave);
    }
    printf("\n");
}


int buscaItemPorChave(Lista *lista, int chave)
{
    int i = 0;
    while ((i <= lista->ultimo) && (lista->vetItem[i]).chave != chave)
    {
        i++;

    }

    if (i <= lista->ultimo)
    {
        return i;
    }
    return -1;
}


void removeItem(Lista *lista, int chave) {
    int posicao = buscaItemPorChave(lista, chave);

    if (posicao == -1 ) {
        printf("A lista esta vazia ou o item nao existe");
        return;
    }

    for (int i = posicao; i <= lista->ultimo; i++) {
        lista->vetItem[i] = lista->vetItem[i + 1];
    }

    lista->ultimo --;
}

void liberaLista(Lista *lista) {
    free(lista);
}

void adicionaItemFimLista(Lista *lista, int chave) {
    if (verificaListaCheia(lista)) {
        printf("A lista esta cheia");
        return;
    }

    Item item;
    item.chave = chave;

    lista->ultimo++;
    lista->vetItem[lista->ultimo] = item;
}