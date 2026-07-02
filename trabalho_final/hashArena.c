#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashArena.h"

struct item {
    char nome[30];
    char tipo[20];
    int poder;
    int vida;
};

struct celula {
    Item item;
    Celula *prox;
};

struct hash {
    int quantidade;
    Celula **celulas;
};

Hash *cria_tabela() {
    int i;
    Hash *h = malloc(sizeof(Hash));
    h->quantidade = 0;
    h->celulas = malloc(TABLESIZE * sizeof(Celula*));
    for(i = 0; i < TABLESIZE; i++)
        h->celulas[i] = NULL;
    return h;
}

void libera_tabela(Hash *h) {
    int i;
    Celula *aux, *remover;
    for(i = 0; i < TABLESIZE; i++) {
        aux = h->celulas[i];
        while(aux != NULL) {
            remover = aux;
            aux = aux->prox;
            free(remover);
        }
    }
    free(h->celulas);
    free(h);
}

//Nova função
int hashing_string(char chave[]) {
    int i;
    unsigned long soma = 0;
    for(i = 0; chave[i] != '\0'; i++)
        soma = soma * 31 + chave[i];
    return soma % TABLESIZE;
}

int verifica_tabela_vazia(Hash *h) {
    return h->quantidade == 0;
}

void imprime_item(Item *item) {
    if(item != NULL)
        printf("Nome: %s | Tipo: %s | Poder: %d | Vida: %d\n", item->nome, item->tipo, item->poder, item->vida);
    else
        printf("Monstro nao existe.\n");
}

void imprime_tabela(Hash *h) {
    int i;
    for(i = 0; i < TABLESIZE; i++) {
        printf("Pos %d: ", i);
        if(h->celulas[i] == NULL) {
            printf("NULL");
        }
        else {
            Celula *aux = h->celulas[i];
            while(aux != NULL) {
                printf("[%s] ", aux->item.nome);
                aux = aux->prox;
            }
        }
        printf("\n");
    }
}

void insere_tratamento_lista_encadeada(Hash *h, char nome[], char tipo[], int poder, int vida) {
    int posicao = hashing_string(nome);
    Item item;
    strcpy(item.nome, nome);
    strcpy(item.tipo, tipo);
    item.poder = poder;
    item.vida = vida;
    Celula *aux = malloc(sizeof(Celula));
    aux->item = item;
    aux->prox = h->celulas[posicao];
    h->celulas[posicao] = aux;
    h->quantidade++;
}

Item *busca_tratamento_lista_encadeada(Hash *h, char nome[]) {
    int posicao = hashing_string(nome);
    if(h->celulas[posicao] == NULL)
        return NULL;
    Celula *aux = h->celulas[posicao];
    while(aux != NULL) {
        if(strcmp(aux->item.nome, nome) == 0)
            return &aux->item;
        aux = aux->prox;
    }
    return NULL;
}

void remove_tratamento_lista_encadeada(Hash *h, char nome[]) {
    int posicao = hashing_string(nome);
    if(h->celulas[posicao] == NULL) {
        printf("Monstro %s nao encontrado.\n", nome);
        return;
    }
    Celula *aux = h->celulas[posicao];
    if(strcmp(aux->item.nome, nome) == 0) {
        h->celulas[posicao] = aux->prox;
        h->quantidade--;
        free(aux);
        return;
    }
    Celula *anterior;
    while(aux != NULL && strcmp(aux->item.nome, nome) != 0) {
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL) {
        printf("Monstro %s nao encontrado.\n", nome);
    }
    else {
        anterior->prox = aux->prox;
        h->quantidade--;
        free(aux);
    }
}

void batalha(Hash *h, char nome1[], char nome2[]) {
    Item *m1 = busca_tratamento_lista_encadeada(h, nome1);
    Item *m2 = busca_tratamento_lista_encadeada(h, nome2);
    if(m1 == NULL || m2 == NULL) {
        printf("Um dos monstros nao foi encontrado na arena.\n");
        return;
    }
    printf("\n--- BATALHA ---\n");
    imprime_item(m1);
    imprime_item(m2);
    if(m1->poder > m2->poder)
        printf(">> Vencedor: %s!\n", m1->nome);
    else if(m2->poder > m1->poder)
        printf(">> Vencedor: %s!\n", m2->nome);
    else
        printf(">> Empate!\n");
}
