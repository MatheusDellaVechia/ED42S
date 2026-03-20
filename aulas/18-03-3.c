#include <stdlib.h>
#include <stdio.h>

//Exemplo aritmética de ponteiros com vetor

int main() {

        short int vet[] = {20,30,40,50,60}; //short int ocupa 2 bytes
        short int *p = vet; //recebe o nome do vetor, para pegar a primeira posição, não precisa um &;

        printf("p aponta para o endereco: %ld\n", p); //endereco de vet[0]
        printf("o valor guardado no endereco acima eh: %d", *p); //valor em vet[0]

        p = p + 2; //Artimética de ponteiros, avança duas posições
        printf("\np = p + 2\n");
        printf("p aponta para o endereco: %ld\n", p); //endereco de vet[2]
        printf("o valor guardado no endereco acima eh: %d", *p); //valor em vet[2]

        p = p - 1; //Artimética de ponteiros, avança duas posições
        printf("\np = p -1\n");
        printf("p aponta para o endereco: %ld\n", p); //endereco de vet[1]
        printf("o valor guardado no endereco acima eh: %d\n", *p); //valor em vet[1]
    return 0;
}