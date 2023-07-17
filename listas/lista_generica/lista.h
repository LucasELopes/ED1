#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noGen {
    void *info;
    struct noGen *prox;
}NoGen;

NoGen* criarNo(void *info);
void inserirInicio(NoGen *L, void *info);
void percorreLista(NoGen *L, void (*cb) (void *));




#endif

