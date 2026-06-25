#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marketplace.h"

int main()
{
    Item *produtos = NULL;
    int quantidade = 0, continuar = 0;

    printf("----- Marketplace: Cadastro de Produtos -----\n");

    do
    {
        char nome[50], categoria[30], vendedor[30];
        float preco;

        printf("\nInforme o nome do produto: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Informe a categoria: ");
        scanf("%[^\n]s", categoria);
        setbuf(stdin, NULL);

        printf("Informe o vendedor: ");
        scanf("%[^\n]s", vendedor);
        setbuf(stdin, NULL);

        printf("Informe o preco: ");
        scanf("%f", &preco);
        setbuf(stdin, NULL);

        produtos = insereProduto(produtos, quantidade, quantidade + 1, nome, categoria, vendedor, preco);
        quantidade++;

        printf("-----------------------------\n");
        printf("Deseja cadastrar outro produto? [1] Sim [0] Nao: ");
        scanf("%d", &continuar);
        setbuf(stdin, NULL);
    } while (continuar);

    if (quantidade == 0)
    {
        printf("\nNenhum produto cadastrado. Encerrando.\n");
        return 0;
    }

    ordenaPorNome(produtos, quantidade);
    printf("\n===== Produtos ordenados por nome =====\n");
    imprimeVetor(produtos, quantidade);

    char busca[50];
    printf("Informe o nome do produto a ser pesquisado: ");
    scanf("%[^\n]s", busca);
    setbuf(stdin, NULL);

    int posicao = pesquisaBinariaPorNome(produtos, quantidade, busca);
    if (posicao != -1)
    {
        printf("Produto \"%s\" encontrado na posicao %d do vetor.\n", busca, posicao);
    }
    else
    {
        printf("Produto \"%s\" nao foi encontrado.\n", busca);
    }

    Fila *fila = criaFilaVazia();
    preencheFila(fila, produtos, quantidade);

    printf("\n===== Produtos na Fila =====\n");
    imprimeFila(fila);

    liberaFila(fila);
    liberaVetor(produtos);
    return 0;
}
