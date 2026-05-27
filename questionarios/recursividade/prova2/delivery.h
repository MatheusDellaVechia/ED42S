#ifndef DELIVERY_H_INCLUDED
#define DELIVERY_H_INCLUDED

#define MAX 100

typedef struct matheusPedido MatheusPedido;
typedef struct fila Fila;

MatheusPedido *novoPedido(char nomeCliente[], char nomePedido[], float preco, int tempoEntrega);
void imprimePedido(MatheusPedido *p);
void freePedido(MatheusPedido *p);

Fila *criaFila();
int inserirFim(Fila *f, MatheusPedido *p);
int removerInicio(Fila *f, MatheusPedido **p);
void imprimeFila(Fila *f);
void freeFila(Fila *f);

int contarPedidosFiltrados(Fila *f, float precoMinimo, int index);

#endif
