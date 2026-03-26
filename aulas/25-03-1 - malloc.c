#include <stdio.h>
#include <stdlib.h>


int main() {

    int *vet;
    int num;

    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &num);
    vet = (int *) malloc(num * sizeof(int));

    if (vet == NULL) {
        printf("Erro ao alocar memoria");
        return 1;
    }

    int i;
    for (i = 0; i < num; i++) {
        printf("\nDigite o valor da posicao %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < num; i++) {
        printf("\nValor da posicao %d: %d \n2", i, vet[i]);
    }

    free(vet);
    return 0;
}