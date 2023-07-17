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
    novoNo->prox = F;
    novoNo->ant = F->ant;
    F->ant->prox = novoNo;
    F->ant = novoNo;
}

Fila* retirarDaFila(Fila *F) {
    Fila* aux = F->prox;

    if(F->prox != F) {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        aux->prox = aux;
        aux->ant = aux;
        return aux;
    } 
    return NULL;
}

void destruirFila(Fila *F) {
    if(F->prox != F) {
        Fila *aux = F->prox;
        F->prox = F;
        F->ant = F;
        while(aux != F) {
            if(aux->prox == F) {
                free(aux);
                break;
            }
            else {
                aux = aux->prox;
                free(aux->ant);
            }
        }
    }
}

void imprimirFila(Fila *F, void (*cb) (void*)) {
    Fila *aux = F->prox;
    while (aux != F) {
        cb(&aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

