#include <stdio.h>
#include <stdlib.h>

typedef struct dosesVacina
{
    char nomePaciente[30];
    char cidade[30];
    int idade;

} DosesVacina;

int main()
{

    DosesVacina doses[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o nome do paciente %d :", i + 1);
        scanf("%[^\n]s", doses[i].nomePaciente);
        setbuf(stdin, NULL);

        printf("Digite a cidade do paciente %d :", i + 1);
        scanf("%[^\n]s", doses[i].cidade);
        setbuf(stdin, NULL);

        printf("Digite a idade do paciente %d :", i + 1);
        scanf("%d", &doses[i].idade);
        setbuf(stdin, NULL);
    }

    printf("-------Doses de Vacina:----------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Nome: %s\n", doses[i].nomePaciente);
        printf("Cidade: %s\n", doses[i].cidade);
        printf("Idade: %d\n", doses[i].idade);
    }

    return 0;
}