#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

//command to execute in ubuntu
//gcc main.c pessoa.c -o programa 
//./programa

int main() {

    Pessoa *vetPessoas;

    int n = 0;
    
    vetPessoas = inserePessoas(vetPessoas, "Matheus", 22, n);

    n++;

    vetPessoas = inserePessoas(vetPessoas, "JAO", 22, n);

    imprimePessoas(vetPessoas, n);

    liberaVetorPessoas(vetPessoas);

    return 0;
}