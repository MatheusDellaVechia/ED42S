#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fatorial(int n) {
    int fat = n;
    for (int i = n - 1; i > 0; i--) {
        fat *= i;
    }
    return fat;
}

int fatorialRecursivo(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatorialRecursivo(n - 1);
}

int main() {

    int n = 20;
    int iteracoes = 1000000;
    clock_t inicio, fim;
    double tempo_iterativo, tempo_recursivo;
    
    inicio = clock();
    for (int i = 0; i < iteracoes; i++) {
        fatorial(n);
    }
    fim = clock();
    tempo_iterativo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    

    inicio = clock();
    for (int i = 0; i < iteracoes; i++) {
        fatorialRecursivo(n);
    }
    fim = clock();
    tempo_recursivo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Fatorial iterativo:  %.6f segundos\n", tempo_iterativo);
    printf("Fatorial recursivo:  %.6f segundos\n", tempo_recursivo);
    printf("Diferença: %.6f segundos\n", tempo_recursivo - tempo_iterativo);

    return 0;
}