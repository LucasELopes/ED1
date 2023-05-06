#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprimirLista(No *L) {
    No *aux = L;
    while (aux != NULL) {
        
    }
    
}

No* criaNo(int ch) {    
    No *novoNo = (No*) calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("Falha na alocação!");
        eixt(1);
    }

    novoNo->prox = NULL;
    novoNo->ant = NULL;
    novoNo->chave = ch;

    return novoNo;
}

No* buscaLista(No *L, int ch) {
    No *aux = L;
    
    while(aux != NULL && aux->chave != ch) {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }

    return aux;
}

No* buscaListaOrd(No *L, int ch) {
    No *aux = L;

    while(aux != NULL && aux->chave < ch) {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }

    return aux;
}

No* inserirInicio(No *L, int ch) {
    No *novoNo = criaNo(ch);
    novoNo->prox = L;
    if(L != NULL) L->ant = novoNo;
    return novoNo;
}

No* inserirFinal(No *L, int ch) {
    No *novoNo = criaNo(ch);
    No *aux = L;

    if(L == NULL) L = novoNo;
    else {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novoNo;
        novoNo->ant = aux;
    }
    return L;
}

No* insereOrd(No *L, int ch) {
    No *novoNo = criaNo(ch);
    No *aux = buscaListaOrd(L, ch);

    if(L == NULL) L = novoNo;
    else {
        if(aux->chave < ch) {
            aux->prox = novoNo;
            novoNo->ant = aux;
        }
        else {
            novoNo->prox = aux;
            if(aux->ant == NULL) L = novoNo;
            else {
                aux->ant->prox = novoNo;
                novoNo->ant = aux->ant;
            }
            aux->ant = novoNo;
        }
    }

}

No* excluiInicio(No *L) {
    No *aux = L;

    if(L == NULL) return NULL;
    L = aux->prox;
    if(L != NULL) L->ant = NULL;
    free(aux);
    return aux;

}

No* excluiFinal(No *L) {
    No *aux = L;

    if(L == NULL) return NULL;
    else {
        if(aux->ant == NULL) L = NULL;
        else {
            aux->ant->prox = NULL;
        }
        free(aux);
        return L;
    }
}

No* excluiChave(No *L, int ch) {
    No *aux = buscaListaOrd(L, ch);

    if(aux == NULL && aux->chave != NULL) {
        printf("Chave inexistente!.\n");
    }
    else {
        if(aux != NULL) {
            if(aux->ant == NULL) L = aux->prox;
            else aux->prox->ant = aux->prox;
            if(aux->prox != NULL) aux->ant->prox = aux->ant;
            free(aux);
        }
    }
    return L;
}
