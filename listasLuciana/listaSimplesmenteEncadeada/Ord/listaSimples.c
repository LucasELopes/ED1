#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int chave;
    struct no *prox;
}No;

No* criarNo(int valor) {
    No *novoNo = (No*)calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("ERRO: Problemas com a alocacao de memoria!.\n");
        exit(1);
    }

    novoNo->prox = NULL;
    novoNo->chave = valor;
}

No* inserirFinal(No *L, int valor) {
    No *novoNo = criarNo(valor);
    No *aux = L;

    if(aux == NULL) L = novoNo;
    else {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novoNo;
    }

    return L;
}

No* buscaChaveOrd(No *L, int valor) {
    No *aux = L;
    if(L == NULL) return NULL;
    else {
        while (aux != NULL)
        {
            if(valor <= aux->chave) break;
            aux = aux->prox;
        }
        return aux;
    }
}

void imprimirLista(No *L) {
    if(L == NULL) return;
    No *aux = L;
    printf("\n");
    while(aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

No* insereOrd(No *L, int valor) {
    No *novoNo = criarNo(valor);
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) L = novoNo;
    else {
        while(aux != NULL && valor > aux->chave) {
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL) {
            novoNo->prox = L;
            L = novoNo;
        } 
        else {
            pred->prox = novoNo;
            novoNo->prox = aux;
        }
    }
    return L;
}

No* excluiChaveOrd(No *L, int valor) {
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL && valor > aux->chave) {
            pred = aux;
            aux = aux->prox;
        }
        if(aux != NULL && valor == aux->chave) {
            if(pred == NULL) L = aux->prox;
            else pred->prox = aux->prox;
            free(aux);
        }
        return L; 
    }
}

void main() {
    No *L = NULL;

    L = insereOrd(L, 12);
    L = insereOrd(L, 7);
    L = insereOrd(L, 2);
    L = insereOrd(L, 132);
    L = insereOrd(L, 1);

    imprimirLista(L);

    printf("Valor buscado: %d", buscaChaveOrd(L, 3)->chave);
}