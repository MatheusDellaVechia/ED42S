#ifndef ITEM_PILHA_H_INCLUDED
#define ITEM_PILHA_H_INCLUDED
#define MAX_TAM 5

typedef struct pilha Pilha;
typedef struct item Item;


Pilha *criaPilhavazia();
int verificaPilhaCheia(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void empilha(Pilha *p, int chave);
void desempilha(Pilha *p);
void imprimePilha(Pilha *p);
void liberaPilha(Pilha *p);

#endif