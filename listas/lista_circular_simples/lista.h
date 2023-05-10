#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

typedef struct no {
    int chave;
    struct no *prox;
}No;


void imprimirLista(No *L);
No* criaNo(int ch);
No* inseriInicio(No *L, int ch);
No* inseriFinal(No *L, int ch);
No* excluiInicio(No *L);
No* excluiFinal(No *L);
#endif