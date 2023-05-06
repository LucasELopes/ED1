#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

typedef struct no {
    int chave;
    struct no *prox, *ant;
}No;

No* criaNo(int ch);
No* buscaLista(No *L, int ch);
No* buscaListaOrd(No *L, int ch);
No* inserirInicio(No *L, int ch);
No* inserirFinal(No *L, int ch);
No* insereOrd(No *L, int ch);
No* excluiInicio(No *L);
No* excluiFinal(No *L);
No* excluiChave(No *L, int ch);
#endif