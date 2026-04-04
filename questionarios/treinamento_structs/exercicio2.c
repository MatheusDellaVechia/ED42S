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
    int limite = 5;
    for (int i = 0; i < limite; i++) {
        printf("Digite o modelo do instrumento %d: ", i + 1);
        scanf("%[^\n]s", instrumentos[i].modelo);
        setbuf(stdin, NULL);

        printf("Digite a marca do instrumento %d: ", i + 1);
        scanf("%[^\n]s", instrumentos[i].marca);
        setbuf(stdin, NULL);

        printf("Digite o preço do instrumento %d: ", i + 1);
        scanf("%f", &instrumentos[i].preco);
        setbuf(stdin, NULL);

    }

    float p;

    do
    {
        printf("Informe o valor de limite de preços dos instrumentos(0 para sair): ");
        scanf("%f", &p);

        if (p == 0) {
            break;
        }

        for(int i = 0; i < limite; i ++) {

            if (instrumentos[i].preco <= p) {
                printf("Marca instrumento: %s\n", instrumentos[i].marca);
                printf("Modelo instrumento: %s\n", instrumentos[i].modelo);
                printf("Preco instrumento: %.2f\n", instrumentos[i].preco);

            }

        }

    } while (p != 0);

    return 0;
}
