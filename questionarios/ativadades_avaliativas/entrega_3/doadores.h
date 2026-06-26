#ifndef DOADORES_H_INCLUDED
#define DOADORES_H_INCLUDED
#define MAX_TAM 100

typedef struct item Item;
typedef struct fila Fila;

Item *insereDoador(Item *vet, int qtd, int chave, char nome[], char documento[], char contato[], char tipoSanguineo[]);
void quickSort(Item *vetor, int posicaoInicio, int posicaoFim);
int pesquisaBinaria(Item *v, int n, char chave[]);
void imprimeVetor(Item *vet, int qtd);
void liberaVetor(Item *vet);

Fila *criaFilaVazia();
void preencheFila(Fila *f, Item *vet, int qtd);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);

#endif
