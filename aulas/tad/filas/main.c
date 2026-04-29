#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item_fila.h"


int main() {
    Fila *f = criaFilavazia();
    printf("Enfileirando 5 itens: \n");
    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    enfileira(f, 4);
    enfileira(f, 5);
    
    printf("\nTentando enfileirar o sexto item:\n");
    enfileira(f, 6);
    imprimeFila(f);
    printf("\nDesenfileirando:\n");
    desenfileira(f);
    desenfileira(f);
    imprimeFila(f);
    liberaFila(f);
    return 0;
}