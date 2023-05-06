#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

typedef struct no
{
    int chave;
    struct no *prox, *ant;
}No;

No* criaNo(int);
No* criaLista();
void imprimirList(No *L);
void insereInicio(No *L, int ch);
No* retiraInicio(No *L);
int ocorrerencias(No *L , int ch);
No* ultimoLista(No *L);
void inverteLista(No *L);
int somaLista(No *L, int soma);
void substituiNo(No* L, int num1, int num2);
int iguais(No* L1, No* L2);
int iesimoIgual(No *L1, No *L2, int index);
#endif