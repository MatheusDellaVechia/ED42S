#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashArena.h"

void limpaBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Hash *h = cria_tabela();
    int opcao = -1;

    printf("=========================================\n");
    printf("            ARENA DE MONSTROS            \n");
    printf("=========================================\n");

    do {
         printf("\n----- MENU -----\n");
        printf("1 - Cadastrar monstro\n");
        printf("2 - Buscar monstro por nome\n");
        printf("3 - Batalhar\n");
        printf("4 - Listar tabela hash\n");
        printf("5 - Remover monstro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        if(scanf("%d", &opcao) != 1) {
            limpaBuffer();
            printf("Opcao invalida. Digite um numero.\n");
            continue;
        }
        limpaBuffer();

        if(opcao == 1) {
            char nome[30], tipo[20];
            int poder = 0, vida = 0;

            printf("Nome do monstro: ");
            scanf(" %[^\n]", nome);
            limpaBuffer();

            printf("Tipo (ex: Fogo, Agua, Terra): ");
            scanf(" %[^\n]", tipo);
            limpaBuffer();

            printf("Poder: ");
            if(scanf("%d", &poder) != 1) {
                limpaBuffer();
                printf("Poder invalido. Cadastro cancelado.\n");
                continue;
            }
            limpaBuffer();

            printf("Vida: ");
            if(scanf("%d", &vida) != 1) {
                limpaBuffer();
                printf("Vida invalida. Cadastro cancelado.\n");
                continue;
            }
            limpaBuffer();

            insere_tratamento_lista_encadeada(h, nome, tipo, poder, vida);
            printf("Monstro %s adicionado na posicao %d da tabela!\n", nome, hashing_string(nome));
        }
        else if(opcao == 2) {
            char nome[30];
            printf("Nome do monstro a buscar: ");
            scanf(" %[^\n]", nome);
            limpaBuffer();

            Item *encontrado = busca_tratamento_lista_encadeada(h, nome);
            if(encontrado != NULL) {
                printf("Encontrado na posicao %d:\n", hashing_string(nome));
                imprime_item(encontrado);
            }
            else {
                printf("Monstro %s nao esta na arena.\n", nome);
            }
        }
        else if(opcao == 3) {
            char nome1[30], nome2[30];
            printf("Nome do primeiro monstro: ");
            scanf(" %[^\n]", nome1);
            limpaBuffer();

            printf("Nome do segundo monstro: ");
            scanf(" %[^\n]", nome2);
            limpaBuffer();

            batalha(h, nome1, nome2);
        }
        else if(opcao == 4) {
            if(verifica_tabela_vazia(h))
                printf("A arena esta vazia.\n");
            else
                imprime_tabela(h);
        }
        else if(opcao == 5) {
            char nome[30];
            printf("Nome do monstro a remover: ");
            scanf(" %[^\n]", nome);
            limpaBuffer();

            remove_tratamento_lista_encadeada(h, nome);
        }
    } while(opcao != 0);

    libera_tabela(h);
    printf("Ate a proxima batalha!\n");
    return 0;
}
