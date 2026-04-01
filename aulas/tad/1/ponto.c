#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"



//Operações TAD
Ponto *criaPonto(float x, float y) {
    Ponto *p = malloc(sizeof(Ponto));
    p-> x = x;
    p-> y = y;
    return p;
};

void imprimePonto(Ponto *p) {
    printf("x: %2.f, y: %2.f\n", p-> x, p-> y);
};

float calculaDistancia(Ponto *p1, Ponto *p2) {
    //Raiz eucladiana

    float dx, dy;
    dx = p2 -> x - p1 -> x;
    dy = p2 -> y - p1 -> y;
    return sqrt(pow(dx, 2) + pow(dy, 2));

};


void liberaPonto(Ponto *p) {
    free(p);
}


