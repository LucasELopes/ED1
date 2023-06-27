#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *dir, *esq;
}Arvore;

/*
Função: criarNo
Descrição:
    Aloca dinamicamente um espaço na memória armazenando o valor genérico passado como parâmetro.
Entrada:
    int info: O valor que o nó armazenará
Saída:
    Arvore*: O nó já alocado que armazanando seu respectivo valor.
*/
Arvore* criaNo(int info);

/*
Função: busca
Descrição:
    Busca  o respectivo valor passado com parametro.
Entrada:
    Arvore *A: A arvore em qual vai acontece a busca.
    inf info: O valor buscado.
    Arvore **pred: O antecessor do nó buscado.
Saída:
    Arvore*: O nó buscado dentro da lista.
*/
Arvore* busca(Arvore *A, int info, Arvore **pred);

/*
Função: insere
Descrição:
    Insere um nó na arvore.
Entrada:
    Arvore *A: A arvore em qual vai ser inserido o nó.
    inf info: O valor que o nó armazenará.
Saída:
    Arvore*: O nó buscado dentro da lista.
*/
Arvore* insere(Arvore *A, int info);

/*
Função: imprime
Descrição:
    Imprime a árvore.
Entrada:
    Arvore *A: A arvore que vai ser imprimida.
Saída:
    Arvore*: O nó buscado dentro da lista.
*/
void imprime(Arvore *A, int nivel);

#endif