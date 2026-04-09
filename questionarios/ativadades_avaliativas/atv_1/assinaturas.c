#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assinaturas.h"

struct data
{
    int dia;
    int mes;
    int ano;
};

struct servico
{
    char descricao[50];
    float valor;
};

struct contratante
{
    char nome[30];
    int quantidadeServicos;
    Servico *servicos;
    Data *dataNascimento;
};

Data *novaData(int dia, int mes, int ano)
{
    Data *data = (Data *)malloc(sizeof(Data));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

Servico *novoServico(Servico *vet, char descricao[], float valor, int quantidadeServicos)
{
    if (quantidadeServicos == 0)
    {
        vet = (Servico *)malloc(sizeof(Servico));
    }
    else
    {
        vet = (Servico *)realloc(vet, (quantidadeServicos + 1) * sizeof(Servico));
    }
    strcpy(vet[quantidadeServicos].descricao, descricao);
    vet[quantidadeServicos].valor = valor;

    return vet;
}

Contratante *novoContratante(Contratante *vet, char nome[], int quantidadeContratantes, int quantidadeServicos, Servico *servicos, Data *dataNascimento)
{
    if (quantidadeContratantes == 0)
    {
        vet = (Contratante *)malloc(sizeof(Contratante));
    }
    else
    {
        vet = (Contratante *)realloc(vet, (quantidadeContratantes + 1) * sizeof(Contratante));
    }

    strcpy(vet[quantidadeContratantes].nome, nome);
    vet[quantidadeContratantes].quantidadeServicos = quantidadeServicos;
    vet[quantidadeContratantes].dataNascimento = dataNascimento;
    vet[quantidadeContratantes].servicos = servicos;
    return vet;
}

void imprimeData(Data *data)
{
    printf("%02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

void imprimeServico(Servico *servico)
{
    printf("Descricao: %s - Valor: %.2f\n", servico->descricao, servico->valor);
}

void imprimeContratante(Contratante *contratante)
{
    printf("Nome: %s\n", contratante->nome);
    printf("Data de Nascimento: ");
    imprimeData(contratante->dataNascimento);
    printf("Servicos contratados:\n");
    for (int i = 0; i < contratante->quantidadeServicos; i++)
    {   
        imprimeServico(&contratante->servicos[i]);
    }
}

void imprimeContratantes(Contratante *contratantes, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        imprimeContratante(&contratantes[i]);
        printf("\n");
    }
}

void freeData(Data *data)
{
    free(data);
}

void freeServico(Servico *servicos)
{
    free(servicos);
}

void freeContratante(Contratante *contratante)
{
    freeData(contratante->dataNascimento);
    freeServico(contratante->servicos);
    free(contratante);
}
