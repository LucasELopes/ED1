#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criarNo(int chave) {
    No *novoNo = (No*) calloc(1, sizeof(No)); // novoNo receber uma espaço de memória.

    if(novoNo == NULL) { // caso não tenha espaço disponível novoNo receberá NULL
        printf("Erro na alocação!\n"); 
        exit(1); // o programa é encerrado.
    }

    novoNo->chave = chave; // caso contrário o novoNo apontará para a chave passa com parâmetro
    novoNo->prox = NULL; // e o próximo nó será NULL;
}

void imprimirLista(No *L) {
    No *aux = L; // aux recebe a lista

    printf("\n"); // primeiro \n para que a informações presente no terminal não atrapalhe a visualização da lista.
    while(aux != NULL) { // enquato aux for diferente de NULL os valores da lista serão imprimidos.
        printf("%d ", aux->chave);
        aux = aux->prox; // sempre indo para o próximo nó ate chegar em NULL;
    }
    printf("\n"); // o último \n para que a impressão da lista não se junte com outra informações possam posteriormente aparece no terminal
}

No* inserirInicio(No *L, int chave) {
    No *novoNo = criarNo(chave);

    novoNo->prox = L;
    L = novoNo;
}

No* inserirFinal(No *L, int chave) {
    No *aux = L;
    No *novoNo = criarNo(chave);
    
    if(L == NULL) L = novoNo;
    else {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novoNo;
    }

    return L;
}

No* buscarChave(No *L, int chave) {
    No *aux = L;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL) {
            if(aux->chave == chave) break;
        }
        return aux;
    }
}

No* excluirInicio(No* L) {
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) return NULL;
    L = aux->prox;
    free(aux);
    
    return L;
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
        if(pred == NULL) L = NULL;
        else pred->prox = NULL;
        free(aux);

        return L;
    }

}

No* excluirChave(No* L, int chave) {
    No *aux = L;
    No *pred = NULL; 

    if(L == NULL) return NULL;
    else {
        while(aux != NULL && aux->chave != chave) {
            pred = aux;
            aux = aux->prox;
        }

        if(aux != NULL) {
            if(pred == NULL) L = aux->prox;
            else pred->prox = aux->prox;
            free(aux);
        }

        return L;
    }
}

No *buscaListaOrd(No *L, int valor, No **pred) {
    No *aux = L;
    (*pred) = NULL;
    if(L == NULL) return NULL;
    else {
        while(aux != NULL && valor > aux->chave) {
            (*pred) = aux;
            aux = aux->prox;
        }
        return aux;
    }
}

No* buscarChaveOrd(No *L, int chave) {
    No *aux = L;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL && chave >= aux->chave){
            if(aux->chave == chave) return aux;
            aux = aux->prox;
        }
    }
    return L;
}

No* inserirOrd(No *L, int chave) {
    No* pred = NULL;
    No* aux = buscaListaOrd(L, chave, &pred);
    No* novoNo = criarNo(chave);

    if(pred == NULL) {
        novoNo->prox = L;
        L = novoNo;
    }
    else {
        pred->prox = novoNo;
        novoNo->prox = aux;
    }
    return L;
}

No* excluirOrd(No *L, int chave) {
    No *pred = NULL;
    No *aux = buscaListaOrd(L, chave, &pred);

    if(aux != NULL) {
        if(pred == NULL) L = aux->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
    
    return L;
}

