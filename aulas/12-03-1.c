#include<stdio.h>
#include<stdlib.h>

typedef struct pedido {
    char nomeCliente[30];
    char descricaoPedido[100];
    float valor;
} Pedido;

int main() {

        Pedido pedido1;

        printf("Digite o nome do cliente: ");
        scanf("%[^\n]s", pedido1.nomeCliente);
        setbuf(stdin, NULL);

        printf("Digite o pedido: ");
        scanf("%[^\n]s", pedido1.descricaoPedido);

        printf("Digite o valor do pedido: ");
        scanf("%f", &pedido1.valor);
    
        printf("-------Pedido:----------\n");
        printf("Cliente: %s\n", pedido1.nomeCliente);
        printf("Descrição: %s\n ", pedido1.descricaoPedido);
        printf("Valor: %.2f\n", pedido1.valor);
    return 0;
}
