#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *inverteString (char s[]) {
    int i, j, tamanho;
    tamanho = strlen(s);
     char *stringInvertida = (char *) malloc(tamanho * sizeof(char));
    j = 0;

    for (i = tamanho -1; i >=0; i--) {
        stringInvertida[j] = s[i];
        j++;
    }

    stringInvertida[j]= '\0';
    return stringInvertida; //n retorna endereço de memória de variável local como retorno

}


int main()
{
    char *string = "abc";
    char *i = inverteString(string);
    printf("%s\n", i);

    free(i);
    return 0;
}