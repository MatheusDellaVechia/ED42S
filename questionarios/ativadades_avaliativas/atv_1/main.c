#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assinaturas.h"

int main()
{
    char nome[30];
    int dia, mes, ano;
    char descricao[30];
    float valor;

    Contratante *contratante = NULL;
    Servico *servicos = NULL;
    Data *dataNascimento;

    int outroServico, outroContratante, quantidadeServicos = 0, quantidadeContratantes = 0;

    printf("####################################################\n");
    printf("Gestao de Streamings\n");
    printf("####################################################\n");

    do
    {
        printf("Informe o nome do contratante %d: ", quantidadeContratantes);
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Data de nascimento(dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        setbuf(stdin, NULL);

        dataNascimento = novaData(dia, mes, ano);
        quantidadeServicos = 0;
        do
        {
            printf("Informe o nome do servico contratado [%d]: ", quantidadeServicos + 1);
            scanf("%[^\n]s", descricao);
            setbuf(stdin, NULL);

            printf("Valor do servico: ");
            scanf("%f", &valor);
            servicos = novoServico(servicos, descricao, valor, quantidadeServicos);
            quantidadeServicos++;


            printf("Deseja informar outro servico para o contratante ? [1] S [0] N: ");
            scanf("%d", &outroServico);
            setbuf(stdin, NULL);
        } while (outroServico);

        contratante = novoContratante(contratante, nome, quantidadeContratantes, quantidadeServicos, servicos, dataNascimento);
        quantidadeContratantes++;
        printf("Informar outro contratante ? [1] S [0] N: ");
        scanf("%d", &outroContratante);
        setbuf(stdin, NULL);
    } while (outroContratante);

    printf("####################################################\n");
    printf("Dados cadastrados\n");
    printf("####################################################\n\n");

    imprimeContratantes(contratante, quantidadeContratantes);
    freeContratante(contratante);

}