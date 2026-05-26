#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main(void) {
    Deque *dq = cria_Deque();
    int opcao = 0;
    MatheusFestaPlaylist musica;

    do {
        printf("\n--- PLAYLIST COLABORATIVA (DEQUE) ---\n");
        printf("1. Adicionar Musica (Fluxo Normal - Final)\n");
        printf("2. Adicionar Musica VIP (Fura Fila - Inicio)\n");
        printf("3. Tocar Proxima Musica (Remover do Inicio)\n");
        printf("4. Mostrar Playlist\n");
        printf("5. Calcular Tempo Total - Musicas Animadas (>120 BPM)\n");
        printf("6. Calcular Tempo Total - Musicas Lentas (<120 BPM)\n");
        printf("7. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1 || opcao == 2) {
            printf("Nome da Musica: ");
            scanf("%[^\n]s", musica.nomeMusica); getchar();
            printf("Artista: ");
            scanf("%[^\n]s", musica.artista); getchar();
            printf("Duracao (segundos): ");
            scanf("%d", &musica.duracaoSegundos); getchar();
            printf("BPM: ");
            scanf("%d", &musica.bpm); getchar();
        }

        switch(opcao) {
            case 1:
                insereFinal_Deque(dq, musica);
                break;
            case 2:
                insereInicio_Deque(dq, musica);
                break;
            case 3:
                removeInicio_Deque(dq);
                break;
            case 4:
                imprime_Deque(dq);
                break;
            case 5:
                if (!Deque_vazia(dq)) {
                    int total = calculaDuracaoRecursivo(dq, dq->inicio, 0, 1);
                    printf("\nDuracao total de musicas Animadas: %d segundos\n", total);
                } else {
                    printf("\nPlaylist vazia.\n");
                }
                break;
            case 6:
                if (!Deque_vazia(dq)) {
                    int total = calculaDuracaoRecursivo(dq, dq->inicio, 0, 0);
                    printf("\nDuracao total de musicas Lentas: %d segundos\n", total);
                } else {
                    printf("\nPlaylist vazia.\n");
                }
                break;
            case 7:
                printf("Encerrando festa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 7);

    libera_Deque(dq);
    return 0;
}