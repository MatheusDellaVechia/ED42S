#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {

    Ponto *p1, *p2;
    float d;
    p1 = criaPonto(10, 20);
    p2 = criaPonto(15, 40);

    imprimePonto(p1);
    imprimePonto(p2);

    d = calculaDistancia(p1, p2);

    printf("Distancia entre os pontos: %.2f", d);

    liberaPonto(p1);
    liberaPonto(p2);


    return 0;
}