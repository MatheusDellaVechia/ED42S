#ifndef ASSINATURAS_H_INCLUDED
#define ASSINATURAS_H_INCLUDED

typedef struct data Data;
typedef struct servico Servico;
typedef struct contratante Contratante;

Data *novaData(int dia, int mes, int ano);

Servico *novoServico(Servico *vet, char descricao[], float valor, int quantidadeServicos);

Contratante *novoContratante(Contratante *vet, char nome[], int indiceContratante, int quantidadeServicos, Servico *servicos, Data *dataNascimento);

void imprimeData(Data *data);

void imprimeServico(Servico *servico);

void imprimeContratante(Contratante *contratante);

void imprimeContratantes(Contratante *contratantes, int quantidade);

void freeData(Data *data);

void freeServico(Servico *servico);

void freeContratante(Contratante *contratante);

#endif