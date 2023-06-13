#include "fila.h"

Fila* criarNo(void *info) {
    Fila *novoNo = (Fila*)calloc(1, sizeof(Fila));

    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }
    novoNo->info = info;
    novoNo->prox = novoNo;
    novoNo->ant = novoNo;
    return novoNo;
}

void inserirFila(Fila *F, void *info) {
    Fila* novoNo = criarNo(info);
    if(F->prox == F) {
        F->prox = novoNo;
        novoNo->prox = F;
    }
}

Fila* retirarDaFila(Fila *F) {
    Fila *aux = NULL;
    if(F->prox != F) {
        aux = F->prox;
        aux->prox->ant = F;
        F->prox = aux->prox;
    }
    return aux;
}

void imprimirFila(Fila *F, void (*cb) (void*)) {
    Fila* aux = F->prox;
    if(aux == F)
        printf("Fila vazia!\n");
    else {
        while(aux != F) {
            cb(aux->info);
            aux = aux->prox;
        }
    }
}

void destruirFila(Fila *F) {
    Fila *aux = F->ant;
    do{
        F->ant = aux->ant;
        free(aux);
        aux = F->ant;
    }while(aux != F);
    F->prox = F;
}

