#include "lista.h"

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
    No *aux = L;

    if(aux == NULL)
        printf("Lista vazia!\n");
    else {
        do{
            printf("%d ", aux->chave);
            aux = aux->prox;
        }while (aux != L);
        printf("\n");
    }
}

No* insereInicio(No *L, int ch) {
    No *novoNo = criaNo(ch);

    if(L == NULL) {
    }
    else {
        novoNo->prox = L;
        novoNo->ant = L->ant;
        L->ant->prox = novoNo;
        L->ant = novoNo;
    }

    return L = novoNo;
}

No* insereFinal(No *L, int ch) {
    No *aux = L;
    No *novoNo = criaNo(ch);

    if(L == NULL) {
        L = novoNo;
    }
    else {
        while(aux->prox != L)
            aux = aux->prox;

        novoNo->ant = aux;
        aux->prox = novoNo;
        L->ant = novoNo;
        novoNo->prox = L;
    }
    return L;
}

No* excluiInicio(No *L) {
    if(L == NULL)
        return NULL;
    else {
        No *aux = L;
        if(L->prox == L)
            L = NULL;
        else {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            L = aux->prox;
        }
        free(aux);
    }
    return L;
}

No* excluiFinal(No *L) {

    if(L == NULL)
        return NULL;
    else {
        No *aux = L;

        if(L->prox == L) 
            L = NULL;
        else {
            while(aux->prox != L)
                aux = aux->prox;
            aux->ant->prox = L;
            L->ant = aux->ant;
        }
        free(aux);
        return L;
    }    

}