# Trabalho Final — Arena de Monstros

## Tabela Hash com Tratamento de Colisão aplicada a um Jogo Digital

**Disciplina:** ED42S — Estrutura de Dados
**Estrutura escolhida:** Tabela Hash com tratamento de colisão por **Endereçamento Separado** (listas encadeadas)

---

## 1. Visão geral do projeto

O trabalho implementa um jogo de console chamado **Arena de Monstros**. O jogador cadastra
monstros (nome, tipo, poder e vida), pode buscá-los, listá-los, removê-los e colocá-los
para **batalhar** entre si.

O que dá suporte a tudo isso é uma **Tabela Hash**: cada monstro é armazenado numa posição
calculada a partir do seu **nome**. Assim, buscar ou batalhar não precisa varrer a estrutura
inteira — a posição é *calculada* diretamente.

### Arquivos

| Arquivo | Papel |
|---|---|
| `hashArena.h` | Interface do TAD (tipos opacos + protótipos das funções) |
| `hashArena.c` | Implementação da Tabela Hash (encapsulamento) |
| `main.c` | Interação com o usuário (menu do jogo no console) |

### Como compilar e executar

```bash
gcc -Wall main.c hashArena.c -o arena
./arena
```

---

## 2. Requisitos do enunciado e onde foram atendidos

| Requisito | Onde está atendido |
|---|---|
| TAD + encapsulamento | `struct item/celula/hash` definidas só no `.c`; no `.h` são tipos opacos |
| Hash com tratamento de colisão | Endereçamento separado (listas encadeadas), baseado no exemplo da professora |
| Jogo digital adequado à estrutura | Arena de Monstros: cadastro/busca/batalha por nome (chave) |
| Nova função de hash com chave `char[]` | `hashing_string` (Horner base 31 + divisão) |
| Definir os dados e qual campo é a chave | Item = nome/tipo/poder/vida; **chave = nome** |
| Objetivo e interação no console | Menu em `main.c` |

---

## 3. TAD e Encapsulamento

O **encapsulamento** é garantido porque as `struct` só existem dentro do `hashArena.c`.
No `hashArena.h` o mundo externo (o `main.c`) conhece apenas os **nomes dos tipos**, não os
campos internos:

```c
// hashArena.h  -> tipos OPACOS (quem usa não enxerga os campos)
typedef struct item Item;
typedef struct celula Celula;
typedef struct hash Hash;
```

```c
// hashArena.c  -> os campos só existem aqui dentro
struct item {
    char nome[30];
    char tipo[20];
    int poder;
    int vida;
};

struct celula {   // guarda um item + ponteiro para a próxima célula da lista
    Item item;
    Celula *prox;
};

struct hash {
    int quantidade;      // quantos itens há na tabela (facilita saber se está vazia)
    Celula **celulas;    // vetor de ponteiros; cada posição aponta para uma lista
};
```

**Por que célula em vez de guardar o item direto?**
Porque usamos **endereçamento separado**: cada posição da tabela pode conter *vários* itens
(quando há colisão). Então cada posição aponta para uma **lista encadeada** de células.

**Definição dos dados e da chave:**
- Dados do item: `nome`, `tipo`, `poder`, `vida`.
- **Campo-chave: `nome`** — é ele que passa pela função de hash para decidir a posição.

---

## 4. A nova função de hash (o coração do trabalho)

O enunciado pede uma **nova** função de hash, **variação de uma estudada**, usando **chave
`char[]` (string)**. A minha é a `hashing_string`:

```c
int hashing_string(char chave[]) {
    int i;
    unsigned long soma = 0;
    for(i = 0; chave[i] != '\0'; i++)
        soma = soma * 31 + chave[i];   // método de Horner (base 31)
    return soma % TABLESIZE;           // método da divisão -> cabe em 0..TABLESIZE-1
}
```

Ela combina **duas técnicas vistas em aula**:

1. **Hashing com strings** (na aula era base 256). Eu uso **base 31** porque:
   - a posição de cada letra continua importando (é multiplicação encadeada, método de Horner);
   - a base 31 cresce mais devagar que 256, reduzindo o risco de estouro do número;
   - 31 é primo, o que ajuda a espalhar melhor as chaves (menos colisões).
2. **Método da divisão** (`% TABLESIZE`) para encaixar o número final dentro da tabela.

