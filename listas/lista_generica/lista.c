#include "lista.h"

NoGen* criarNo(void *info) {
    NoGen *novoNo = (NoGen*)calloc(1, sizeof(NoGen));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->info = info;
    return novoNo;
}

void inserirInicio(NoGen *L, void *info) {
    NoGen *novoNo = criarNo(info);
    novoNo->prox = L->prox;
    L->prox = novoNo;
}

void percorreLista(NoGen *L, void (*cb) (void *)) {
    NoGen *aux = L->prox;
    while(aux) {
        cb(aux->info);
        aux = aux->prox;
    }
}