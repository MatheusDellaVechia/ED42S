#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item_pilha.h"


struct item {
    int chave;
};

struct pilha {
    Item vetItem[MAX_TAM];
    int topo;
};

Pilha *criaPilhavazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int verificaPilhaCheia(Pilha *p) {
    return (p->topo == MAX_TAM - 1);
}

int verificaPilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

void empilha(Pilha *p, int chave) {
    if (verificaPilhaCheia(p)) {
        printf("Erro: a pilha esta cheia\n");
        return;
    }
    Item  novoItem;
    novoItem.chave = chave;
    p->topo++;
    p->vetItem[p->topo].chave = chave;
}

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: a pilha esta vazia\n");
        return;
    }
    p->topo--;
}

void imprimePilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: a pilha esta vazia\n");
        return;
    }
    
    for (int i =  0; i <= p->topo; i++) {
        printf("Chave: %d\n", p->vetItem[i].chave);
    }
}

void liberaPilha(Pilha *p) {
    free(p);
}