Por isso ela é uma **variação** das funções estudadas (hashing de strings + divisão), e não
uma cópia — foi o ponto exigido pelo trabalho.

### 4.1 Como o número é gerado (passo a passo)

Cada letra tem um código ASCII. A cada letra fazemos `soma = soma * 31 + letra`.

Exemplo com **"Sharizard"**:

| Letra | ASCII | Conta | soma |
|---|---|---|---|
| S | 83  | 0·31 + 83     | 83 |
| h | 104 | 83·31 + 104   | 2.677 |
| a | 97  | 2.677·31 + 97 | 83.084 |
| r | 114 | ...           | 2.575.718 |
| i | 105 | ...           | 79.847.363 |
| z | 122 | ...           | 2.475.268.375 |
| a | 97  | ...           | 76.733.319.722 |
| r | 114 | ...           | 2.378.732.911.496 |
| d | 100 | ...           | **73.740.720.256.476** |

Depois, o **método da divisão** encaixa na tabela:

```
73.740.720.256.476 % 50 = 26
```

➡️ Por isso **"Sharizard" vai para a posição 26**.

### 4.2 Comparação entre nomes

| Nome | Número gerado | `% 50` | Posição |
|---|---|---|---|
| Sharizard | 73.740.720.256.476 | 26 | **26** |
| Charizard | 60.094.463.657.420 | 20 | **20** |
| Pikachu   | 74.108.160.289     | 39 | **39** |

Repare que **"Sharizard" e "Charizard" caem em posições diferentes** (26 vs 20), mesmo sendo
quase iguais: só muda a 1ª letra (`S`=83 vs `C`=67), e como cada letra é multiplicada
repetidamente por 31, essa diferença se propaga por todo o cálculo. Isso mostra que a função
**espalha bem** as chaves.

---

## 5. Tratamento de colisão — Endereçamento Separado

**Colisão** é quando dois nomes diferentes geram a mesma posição. No endereçamento separado,
a posição guarda uma **lista encadeada**, e o novo item é inserido **no início** dessa lista.

```c
void insere_tratamento_lista_encadeada(Hash *h, char nome[], char tipo[], int poder, int vida) {
    int posicao = hashing_string(nome);   // calcula a posição a partir do nome (chave)
    Item item;
    strcpy(item.nome, nome);
    strcpy(item.tipo, tipo);
    item.poder = poder;
    item.vida = vida;
    Celula *aux = malloc(sizeof(Celula));
    aux->item = item;
    aux->prox = h->celulas[posicao];      // a nova célula aponta para o que já existia
    h->celulas[posicao] = aux;            // e passa a ser a 1ª da lista (inserção no início)
    h->quantidade++;
}
```

Se dois monstros colidirem na posição X, a lista dessa posição fica com os dois, um apontando
para o outro — e nenhum dado é perdido. Esse é o **tratamento de colisão** do trabalho.

---

## 6. As demais funções do TAD

### 6.1 `cria_tabela` — cria a tabela vazia
Idêntica ao padrão da professora: aloca a Hash, zera `quantidade`, aloca o vetor de ponteiros
e inicializa todas as posições com `NULL`.

```c
Hash *cria_tabela() {
    int i;
    Hash *h = malloc(sizeof(Hash));
    h->quantidade = 0;
    h->celulas = malloc(TABLESIZE * sizeof(Celula*));
    for(i = 0; i < TABLESIZE; i++)
        h->celulas[i] = NULL;
    return h;
}
```

### 6.2 `busca_tratamento_lista_encadeada` — encontra pelo nome
Calcula a posição com a **mesma** função de hash e percorre a lista daquela posição
comparando com `strcmp` (porque a chave é texto).

```c
Item *busca_tratamento_lista_encadeada(Hash *h, char nome[]) {
    int posicao = hashing_string(nome);
    if(h->celulas[posicao] == NULL)
        return NULL;
    Celula *aux = h->celulas[posicao];
    while(aux != NULL) {
        if(strcmp(aux->item.nome, nome) == 0)
            return &aux->item;
        aux = aux->prox;
    }
    return NULL;
}
```

### 6.3 `remove_tratamento_lista_encadeada` — remove pelo nome
Trata os quatro casos do padrão da professora: lista vazia, remover do início, remover do
meio/fim e chave inexistente.

### 6.4 `imprime_tabela` — mostra todas as posições
Percorre as `TABLESIZE` posições; imprime `NULL` nas vazias e os nomes da lista nas ocupadas.

