#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

typedef struct pessoa Pessoa;

Pessoa *inserePessoas(Pessoa *vet, char nome[], int idade, int numeroPessoas);

void imprimePessoas(Pessoa *vet, int nPessoas);

void liberaVetorPessoas(Pessoa *vetPessoas);

#endif