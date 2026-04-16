#ifndef ONG_H_INCLUDED
#define ONG_H_INCLUDED

typedef struct data Data;
typedef struct petsMatheus PetsMatheus;

PetsMatheus *novoPet(PetsMatheus *vet, Data *dataNascimento, int quantidadePets, char nome[], char raca[], char sexo, float peso, int jaAdotado);

void imprimePet(PetsMatheus *pet, int quantidade);

void imprimePetPorMes(int mes, PetsMatheus *pet, int quantidade);

void imprimePetPorMesNaoAdotados(int mes, PetsMatheus *pet, int quantidade);

void liberaPets(PetsMatheus *pets, int quantidade);

Data *criarData(int dia, int mes, int ano);

void imprimirData(Data *data);

void liberarData(Data *data);

#endif