### 6.5 `verifica_tabela_vazia` — usa o campo `quantidade`
Retorna `h->quantidade == 0`.

### 6.6 `libera_tabela` — libera toda a memória
Percorre cada posição liberando célula por célula, depois libera o vetor e a Hash.

### 6.7 `batalha` — regra do jogo
Busca os dois monstros pelo nome (reaproveitando a busca por hash) e compara o poder para
decidir o vencedor.

```c
void batalha(Hash *h, char nome1[], char nome2[]) {
    Item *m1 = busca_tratamento_lista_encadeada(h, nome1);
    Item *m2 = busca_tratamento_lista_encadeada(h, nome2);
    if(m1 == NULL || m2 == NULL) {
        printf("Um dos monstros nao foi encontrado na arena.\n");
        return;
    }
    imprime_item(m1);
    imprime_item(m2);
    if(m1->poder > m2->poder)      printf(">> Vencedor: %s!\n", m1->nome);
    else if(m2->poder > m1->poder) printf(">> Vencedor: %s!\n", m2->nome);
    else                            printf(">> Empate!\n");
}
```

---

## 7. Fluxo dos dados (cadastrar × batalhar)

Este é o ponto central para entender o jogo:

1. **Cadastrar**: o nome passa por `hashing_string` → resultado é a **posição** → o monstro é
   guardado ali.
2. **Batalhar/Buscar**: o mesmo nome passa pela **mesma** `hashing_string` → cai na **mesma
   posição** → o monstro é encontrado.

A **chave (nome) + a função de hash** é o elo entre guardar e recuperar. Como a função é
**determinística**, o mesmo nome sempre aponta para o mesmo lugar.

---

## 8. Fidelidade ao padrão da professora

O TAD segue o exemplo **`HashEndSeparado`** (Endereçamento Separado):

- mesmas `struct item/celula/hash`;
- `cria_tabela`, `libera_tabela`, `verifica_tabela_vazia`, `imprime_tabela`,
  `insere/busca/remove` com a mesma lógica;
- inserção no início da lista;
- `#define TABLESIZE 50`.

As **únicas** diferenças são as **exigidas pelo enunciado**:
1. chave `char[]` (nome) em vez de `int` → nova função `hashing_string`;
2. item com vários campos (jogo) em vez de só `chave`;
3. `busca`/`remove` usam `strcmp` porque a chave é texto.

---

## 9. Roteiro de teste (exemplos de entrada)

Sequência sugerida no menu:

1. **Cadastrar** → `Pikachu`, `Eletrico`, `90`, `200`
2. **Cadastrar** → `Charizard`, `Fogo`, `95`, `180`
3. **Cadastrar** → `Blastoise`, `Agua`, `85`, `220`
4. **Listar tabela hash** → ver cada monstro na sua posição
5. **Buscar** → `Charizard` → deve encontrar
6. **Batalhar** → `Pikachu` × `Charizard` → vence quem tem maior poder
7. **Remover** → `Pikachu` → some da tabela
8. **Sair**

> Dica para demonstrar **colisão**: cadastre nomes diferentes que caiam na mesma posição e
> use "Listar" para mostrar os dois na mesma linha (lista encadeada).

---

## 10. Perguntas prováveis na prova de autoria (e respostas)

**Qual é a chave da sua tabela?**
O nome do monstro.

**Por que sua função de hash é uma "nova" função?**
Porque combina o hashing de strings (que na aula era base 256) usando base 31, com o método
da divisão. É uma variação das técnicas estudadas, não uma cópia.

**Por que multiplicar por 31 a cada letra?**
Para que a posição de cada letra importe (método de Horner) e para espalhar melhor as chaves;
31 é primo e cresce devagar, reduzindo colisões e risco de estouro.

**O que é colisão e como você trata?**
É quando dois nomes geram a mesma posição. Trato com endereçamento separado: cada posição tem
uma lista encadeada e insiro no início dela.

**Por que usa `strcmp` na busca e não `==`?**
Porque a chave é uma string; `==` compararia endereços, não o conteúdo.

**Por que a struct fica no `.c` e não no `.h`?**
Encapsulamento: quem usa o TAD só conhece os tipos, não os campos internos.

**O que acontece se a tabela encher?**
No endereçamento separado não existe "tabela cheia" — as listas apenas crescem.
