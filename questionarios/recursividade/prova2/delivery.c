#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery.h"

struct matheusPedido {
    char nomeCliente[50];
    float preco;
    int tempoEntrega;
    char nomePedido[100];
};

struct fila {
    MatheusPedido *itens[MAX]; 
    int inicio;
    int fim;
    int total;
};

MatheusPedido *novoPedido(char nomeCliente[], char nomePedido[], float preco, int tempoEntrega) {
    MatheusPedido *p = (MatheusPedido *)malloc(sizeof(MatheusPedido));
    if (p != NULL) {
        strcpy(p->nomeCliente, nomeCliente);
        strcpy(p->nomePedido, nomePedido);
        p->preco = preco;
        p->tempoEntrega = tempoEntrega;
    }
    return p;
}

void imprimePedido(MatheusPedido *p) {
    if (p != NULL) {
        printf("  Cliente: %s\n", p->nomeCliente);
        printf("  Pedido: %s\n", p->nomePedido);
        printf("  Preco: R$%.2f\n", p->preco);
        printf("  Tempo: %d min\n", p->tempoEntrega);
    }
}

void freePedido(MatheusPedido *p) {
    if (p != NULL) {
        free(p);
    }
}

Fila *criaFila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = 0;
        f->fim = -1;
        f->total = 0;
    }
    return f;
}

int inserirFim(Fila *f, MatheusPedido *p) {
    if (f->total == MAX) {
        return 0;
    }
    f->fim = (f->fim + 1) % MAX;
    f->itens[f->fim] = p;
    f->total++;
    return 1;
}

int removerInicio(Fila *f, MatheusPedido **p) {
    if (f->total == 0) {
        return 0;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return 1;
}

void imprimeFila(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia.\n");
        return;
    }
    printf("--- Lista de Pedidos ---\n");
    for (int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("Pedido #%d:\n", i + 1);
        imprimePedido(f->itens[idx]);
    }
}

void freeFila(Fila *f) {
    if (f != NULL) {
        for (int i = 0; i < f->total; i++) {
            int idx = (f->inicio + i) % MAX;
            freePedido(f->itens[idx]);
        }
        free(f);
    }
}

int contarPedidosFiltrados(Fila *f, float precoMinimo, int index) {
    if (index >= f->total) {
        return 0;
    }
    
    int idx = (f->inicio + index) % MAX;
    int count = (f->itens[idx]->preco > precoMinimo) ? 1 : 0;
    
    return count + contarPedidosFiltrados(f, precoMinimo, index + 1);
}
