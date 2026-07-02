typedef struct item Item;
typedef struct celula Celula;
typedef struct hash Hash;

#define TABLESIZE 50

Hash * cria_tabela();
void libera_tabela(Hash *h);
int verifica_tabela_vazia(Hash *h);
int hashing_string(char chave[]);
void imprime_item(Item *item);
void imprime_tabela(Hash *h);
void insere_tratamento_lista_encadeada(Hash *h, char nome[], char tipo[], int poder, int vida);
Item * busca_tratamento_lista_encadeada(Hash *h, char nome[]);
void remove_tratamento_lista_encadeada(Hash *h, char nome[]);
void batalha(Hash *h, char nome1[], char nome2[]);
