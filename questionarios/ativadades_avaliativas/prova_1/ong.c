#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ong.h"

struct data
{
    int dia;
    int mes;
    int ano;
};

struct petsMatheus
{
    char nome[50];
    char raca[50];
    char sexo;
    float peso;
    Data *dataNascimento;
    int jaAdotado;
};

PetsMatheus *novoPet(PetsMatheus *vet, Data *dataNascimento, int quantidadePets, char nome[], char raca[], char sexo, float peso, int jaAdotado) 
{
    if (quantidadePets == 0)
    {
        vet = (PetsMatheus *)malloc(sizeof(PetsMatheus));
    }
    else
    {
        vet = (PetsMatheus *)realloc(vet, (quantidadePets + 1) * sizeof(PetsMatheus));
    }

    strcpy(vet[quantidadePets].nome, nome);
    strcpy(vet[quantidadePets].raca, raca);
    vet[quantidadePets].sexo = sexo;
    vet[quantidadePets].peso = peso;
    vet[quantidadePets].dataNascimento = dataNascimento;
    vet[quantidadePets].jaAdotado = jaAdotado;
    return vet;
}

void imprimePet(PetsMatheus *pet, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nome: %s\n", pet[i].nome);
        printf("Raça: %s\n", pet[i].raca);
        printf("Sexo: %c\n", pet[i].sexo);
        printf("Peso: %.2f kg\n", pet[i].peso);
        printf("Data de Nascimento: ");
        imprimirData(pet[i].dataNascimento);
        printf("Já Adotado: %s\n", pet[i].jaAdotado ? "Sim" : "Não");
        printf("--------------------------\n");
    }
}

void imprimePetPorMes(int mes, PetsMatheus *pet, int quantidade)
{
    printf("Pets nascidos no mês %d:\n", mes);
    for (int i = 0; i < quantidade; i++)
    {
        if (pet[i].dataNascimento->mes == mes)
        {
            imprimePet(&pet[i], 1);
        }
    }
}

void imprimePetPorMesNaoAdotados(int mes, PetsMatheus *pet, int quantidade)
{
    printf("Pets nascidos no mês %d e ainda não adotados:\n", mes);
    for (int i = 0; i < quantidade; i++)
    {
        if (pet[i].dataNascimento->mes == mes && !pet[i].jaAdotado)
        {
            imprimePetPorMes(mes, &pet[i], 1);
        }
    }
}


void liberaPets(PetsMatheus *pets, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        liberarData(pets[i].dataNascimento);
    }
    free(pets);
}

Data *criarData(int dia, int mes, int ano)
{
    Data *data = (Data *)malloc(sizeof(Data));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

void imprimirData(Data *data)
{
    printf("%02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

void liberarData(Data *data)
{
    free(data);
}
