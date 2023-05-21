#include "lista.h"

No* criaLista() {
    No *novaLista = (No*)calloc(1, sizeof(No));

    if(novaLista == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novaLista->prox = novaLista;
    novaLista->ant = novaLista;

    return novaLista;
}

No* criaNo(int ch) {
    No *novoNo = (No*)calloc(1, sizeof(No));
    if(novoNo == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->chave = ch;
    novoNo->prox = novoNo;
    novoNo->ant = novoNo;
    return novoNo;
}

void imprimirLista(No *L) {
    if(L == L->prox)
        printf("Lista vazia!\n");
    else {
        No *aux = L->prox;
        do{
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while (aux != L);
        printf("\n");
    }
}

void insereInicio(No *L, int ch) {
    No *novoNo = criaNo(ch);
    
    if(L->prox == L) {
        L->ant = novoNo;
        novoNo->prox = L;
    }
    else{
        novoNo->prox = L->prox;
        novoNo->prox->ant = novoNo;
    }
    novoNo->ant = L;
    L->prox = novoNo;
}

void insereFinal(No *L, int ch) {
    No *novoNo = criaNo(ch);

    novoNo->prox = L;
    if(L->prox == L) {
        novoNo->ant = L;
        L->prox = novoNo;
    }else {
        No *aux = L->prox;
        while(aux->prox != L)
            aux = aux->prox;
        
        aux->prox = novoNo;
        novoNo->ant = aux;
    }
    L->ant = novoNo;
}

void excluiInicio(No *L) {
    if(L->prox == L) return;
    else {
        No *aux = L->prox;
        L->prox = L->prox->prox;
        L->prox->ant = L;
        free(aux);
    }
}

void excluiFinal(No *L) {
    if(L->prox == L) return;
    else {
        No *aux = L->prox;
        while(aux->prox != L) 
            aux = aux->prox;
        aux->ant->prox = L;
        L->ant = aux->ant;
        free(aux);
    }
}
