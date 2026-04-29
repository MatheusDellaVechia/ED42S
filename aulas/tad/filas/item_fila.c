#include <stdlib.h>
#include <stdio.h>
#include "item_fila.h"

struct item {
   int chave;
};

struct fila {
    Item vetItem[MAX_TAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila *criaFilavazia() {
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

int verificaFilaCheia(Fila *f) {
    return (f->tamanho == MAX_TAM);
}

int verificaFilaVazia(Fila *f) {
    return (f->tamanho == 0);
}

void enfileira(Fila *f, int chave) {
    if (verificaFilaCheia(f)) {
        printf("Erro: a fila esta cheia\n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    f->vetItem[f->ultimo] = novoItem;
    f->ultimo = (f->ultimo + 1) % MAX_TAM;
    f->tamanho++;
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Erro: a fila esta vazia\n");
        return;
    }
    f->primeiro = (f->primeiro + 1) % MAX_TAM;
    f->tamanho--;
}

void imprimeFila(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Erro: a fila esta vazia\n");
        return;
    }
    int i = f->primeiro;
    for (int j = 0; j < f->tamanho; j++) {
        printf("Chave: %d\n", f->vetItem[i].chave);
        i = (i + 1) % MAX_TAM;
    }
}

void liberaFila(Fila *f) {
    free(f);
}
