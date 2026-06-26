#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marketplace.h"

struct item
{
    int chave;
    char nome[50];
    char categoria[30];
    char vendedor[30];
    float preco;
};

struct fila
{
    Item vetItem[MAX_TAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Item *insereProduto(Item *vet, int qtd, int chave, char nome[], char categoria[], char vendedor[], float preco)
{
    if (qtd == 0)
    {
        vet = (Item *)malloc(sizeof(Item));
    }
    else
    {
        vet = (Item *)realloc(vet, (qtd + 1) * sizeof(Item));
    }

    vet[qtd].chave = chave;
    strcpy(vet[qtd].nome, nome);
    strcpy(vet[qtd].categoria, categoria);
    strcpy(vet[qtd].vendedor, vendedor);
    vet[qtd].preco = preco;
    return vet;
}

void troca(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(Item *vet, int inicio, int fim)
{
    char pivo[50];
    strcpy(pivo, vet[fim].nome);
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (strcmp(vet[j].nome, pivo) <= 0)
        {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }
    troca(&vet[i + 1], &vet[fim]);
    return i + 1;
}

void quicksort(Item *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int p = particiona(vet, inicio, fim);
        quicksort(vet, inicio, p - 1);
        quicksort(vet, p + 1, fim);
    }
}

void ordenaPorNome(Item *vet, int qtd)
{
    quicksort(vet, 0, qtd - 1);
}

int pesquisaBinariaPorNome(Item *vet, int qtd, char nome[])
{
    int inicio = 0, fim = qtd - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(nome, vet[meio].nome);

        if (cmp == 0)
        {
            return meio;
        }
        else if (cmp < 0)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1;
}

void imprimeItem(Item item)
{
    printf("Chave: %d\n", item.chave);
    printf("Produto: %s\n", item.nome);
    printf("Categoria: %s\n", item.categoria);
    printf("Vendedor: %s\n", item.vendedor);
    printf("Preco: R$ %.2f\n", item.preco);
    printf("--------------------------\n");
}

void imprimeVetor(Item *vet, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        imprimeItem(vet[i]);
    }
}

void liberaVetor(Item *vet)
{
    free(vet);
}

Fila *criaFilaVazia()
{
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

int verificaFilaCheia(Fila *f)
{
    return (f->tamanho == MAX_TAM);
}

int verificaFilaVazia(Fila *f)
{
    return (f->tamanho == 0);
}

void enfileira(Fila *f, Item item)
{
    if (verificaFilaCheia(f))
    {
        printf("Erro: a fila esta cheia\n");
        return;
    }
    f->vetItem[f->ultimo] = item;
    f->ultimo = (f->ultimo + 1) % MAX_TAM;
    f->tamanho++;
}

void preencheFila(Fila *f, Item *vet, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        enfileira(f, vet[i]);
    }
}

void imprimeFila(Fila *f)
{
    if (verificaFilaVazia(f))
    {
        printf("Erro: a fila esta vazia\n");
        return;
    }
    int i = f->primeiro;
    for (int j = 0; j < f->tamanho; j++)
    {
        imprimeItem(f->vetItem[i]);
        i = (i + 1) % MAX_TAM;
    }
}

void liberaFila(Fila *f)
{
    free(f);
}
