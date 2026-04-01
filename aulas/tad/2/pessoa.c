#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

typedef struct pessoa  {
    char nome[30];
    int idade;
} Pessoa;

Pessoa *inserePessoas(Pessoa *vet, char nome[], int idade, int numeroPessoas) {
    if (numeroPessoas == 0) {
        vet = (Pessoa * ) malloc(sizeof(Pessoa));
    } else {
        vet = (Pessoa *) realloc(vet, (numeroPessoas + 1) * sizeof(Pessoa));
    }
    strcpy(vet[numeroPessoas].nome, nome);
    vet[numeroPessoas].idade = idade;
    return vet;
}

void imprimePessoas(Pessoa *vet, int nPessoas) {
    for (int i = 0; i <= nPessoas; i ++) {
        printf("%s - %d\n", vet[i].nome, vet[i].idade);
    }
}

void liberaVetorPessoas(Pessoa *vetPessoas) {
    free(vetPessoas);
}