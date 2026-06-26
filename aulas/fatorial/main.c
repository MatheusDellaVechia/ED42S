#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime(int vetor[], int n) {
    for (int i = n - 1; i >= 0; i--) {

        printf("%d\t", vetor[i]);
    }
}

int imprimeRecursivo(int vetor[], int n) {
    if (n == 0) {
        return 1;
    }
    printf("%d\t", vetor[n - 1]);
    return imprimeRecursivo(vetor, n - 1);
}

int main()  {
    int n = 0;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int *vetor = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }

    imprime(vetor, n);
    printf("\n");
    imprimeRecursivo(vetor, n);
    return 0;
}



int fibonacci(int n) {
    int primeiro, segundo, proximo;
    primeiro = 0;
    segundo = 1;
    if (n == 0) {
        return primeiro;
    } else if (n == 1) {
        return segundo;
    }
    for (int i = 2; i <= n; i++) {
        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo; 
    }
    return proximo;

}