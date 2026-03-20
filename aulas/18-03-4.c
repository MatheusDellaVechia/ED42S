#include <stdlib.h>
#include <stdio.h>

//Exemplo de uso de vetor como argummento/parametro de funcao

void alteraVetor(int v[], int n) {
    v[0] = n;
}
 
int main() {
    int n = 5;
    int v[] = {1,2,3,4,5};
    alteraVetor(v, n);
    for(int i =0; i < n; i++) {
        printf("%d\t", v[i]);
    }
       
    return 0;
}