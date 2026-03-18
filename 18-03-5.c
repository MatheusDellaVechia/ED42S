#include <stdlib.h>
#include <stdio.h>

//Exemplo de uso de vetor como argummento/parametro e retorno de funcao

void alteraVetor(int v[], int n) {
    v[0] = n;
}

char *copiaParteStr(char c, char str[]) {
    while(c != *str && *str) { //so para se o c for igual ao conteudo do ponteiro ou a string acabar
        str = str + 1; //artimetica de pontero para avancar na string 
    }

    return str; //retorna o ponteiro contendo o restante da string
}
 
int main() {
    int n = 5;
    int v[] = {1,2,3,4,5};
    alteraVetor(v, n);
    for(int i =0; i < n; i++) {
        printf("%d\t", v[i]);
    }

    char s[] = "Boa noite!";
    char c = 'a';
    char *pc  = copiaParteStr(c, s);

    printf("pc :%d", *pc); 

    if (0) { //se ha um valro associado ao ponteiro
        printf("\n%s", pc); 

    } else {
        printf("Caractere nao encontrado na String.");
    }
       
    return 0;
}