#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprimirLista(No *L) {
    if(L == NULL) {
        printf("Lista vazia.\n");
    }
    else {
        No *aux = L->prox;
        do {
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while(aux != L->prox);
        printf("\n");
    }
}

No* criaNo(int ch) {
    No *novoNo = (No*)calloc(1, sizeof(No));
    if(novoNo == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->chave = ch;
    return novoNo;
}

No* inseriInicio(No *L, int ch) {
    No *novoNo = criaNo(ch);
    
    if(L == NULL) {
        novoNo->prox = novoNo;
        L = novoNo;
    }else {
        novoNo->prox = L->prox;
        L->prox = novoNo;
    }
    return L;
}

No* inseriFinal(No *L, int ch) {
    No *novoNo = criaNo(ch);

    if(L == NULL) {
        novoNo->prox = novoNo;
        L = novoNo;
    }else {
        No *aux = L->prox;
        L->prox = novoNo;
        L = novoNo;
        L->prox = aux;
    }
    return L;
}

No* excluiInicio(No *L) {
    if(L == NULL) return NULL;
    else {
        No *aux = L->prox;
        if(L->prox == L) {
            L = NULL;
        }else {
            L->prox = aux->prox;
        }
        free(aux);
    }
    return L;
}

No* excluiFim(No *L) {
    No *aux = L->prox;

    if(L == NULL) return NULL;
    if(L->prox == L) L = NULL;
    else {
        while(aux->prox != L) 
            aux = aux->prox;
        L = aux;
        aux = L->prox;
        L->prox = aux->prox;
    }
    free(aux);
    return L;
}