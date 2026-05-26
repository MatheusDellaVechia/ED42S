#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logistica.h"

int gerarCheckSum(char *codigoBase) {
    int soma = 0;
    for (int i = 0; i < strlen(codigoBase); i++) {
        soma += codigoBase[i];
    }
    return soma % 10;
}

int validarCodigoRastreio(char *codigoRastreio) {
    char copia[25];
    strcpy(copia, codigoRastreio);
    
    char *base = strtok(copia, "-");
    char *digitoStr = strtok(NULL, "-");
    
    if (base == NULL || digitoStr == NULL) return 0;
    
    int digitoInformado = atoi(digitoStr);
    int digitoCalculado = gerarCheckSum(base);
    
    return (digitoInformado == digitoCalculado);
}

Fila* criaFilaVazia() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->primeiro = 0;
        f->ultimo = 0;
        f->tamanho = 0;
    }
    return f;
}

int verificaFilaCheia(Fila *f) {
    return f->tamanho == MAXTAM;
}

int verificaFilaVazia(Fila *f) {
    return f->tamanho == 0;
}

int buscaChaveFila(Fila *f, char *chaveBusca) {
    int i = f->primeiro;
    for (int t = 0; t < f->tamanho; t++) {
        if (strcmp(f->item[i].codigoRastreio, chaveBusca) == 0) {
            return 1;
                }
        i = (i + 1) % MAXTAM;
    }
    return 0;
}

int enfileiraPacote(Fila *f, Pacote pBase, char *codigoOriginal) {
    if (verificaFilaCheia(f)) {
        printf("Erro: a fila esta cheia.\n");
        return 0;
    }
    
    int digito = gerarCheckSum(codigoOriginal);
    sprintf(pBase.codigoRastreio, "%s-%d", codigoOriginal, digito);
    
    if (buscaChaveFila(f, pBase.codigoRastreio)) {
        printf("Erro: Pacote com este codigo de rastreio ja existe!\n");
        return 0;
    }

    f->item[f->ultimo] = pBase;
    f->ultimo = (f->ultimo + 1) % MAXTAM;
    f->tamanho++;
    return 1;
}

int desenfileiraPacote(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Erro: a fila esta vazia.\n");
        return 0;
    }
    printf("Pacote excluido/despachado: %s\n", f->item[f->primeiro].codigoRastreio);
    f->primeiro = (f->primeiro + 1) % MAXTAM;
    f->tamanho--;
    return 1;
}

void buscaPorCidade(Fila *f, char *cidadeBuscada) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    int i = f->primeiro;
    int encontrou = 0;
    printf("\n--- Pacotes para %s ---\n", cidadeBuscada);
    for (int t = 0; t < f->tamanho; t++) {
        if (strcmp(f->item[i].cidadeDestino, cidadeBuscada) == 0) {
            printf("Rastreio: %s | Peso: %.2f | Remetente: %s\n", 
                   f->item[i].codigoRastreio, f->item[i].peso, f->item[i].remetente);
            encontrou = 1;
        }
        i = (i + 1) % MAXTAM;
    }
    if (!encontrou) printf("Nenhum pacote encontrado para esta cidade.\n");
}

void imprimeFila(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    int i = f->primeiro;
    for (int t = 0; t < f->tamanho; t++) {
        int valido = validarCodigoRastreio(f->item[i].codigoRastreio);
        printf("Rastreio: %s [%s] | Cidade: %s | Peso: %.2f | Remetente: %s | Valor: %.2f\n", 
               f->item[i].codigoRastreio, 
               valido ? "VALIDO" : "CORROMPIDO",
               f->item[i].cidadeDestino, f->item[i].peso, f->item[i].remetente, f->item[i].valor);
        i = (i + 1) % MAXTAM;
    }
}

void imprimeFilaRecursivo(Fila *f, int indiceAtual, int cont) {
    if (cont == f->tamanho) {
        return; 
    }
    
    int valido = validarCodigoRastreio(f->item[indiceAtual].codigoRastreio);
    printf("Rastreio: %s [%s] | Cidade: %s\n", 
           f->item[indiceAtual].codigoRastreio, 
           valido ? "VALIDO" : "CORROMPIDO",
           f->item[indiceAtual].cidadeDestino);
           
    imprimeFilaRecursivo(f, (indiceAtual + 1) % MAXTAM, cont + 1);
}

void liberaFila(Fila *f) {
    if (f != NULL) {
        free(f);
    }
}