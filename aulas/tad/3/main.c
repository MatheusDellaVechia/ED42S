#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "22-04.h"

int main() {

    Lista *lista = NULL;
    int vazia, cheia, chave;

    printf("Criando lista vazia. \n");
    lista = criaListaVazia();

    vazia = verificaListaVazia(lista);
    printf("Lista vazia ? %d\n", vazia);

    cheia = verificaListaCheia(lista);
    printf("Lista cheia ? %d\n", cheia);

    printf("\nAdicionando o primeiro item.\n");
    chave = 1;
    adicionaItemFimLista(lista, chave);
    vazia = verificaListaVazia(lista);
    printf("Lista vazia ? %d\n", vazia);

    printf("\nAdicionando o segundo item.\n");
    chave = 2;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o terceiro item.\n");
    chave = 3;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o quarto item.\n");
    chave = 4;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o quinto item.\n");
    chave = 5;
    adicionaItemFimLista(lista, chave);

    cheia = verificaListaCheia(lista);
    printf("Lista cheia ? %d\n", cheia);

    printf("\nAdicionando o sexto item.\n");
    chave = 6;
    adicionaItemFimLista(lista, chave);

    printf("\nItens da lista:\n");
    imprimeLista(lista);

    printf("Posicao do item com chave 2: %d\n", 
    buscaItemPorChave(lista, 2));


    printf("\nPosicao do item com chave 4: %d\n", 
    buscaItemPorChave(lista, 4));

    printf("\nPosicao do item com chave 6: %d\n", 
    buscaItemPorChave(lista, 6));

    printf("\nTentando remover item com chave 6.\n");
    
    removeItem(lista, 3);
    

    printf("\nItens da lista após remoção:\n");
    imprimeLista(lista);
    
    removeItem(lista, 6);


    liberaLista(lista);


    return 0;
}