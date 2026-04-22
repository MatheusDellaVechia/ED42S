#ifndef ITEM_LISTA_H_INCLUDED
#define ITEM_LISTA_H_INCLUDED
#define MAX_TAM 5

typedef struct item Item;
typedef struct lista Lista;

Lista *criaListaVazia();

int verificaListaVazia(Lista *lista);

int verificaListaCheia(Lista * lista);

void adicionaItemFimLista(Lista *lista, int chave);

void imprimeLista(Lista *lista);

int buscaItemPorChave(Lista *lista, int chave);

void removeItem(Lista *lista, int chave);

void liberaLista(Lista *lista);


#endif