#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Exemplo de uso de ponteiro de struct

typedef struct cliente Cliente;

struct cliente
{
    char nome[30];
    char rua[30];
    int numero;
};

void alteraEndereco(Cliente *cliente, char rua[], int numero)
{
    strcpy(cliente->rua, rua);
    cliente->numero = numero;
}

void imprimeCliente(Cliente *cliente)
{
    printf("\nNome: %s", cliente->nome);
    printf("\nRua: %s", cliente->rua);
    printf("\nNumero: %d\n", cliente->numero);
}

int main()
{

    Cliente cliente;
    strcpy(cliente.nome, "Matheus");
    strcpy(cliente.rua, "Rua Guarani");
    cliente.numero = 10;

    imprimeCliente(&cliente);
    alteraEndereco(&cliente, "Avenida tupi", 20);
    imprimeCliente(&cliente);

    return 0;
}