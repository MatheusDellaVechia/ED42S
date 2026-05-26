#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logistica.h"

int main(void) {
    Fila *f = criaFilaVazia();
    int opcao = 0;
    Pacote p;
    char codBase[20];
    char cidadeBusca[50];

    do {
        printf("\n--- LOGISTICA DE PACOTES ---\n");
        printf("1. Inserir Pacote\n");
        printf("2. Excluir/Despachar Pacote\n");
        printf("3. Buscar Pacote (por Cidade)\n");
        printf("4. Imprimir Todos (Iterativo)\n");
        printf("5. Imprimir Todos (Recursivo)\n");
        printf("6. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Codigo Base (sem digito): ");
                scanf("%[^\n]s", codBase); getchar();
                printf("Peso (kg): ");
                scanf("%f", &p.peso); getchar();
                printf("Cidade Destino: ");
                scanf("%[^\n]s", p.cidadeDestino); getchar();
                printf("Remetente: ");
                scanf("%[^\n]s", p.remetente); getchar();
                printf("Valor (R$): ");
                scanf("%f", &p.valor); getchar();
                
                enfileiraPacote(f, p, codBase);
                break;
            case 2:
                desenfileiraPacote(f);
                break;
            case 3:
                printf("Informe a Cidade de Destino: ");
                scanf("%[^\n]s", cidadeBusca); getchar();
                buscaPorCidade(f, cidadeBusca);
                break;
            case 4:
                printf("\n--- Imprimindo Fila (Iterativo) ---\n");
                imprimeFila(f);
                break;
            case 5:
                printf("\n--- Imprimindo Fila (Recursivo) ---\n");
                if (verificaFilaVazia(f)) {
                    printf("Fila vazia.\n");
                } else {
                    imprimeFilaRecursivo(f, f->primeiro, 0);
                }
                break;
            case 6:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

    liberaFila(f);
    return 0;
}