#ifndef LOGISTICA_H_INCLUDED
#define LOGISTICA_H_INCLUDED
#define MAXTAM 5

typedef struct pacote {
    char codigoRastreio[25]; 
    float peso;
    char cidadeDestino[50];
    char remetente[50];
    float valor;
} Pacote;

typedef struct fila {
    Pacote item[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
} Fila;

int gerarCheckSum(char *codigoBase);
int validarCodigoRastreio(char *codigoRastreio);
Fila* criaFilaVazia();
int verificaFilaCheia(Fila *f);
int verificaFilaVazia(Fila *f);
int buscaChaveFila(Fila *f, char *chaveBusca);
int enfileiraPacote(Fila *f, Pacote pBase, char *codigoOriginal);
int desenfileiraPacote(Fila *f);
void buscaPorCidade(Fila *f, char *cidadeBuscada);
void imprimeFila(Fila *f);
void imprimeFilaRecursivo(Fila *f, int indiceAtual, int cont);
void liberaFila(Fila *f);
#endif