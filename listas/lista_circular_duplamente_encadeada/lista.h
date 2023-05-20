#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *prox, *ant;
}No;

No* criaNo(int ch);
void imprimirLista(No *L);
No* insereInicio(No *L, int ch);
No* insereFinal(No *L, int ch);
No* excluiInicio(No *L);
No* excluiFinal(No *L);
#endif