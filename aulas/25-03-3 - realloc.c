#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *vet;
    int num = 5;
    vet = (int *)malloc(num * sizeof(int));

    if (vet)
    {

        int i;
        for (i = 0; i < num; i++)
        {
            vet[i] = i +1;
            printf("%d\n", vet[i]);

        }

        printf("\n");
        num = 3;
        vet = realloc(vet, num * sizeof(int));

        for (i = 0; i < num; i++)
        {
            printf("%d\n", vet[i]);
        }

        printf("\n");
        num = 10;
        vet = realloc(vet, num * sizeof(int));

        for (i = 0; i < num; i++)
        {
            printf("%d\n", vet[i]);
        }
    }
    free(vet);

    return 0;
}