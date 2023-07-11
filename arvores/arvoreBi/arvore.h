#ifndef INCLUDED_ARVORE_H
#define INCLUDED_ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int chave;
    struct no *esq, *dir;
}NoArvore;

typedef struct noPilha {
    No *info;
    struct noPilha *prox;
}NoPilha;

NoArvore* criarNoArvore(int chave);
NoPilha* criarNoPilha(NoArvore *info);

void inserirPilha(NoPilha *Pilha, NoArvore info);
NoPilha* removerPilha(NoPIlha *Pilha);
void imprimirArvore(NoArvore **Arvore);

#endif