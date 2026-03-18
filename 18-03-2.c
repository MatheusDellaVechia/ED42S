#include <stdlib.h>


int main() {

        char c = 'c';
        int n = 10;
        int *pn = &n; // ponteiro de inteiro que guarda o endereço de n
        char *pc = &c; //ponteiro de char que guarda o endereço de c

        //imprime conteúdo
        printf("O valor da variavel n eh: %d \n", n);
        printf("O valor da variavel c eh: %d \n", c);

        //imprime o endereço
        printf("O endereco da variavel n eh: %ld \n", &n);
        printf("O endereco da variavel c eh: %ld\n", &c);

        //imprime conteudo das variaveis do tipo ponteiro
        printf("pn aponta para o endereco de n que eh: %p\n", pn);
        printf("pc aponta para o endereco de c que eh: %p\n", pc);

        //imprime conteudo das variaveis apontadass pelos ponteiros
        printf("No endereco apontado por pn esta o conteudo: %d\n", *pn);
        printf("No endereco apontado por pc esta o conteudo: %d\n", *pc);

        *pn = 20;
        printf("Agora no endereco apontado por pn esta o conteudo: %d\n", *pn);
        



    return 0;
}