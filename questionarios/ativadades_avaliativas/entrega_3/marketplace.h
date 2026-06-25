#ifndef MARKETPLACE_H_INCLUDED
#define MARKETPLACE_H_INCLUDED
#define MAX_TAM 100

typedef struct item Item;
typedef struct fila Fila;

Item *insereProduto(Item *vet, int qtd, int chave, char nome[], char categoria[], char vendedor[], float preco);
void ordenaPorNome(Item *vet, int qtd);
int pesquisaBinariaPorNome(Item *vet, int qtd, char nome[]);
void imprimeVetor(Item *vet, int qtd);
void liberaVetor(Item *vet);

Fila *criaFilaVazia();
int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);
void enfileira(Fila *f, Item item);
void preencheFila(Fila *f, Item *vet, int qtd);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);

#endif
