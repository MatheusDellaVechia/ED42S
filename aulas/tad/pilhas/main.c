#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item_pilha.h"

int main() {

    Pilha *p = criaPilhavazia();
    printf("Empilhando 5 itens.\n");
    empilha(p, 1);
    empilha(p, 2);
    empilha(p, 3);
    empilha(p, 4);
    empilha(p, 5);

    printf("\nTentando empilhar o sexto item.\n");
    empilha(p, 6);

    imprimePilha(p);
    printf("\nDesempilhando:\n");
    desempilha(p);
    imprimePilha(p);
    liberaPilha(p);

    return 0;
}