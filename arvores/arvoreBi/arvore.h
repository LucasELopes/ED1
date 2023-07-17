#ifndef INCLUDED_ARVORE_H
#define INCLUDED_ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
}No;

No* criarNo(int chave);
void imprimirArvore(No **A, int nivel);
No* busca(No **A, int ch, No **pred);
void inserirArvore(No **A, int ch);
No* sucessor(No **A, No **pred);
void removerNo(No **A, int ch);

#endif