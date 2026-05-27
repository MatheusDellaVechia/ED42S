#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery.h"

//Descrição da roleta Corrigida: Utilize uma estrutura de dados estática que remove elementos somente do início do conjunto de dados e inclui no final.
//Na roleta estava "e remove do final".
int main() {
    Fila *minhaFila = criaFila();
    int opcao;
    char nomeC[50], nomeP[100];
    float preco, precoFiltro;
    int tempo;
    MatheusPedido *pTemp = NULL;

    do {
        printf("\n---DELIVERY ---\n");
        printf("1. Incluir Pedido\n");
        printf("2. Remover Pedido\n");
        printf("3. Imprimir Pedidos\n");
        printf("4. Contar Pedidos\n");
        printf("5. Limpar Registros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida.\n");
            setbuf(stdin, NULL);
            continue;
        }
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1:
                printf("Nome do Cliente: ");
                scanf(" %[^\n]", nomeC);

                printf("Nome do Pedido: ");
                scanf(" %[^\n]", nomeP);

                printf("Preco: ");
                scanf("%f", &preco);
                
                printf("Tempo de Entrega (min): ");
                scanf("%d", &tempo);

                pTemp = novoPedido(nomeC, nomeP, preco, tempo);
                if (inserirFim(minhaFila, pTemp)) {
                    printf("Pedido inserido com sucesso!\n");
                } else {
                    printf("Erro: Fila cheia.\n");
                    freePedido(pTemp);
                }
                break;

            case 2:
                if (removerInicio(minhaFila, &pTemp)) {
                    printf("Pedido removido do inicio:\n");
                    imprimePedido(pTemp);
                    freePedido(pTemp);
                } else {
                    printf("Erro: Fila vazia.\n");
                }
                break;

            case 3:
                imprimeFila(minhaFila);
                break;

            case 4:
                printf("Filtrar pedidos com preco maior que: ");
                scanf("%f", &precoFiltro);
                int total = contarPedidosFiltrados(minhaFila, precoFiltro, 0);
                printf("Total de pedidos com preco > %.2f: %d\n", precoFiltro, total);
                break;

            case 5:
                freeFila(minhaFila);
                minhaFila = criaFila();
                printf("Todos os registros foram removidos.\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    freeFila(minhaFila);
    return 0;
}
