#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doadores.h"

int main()
{
    Item *doadores = NULL;
    int quantidade = 0, continuar = 0;

    printf("-----Controle de Doadores de Sangue -----\n");

    do
    {
        char nome[50], documento[20], contato[20], tipoSanguineo[5];

        printf("\nInforme o nome do doador: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Informe o documento de identificacao: ");
        scanf("%[^\n]s", documento);
        setbuf(stdin, NULL);

        printf("Informe o contato: ");
        scanf("%[^\n]s", contato);
        setbuf(stdin, NULL);

        printf("Informe o tipo sanguineo (ex: A+, O-): ");
        scanf("%[^\n]s", tipoSanguineo);
        setbuf(stdin, NULL);

        doadores = insereDoador(doadores, quantidade, quantidade + 1, nome, documento, contato, tipoSanguineo);
        quantidade++;

        printf("-----------------------------\n");
        printf("Deseja cadastrar outro doador? [1] Sim [0] Nao: ");
        scanf("%d", &continuar);
        setbuf(stdin, NULL);
    } while (continuar);

    if (quantidade == 0)
    {
        printf("\nNenhum doador cadastrado. Encerrando.\n");
        return 0;
    }

    quickSort(doadores, 0, quantidade - 1);
    printf("\n===== Doadores ordenados por nome =====\n");
    imprimeVetor(doadores, quantidade);

    char busca[50];
    printf("Informe o nome do doador a ser pesquisado: ");
    scanf("%[^\n]s", busca);
    setbuf(stdin, NULL);

    int posicao = pesquisaBinaria(doadores, quantidade, busca);
    if (posicao != -1)
    {
        printf("Doador \"%s\" encontrado na posicao %d do vetor.\n", busca, posicao);
    }
    else
    {
        printf("Doador \"%s\" nao foi encontrado.\n", busca);
    }

    Fila *fila = criaFilaVazia();
    preencheFila(fila, doadores, quantidade);

    printf("\n===== Doadores na Fila =====\n");
    imprimeFila(fila);

    liberaFila(fila);
    liberaVetor(doadores);
    return 0;
}
