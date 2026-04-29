#ifndef ITEM_FILA_H_INCLUDED
#define ITEM_FILA_H_INCLUDED
#define MAX_TAM 5

typedef struct fila Fila;
typedef struct item Item;


Fila *criaFilavazia();
int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);
void enfileira(Fila *f, int chave);
void desenfileira(Fila *f);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);

#endif