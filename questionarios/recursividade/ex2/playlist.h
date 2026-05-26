#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#define MAXTAM 10

typedef struct matheusFestaPlaylist {
    char nomeMusica[50];
    char artista[50];
    int duracaoSegundos;
    int bpm;
} MatheusFestaPlaylist;

typedef struct deque {
    MatheusFestaPlaylist item[MAXTAM];
    int inicio;
    int final;
    int qtd;
} Deque;

Deque* cria_Deque();
int Deque_cheia(Deque* dq);
int Deque_vazia(Deque* dq);
int insereFinal_Deque(Deque* dq, MatheusFestaPlaylist musica);
int insereInicio_Deque(Deque* dq, MatheusFestaPlaylist musica);
int removeInicio_Deque(Deque* dq);
void imprime_Deque(Deque* dq);
int calculaDuracaoRecursivo(Deque *dq, int indiceAtual, int cont, int filtro);
void libera_Deque(Deque* dq);

#endif