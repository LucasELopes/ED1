#ifndef INCLUDED_LISTA_H
#define INCLUDED_LIST_H

typedef struct no
{
    int chave;
    struct no *prox, *ant;
}No;

No* criaNo(int ch);
void imprimiLista(No **L);

// Lista não ordenada.

No* buscaLista(No **L, int ch);
void insereInicio(No **L, int ch);
void insereFinal(No **L, int ch);
void excluirInicio(No **L);
void excluirFinal(No **L);

// Lista ordenada.

No* buscaOrd(No **L, int ch);
void insereOrd(No **L, int ch);
void excluiChave(No **L, int ch);


#endif