#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

No* criaNo(int ch) {
    No* novoNo = (No*)calloc(1, sizeof(No));
    if(novoNo == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->chave = ch;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    return novoNo;
}

void imprimiLista(No **L) {
    No *aux = *L;
    printf("\n");
    while(aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

// Lista não ordenada.

No* buscaLista(No **L, int ch) {
    No *aux = *L;
    // Primeiro comparndo se o aux é diferente de null para entao verificar o valor.
    while(aux != NULL && ch != aux->chave) {
        // Caso seja o último nó da lista o loop encerra.
        if(aux->prox == NULL) break;
        // caso contrário vai para o próximo nó.
        aux = aux->prox;
    }
    // por fim retorna o nó.
    return aux;
}

void insereInicio(No **L, int ch) {
    No *aux = *L; // Aponto o aux para o inicio da lista
    No *novoNo = criaNo(ch); // Crio o novo nó.
    novoNo->prox = *L; // O proximo do novoNo aponta para o primeiro nó da lista
    if(*L != NULL) (*L)->ant = novoNo; // caso a lista já aponte para algum nó o respectivo apontarar anteriormente para o novoNo
    *L = novoNo; // A lista passará a aponta para o novoNo. 
}

void insereFinal(No **L, int ch) {
    No *aux = *L; // Aponta o aux para o iniciio da lista
    No *novoNo = criaNo(ch); 

    if(aux == NULL) *L = novoNo; // Caso a lista esteja vazia o L apontará para o novoNo
    else {
        while(aux->prox != NULL) { // Caso contrário percorrera até o último nó
            aux = aux->prox; // avançando os nós.
        }
        aux->prox = novoNo; // o último nó aponta para o novoNo
        novoNo->ant = aux; // novoNo anterior aponta para o último nó da lista (aux).
    }
}

void excluirInicio(No **L) {
    No* aux = *L;
    
    if(*L == NULL) return;
    *L = aux->prox;   
    if(*L != NULL) (*L)->ant = NULL;
    free(aux);
}

void excluirFinal(No **L) {
    No *aux = *L;

    if(L == NULL) {}
    else {
        if(aux->ant == NULL) L = NULL;
        else aux->ant->prox = NULL;
        free(aux);
    }
} 

// Lista Ordenada.

No* buscaOrd(No **L, int ch) {
    No *aux = *L;

    // O while vai continua até o aux ser igual NULL ou aux->chave ser maior que o ch.
    while(aux != NULL && aux->chave < ch) {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }

    return aux;
}

void insereOrd(No **L, int ch) {
    No *novoNo = criaNo(ch);
    No *aux = buscaOrd(&(*L), ch);
    // O aux sempre estara na frente da chave inserida, menos se o aux for o último.
    if(aux == NULL) *L = novoNo;
    else {
        if(aux->chave < ch) { // Verificando se o nó vai ser inserido no final da lista.
            aux->prox = novoNo;
            novoNo->ant = aux;
        }
        else {
            novoNo->prox = aux; // Como o novoNo não vai ser inserido após o aux, então o prox do novoNo é o aux;
            if(aux->ant == NULL) *L = novoNo;
            else {
                novoNo->ant = aux->ant;
                aux->ant->prox = novoNo;
            }
            aux->ant = novoNo;
        }
    }
}

void excluiChave(No **L, int ch) {
    No *aux = buscaOrd(&(*L), ch);
    if(aux == NULL || aux->chave != ch) {
        printf("Chave inexistente.\n");
    }
    else {
        if(aux != NULL) {
            if(aux->ant == NULL) *L = aux->prox;
            else aux->ant->prox = aux->prox;
            if(aux->prox != NULL) aux->prox->ant = aux->ant;
            free(aux);
        }
    }
}
