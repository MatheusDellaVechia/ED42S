#include <stdio.h>
#include <stdlib.h>

typedef struct instrumento
{
    char modelo[30];
    char marca[100];
    float preco;
} Instrumento;

int main()
{

    Instrumento instrumentos[5];
    int i = 0;
    for (int i = 0; i < 3; i++)
    {
        setbuf(stdin, NULL);
        printf("Digite o modelo do instrumento %d: ", i + 1);
        scanf("%[^\n]s", instrumentos[i].modelo);
        setbuf(stdin, NULL);

        printf("Digite a marca do instrumento %d: ", i + 1);
        scanf("%[^\n]s", instrumentos[i].marca);
        setbuf(stdin, NULL);

        printf("Digite o preço do instrumento %d: ", i + 1);
        scanf("%f", &instrumentos[i].preco);

    }
        int p = 1;
        do
        {
            printf("Informe o valor de limite de preços dos instrumentos: ");
            scanf("%d", &p);

            for(int i = 0; i < 3; i ++) {
                if (instrumentos[i].preco <= p) {
                    printf("Marca instrumento: %s\n", instrumentos[i].marca);
                    printf("Modelo instrumento: %s\n", instrumentos[i].modelo);
                }

            }

            printf("Deseja ler outro valor? [1] S [0] N: ");
            scanf("%d", &p);

        } while (p > 0);

    return 0;
}
