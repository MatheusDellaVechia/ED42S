#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Deque* cria_Deque() {
    Deque *dq = (Deque*) malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->inicio = 0;
        dq->final = 0;
        dq->qtd = 0;
    }
    return dq;
}

int Deque_cheia(Deque* dq) {
    return dq->qtd == MAXTAM;
}

int Deque_vazia(Deque* dq) {
    return dq->qtd == 0;
}

int insereFinal_Deque(Deque* dq, MatheusFestaPlaylist musica) {
    if (Deque_cheia(dq)) {
        printf("\nErro: Nao foi possivel inserir, playlist cheia.\n");
        return 0;
    }
    dq->item[dq->final] = musica;
    dq->final = (dq->final + 1) % MAXTAM;
    dq->qtd++;
    return 1;
}

int insereInicio_Deque(Deque* dq, MatheusFestaPlaylist musica) {
    if (Deque_cheia(dq)) {
        printf("\nErro: Nao foi possivel inserir, playlist cheia.\n");
        return 0;
    }
    dq->inicio--;
    if (dq->inicio < 0) {
        dq->inicio = MAXTAM - 1;
    }
    dq->item[dq->inicio] = musica;
    dq->qtd++;
    return 1;
}

int removeInicio_Deque(Deque* dq) {
    if (Deque_vazia(dq)) {
        printf("\nErro: Nao foi possivel remover, playlist vazia.\n");
        return 0;
    }
    printf("\nTocando agora: %s - %s\n", dq->item[dq->inicio].nomeMusica, dq->item[dq->inicio].artista);
    dq->inicio = (dq->inicio + 1) % MAXTAM;
    dq->qtd--;
    return 1;
}

void imprime_Deque(Deque* dq) {
    if (Deque_vazia(dq)) {
        printf("Playlist vazia.\n");
        return;
    }
    int n, i = dq->inicio;
    printf("\n--- PLAYLIST ATUAL ---\n");
    for(n = 0; n < dq->qtd; n++) {
        printf("%d. %s | %s | %ds | %d BPM\n", 
               n+1, dq->item[i].nomeMusica, dq->item[i].artista, 
               dq->item[i].duracaoSegundos, dq->item[i].bpm);
        i = (i + 1) % MAXTAM;
    }
}

void libera_Deque(Deque* dq) {
    free(dq);
}

int calculaDuracaoRecursivo(Deque *dq, int indiceAtual, int cont, int filtro) {
    if (cont == dq->qtd) {
        return 0;
    }
    
    int duracaoAtual = 0;
    int bpm = dq->item[indiceAtual].bpm;
    
    if ((filtro == 1 && bpm > 120) || (filtro == 0 && bpm < 120)) {
        duracaoAtual = dq->item[indiceAtual].duracaoSegundos;
    }
    
    return duracaoAtual + calculaDuracaoRecursivo(dq, (indiceAtual + 1) % MAXTAM, cont + 1, filtro);
}

