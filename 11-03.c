#include<stdio.h>
#include<stdlib.h>

typedef struct triangulo Triangulo;
typedef struct ponto Ponto;

struct ponto {
    int x;
    int y;
};

struct triangulo {
    Ponto pontos[3];
};

int main() {

    Triangulo triangulo;
    triangulo.pontos[0].x = 0;
    triangulo.pontos[0].y = 0;
    triangulo.pontos[1].x = 5;
    triangulo.pontos[1].y = 0;
    triangulo.pontos[2].x = 1;
    triangulo.pontos[2].y = 0;

    for(int i = 0; i < 3; i ++) {
        printf("x: %d, y: %d\n", triangulo.pontos[i].x, triangulo.pontos[i].y);
    }

    return 0;
}



