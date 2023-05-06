#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criaNo(int valor) {
    No *novoNo = (No*) calloc(1, sizeof(No));
    
    if(novoNo == NULL) {
        printf("ERRO: alocação mal sucedida!");
        exit(1);
    }

    novoNo->chave = valor;
    novoNo->prox = NULL;

    return novoNo;
} 

No* insereInicio(No *L, int valor) {
    No *novoNo = criaNo(valor);
    novoNo->prox = L;
    L = novoNo;
    return L;    
}

No* insereFinal(No *L, int valor) {
    No *novoNo = criaNo(valor);
    No *aux = L;

    if(L == NULL) L = novoNo;
    else {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novoNo;
    }
    return L;
}

No* buscaChave(No *L, int valor) {
    No *aux = L;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL && aux->chave != valor) aux = aux->prox;
    }
    return aux;
}

No* excluirInicio(No *L) {
    No *aux = L;
 
    if(L == NULL) return NULL;
    else {
        L = L->prox;
        free(aux);
    }
    return aux;
}

No* excluirFinal(No *L) {
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) return NULL;
    else {
        while(aux->prox != NULL) {
            pred = aux;
            aux = aux->prox; 
        }
        if(pred == NULL) L = aux->prox;
        else pred->prox = NULL;
        free(aux);
    }
    return L;
}

No* excluirChave(No *L, int chave) {
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL && aux->chave != chave) {
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL) L = L->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
    return L;
}

void imprimirLista(No *L) {
    No *aux = L;
    if(L == NULL) return;
    else {
        printf("\n");
        while(aux != NULL) {
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
        printf("\n");
    }
}