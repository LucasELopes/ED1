#include "fila.h"

Fila* criarNo(void *info) {
    Fila *novoNo = (Fila*)calloc(1, sizeof(Fila));

    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->prox = novoNo;
    novoNo->ant = novoNo;
    novoNo->info = info;

    return novoNo;
}

void inserirFila(Fila *F, void *info) {
    Fila* novoNo = criarNo(info);

    novoNo->ant = F->ant;
    novoNo->prox = F;
    F->ant = novoNo;
    if(F->prox == F)
        F->prox = novoNo;
}

void imprimirFila(Fila *F, void (*cb) (void*)) {
    Fila *aux = F->prox;
    while (aux != F) {
        cb(aux->info);
        aux = aux->prox;
    }
    printf("\n");
}




