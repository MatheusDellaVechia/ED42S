#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doadores.h"

struct item
{
    int chave;
    char nome[50];
    char documento[20];
    char contato[20];
    char tipoSanguineo[5];
};

struct fila
{
    Item vetItem[MAX_TAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Item *insereDoador(Item *vet, int qtd, int chave, char nome[], char documento[], char contato[], char tipoSanguineo[])
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
    strcpy(vet[qtd].documento, documento);
    strcpy(vet[qtd].contato, contato);
    strcpy(vet[qtd].tipoSanguineo, tipoSanguineo);
    return vet;
}

int separa(Item vetor[], int posicaoInicio, int posicaoFim)
{
    Item pivo = vetor[posicaoFim];
    int esquerda = posicaoInicio;
    int atual;
    Item aux;
    for (atual = posicaoInicio; atual < posicaoFim; atual++)
    {
        if (strcmp(vetor[atual].nome, pivo.nome) <= 0)
        {
            aux = vetor[atual];
            vetor[atual] = vetor[esquerda];
            vetor[esquerda] = aux;
            esquerda++;
        }
    }
    aux = vetor[esquerda];
    vetor[esquerda] = vetor[posicaoFim];
    vetor[posicaoFim] = aux;
    return esquerda;
}

void quickSort(Item vetor[], int posicaoInicio, int posicaoFim)
{
    if (posicaoInicio < posicaoFim)
    {
        int metade = separa(vetor, posicaoInicio, posicaoFim);
        quickSort(vetor, posicaoInicio, metade - 1);
        quickSort(vetor, metade + 1, posicaoFim);
    }
}

int pesquisaBinaria(Item v[], int n, char chave[])
{
    int primeiro = 0;
    int ultimo = n - 1;
    int meio;
    while (primeiro <= ultimo)
    {
        meio = (primeiro + ultimo) / 2;
        if (strcmp(v[meio].nome, chave) == 0)
        {
            return meio;
        }
        else if (strcmp(v[meio].nome, chave) > 0)
        {
            ultimo = meio - 1;
        }
        else
        {
            primeiro = meio + 1;
        }
    }
    return -1;
}

void imprimeItem(Item item)
{
    printf("Chave: %d\n", item.chave);
    printf("Nome: %s\n", item.nome);
    printf("Documento: %s\n", item.documento);
    printf("Contato: %s\n", item.contato);
    printf("Tipo Sanguineo: %s\n", item.tipoSanguineo);
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
