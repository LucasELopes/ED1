#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *prox, *ant;
}No;

No* criaNo(int ch);
No* criaLista();
void imprimirLista(No *L);
void insereInicio(No *L, int ch);
void insereFinal(No *L, int ch);
void excluiInicio(No *L);
void excluiFinal(No *L);
#endif