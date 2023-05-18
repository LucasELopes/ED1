#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

typedef struct no {
    int chave;
    struct no *prox;
}No;


void imprimirLista(No *L);
No* criaNo(int ch);
No* criaLista();
void inseriInicio(No *L, int ch);
void inseriFinal(No *L, int ch);
void excluiInicio(No *L);
void excluiFinal(No *L);
#endif