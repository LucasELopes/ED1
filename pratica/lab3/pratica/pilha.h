#ifndef INCLUDED_PILHA_H
#define INCLUDED_PILHA_H

// Inclusão das bibliotecas utilizadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definido a estrutura do dado no
typedef struct no {
    char delim;
    struct no *prox, *ant;
}No;

/*
Função: imprimirPilha.
Descrição: Imprimi todo o conteúdo presente na pilha, caso não tenha imprime "pilha vazia!".
Entrada: 
    No* p: A respectiva pilha que será imprimida.
Saída:
    A função não retona nada, pois só é informativa.
*/
void imprimirPilha(No* p);

/*
Função: criarNo
Descrição: Aloca dinamicamente um no com o paramâtro passado como argumento.
Entrada:
    char delim: armazena o delimitador.
Saída:
    Ponteiro para o respectivo no criado.
*/
No* criarNo(char delim);

/*
Função: inserirNo.
Descrição: Insere ao final da pilha um no alocado dinamicamente.
Entrada: 
    No* p: A pilha que onde será inserido o no.
    char delim: O respectivo delimitador desse no.
Saída:
    A função não retorna nada, pois estamos modificando diretamente nos endereços de memória.
*/
void inserirNo(No* p, char delim);

/*
Função: removerNo.
Descrição: Remove o último no da pilha.
Entrada:
    No *p: A pilha onde será removido o nó.
Saída:
    void
*/
void removerNo(No *p);

/*
Função: retirarNo.
Descrição: Retira o último no da pilha.
Entrada:
    No *p: A pilha onde será retirado o nó.
Saída:
    ponteiro para estrutura No alocado dinamicamente.
*/
No* retirarNo(No *p);


/*
Função: delimitador.
Descrição: Verifica se os delimitadores estão posicionados corretamente.
Entrada:
    FILE* file: O arquivo de entrada contendo os delimitadores.
Saída:
    retona 1 caso os delimitadores estejam balanceados e 0, caso contrário.
*/
int delimitador(FILE* file);
#endif