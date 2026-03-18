#include <stdlib.h>


int main() {

        char c = 'c';
        int n = 10;

        printf("O valor da variavel n eh: %d \n", n);
        printf("O valor da variavel c eh: %d \n", c);


        printf("O endereco da variavel n eh: %ld \n", &n);
        printf("O endereco da variavel c eh: %ld\n", &c);

    return 0;
}