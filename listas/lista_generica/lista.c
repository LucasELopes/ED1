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

NoGen* inserirInicio(NoGen *L, void *info) {
    NoGen *novoNo = criarNo(info);
    novoNo->prox = L;
    return novoNo;
}

void imprimirLista(NoGen *L, void (*cb) (void *)) {
    if(L) {
        NoGen* aux = L;
        while(aux) {
            cb(aux->info);
            aux = aux->prox;
        }
    }
}