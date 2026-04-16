#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ong.h"

int main()
{
    Data *dataNascimento;
    PetsMatheus *pets = NULL;
    int quantidadePets = 0, continuarNovoPet = 0, visualizarTodos = 0, visualizarMes = 0, visualizarMesNaoAdotados = 0;

    printf("------ONG Solidária para PETS---------\n");

    do
    {
        char nome[50], raca[50], sexo;
        float peso;
        int dia, mes, ano, jaAdotado;

        printf("Informe o nome do pet: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Informe a raça do pet: ");
        scanf("%[^\n]s", raca);
        setbuf(stdin, NULL);

        printf("Informe o sexo do pet (M/F): ");
        scanf("%c", &sexo);
        setbuf(stdin, NULL);

        printf("Informe o peso do pet: ");
        scanf("%f", &peso);
        setbuf(stdin, NULL);

        printf("O pet já foi adotado ? [1] Sim [0] Não: ");
        scanf("%d", &jaAdotado);
        setbuf(stdin, NULL);

        printf("Informe a data de nascimento do pet (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        setbuf(stdin, NULL);

        dataNascimento = criarData(dia, mes, ano);
        pets = novoPet(pets, dataNascimento, quantidadePets, nome, raca, sexo, peso, jaAdotado);
        quantidadePets++;
        printf("\n");
        printf("-----------------------------\n");
        printf("Deseja cadastrar outro pet ? [1] S [0] N: ");
        scanf("%d", &continuarNovoPet);
        setbuf(stdin, NULL);

    } while (continuarNovoPet);

    do
    {
        printf("Deseja visualizar os pets por um mes de nascimento especifico ? [1] S [0] N: ");
        scanf("%d", &visualizarMes);
        setbuf(stdin, NULL);
        if (!visualizarMes)
        {
            break;
        }
        int mesFiltro;
        printf("Informe o mês para filtrar os pets: ");
        scanf("%d", &mesFiltro);
        setbuf(stdin, NULL);
        printf("\n-----------------------------\n");
        imprimePetPorMes(mesFiltro, pets, quantidadePets);
    } while (visualizarMes);

    do
    {

        printf("Deseja visualizar os pets por um mes de nascimento especifico e que não foram adotados ? [1] S [0] N: ");
        scanf("%d", &visualizarMesNaoAdotados);
        setbuf(stdin, NULL);
        if (!visualizarMesNaoAdotados)
        {
            break;
        }
        int mesFiltro;
        printf("Informe o mês para filtrar os pets: ");
        scanf("%d", &mesFiltro);
        setbuf(stdin, NULL);
        printf("\n-----------------------------\n");
        imprimePetPorMesNaoAdotados(mesFiltro, pets, quantidadePets);

    } while (visualizarMesNaoAdotados);

    do
    {

        printf("Deseja visualizar todos os pets cadastrados ? [1] S [0] N: ");
        scanf("%d", &visualizarTodos);
        setbuf(stdin, NULL);
        if (!visualizarTodos)
        {
            break;
        }
        printf("\n-----------------------------\n");
        imprimePet(pets, quantidadePets);
    } while (visualizarTodos);

    liberaPets(pets, quantidadePets);
}