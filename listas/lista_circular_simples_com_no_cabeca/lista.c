#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprimirLista(No *L) {
    if(L->prox == L) {
        printf("Lista vazia.\n");
    }
    else {
        No *aux = L->prox;
        do {
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while(aux != L);
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

No* criaLista() {
    No *novaLista = (No*)calloc(1, sizeof(No));

    if(novaLista == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    } 
    novaLista->prox = novaLista;
    return novaLista;
}

void inseriInicio(No *L, int ch) {
    No *novoNo = criaNo(ch);
    
    if(L->prox == L) {
        L->prox = novoNo;
        novoNo->prox = L;
    }
    else {
        novoNo->prox = L->prox;
        L->prox = novoNo;        
    }
}

void inseriFinal(No *L, int ch) {
    No *novoNo = criaNo(ch);

    if(L->prox == L) {
        L->prox = novoNo;
        novoNo->prox = L;
    }else {
        No *aux = L->prox;
        
        while(aux->prox != L) 
            aux = aux->prox;
        
        novoNo->prox = L;
        aux->prox = novoNo;
    }
}

void excluiInicio(No *L) {
    if(L->prox == L) return;
    else {
        No *aux = L->prox;
        if(L->prox == aux->prox->prox) {
            L->prox = L;
        }
        else {
            L->prox = aux->prox;
        }
        free(aux);
    }
}

void excluiFim(No *L) {
    if(L->prox == L)return;
    else {
        No *aux = L->prox;
        if(L->prox == aux->prox->prox) {
            L->prox = L;
        }
        else {
            while(aux->prox->prox != L)
                aux = aux->prox;
            free(aux->prox);
            aux->prox = L;
        }
    }
}