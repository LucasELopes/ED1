#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int ch;
    struct no *prox, *ant;
}No;

typedef struct lista {
    struct no *inicio, *fim; 
}Lista;

Lista* criarLista() {
    Lista *novaLista = (Lista*)calloc(1, sizeof(Lista));

    if(novaLista == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    return novaLista;
}

No* criarNo(int ch) {
    No *novoNo = (No*) calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("Erro na alocação!\n");
    }

    novoNo->ch = ch;

    return novoNo;
}

void imprimirLista(Lista *L) {
    No *aux = L->inicio;

    if(L == NULL) {
        printf("Lista vazia!\n");
    }
    else {
        while(aux != NULL) {
            printf("%d ", aux->ch);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inserirInicio(Lista *L, int ch) {
    No *novoNo = criarNo(ch);

    if(L->inicio == NULL) {
        L->inicio = novoNo;
        L->fim = novoNo;
    }
    else {
        novoNo->prox = L->inicio;
        L->inicio->ant = novoNo;
        L->inicio = novoNo;
    }
}

void inserirFinal(Lista *L, int ch) {
    No *novoNo = criarNo(ch);

    if(L->fim == NULL) {
        L->inicio = novoNo;
        L->fim = novoNo;
    }
    else {
        L->fim->prox = novoNo;
        novoNo->ant = L->fim;
        L->fim = novoNo;
    }
}

void removeNo(Lista *L, int ch) {
    No *aux = L->inicio;

    if(L->inicio == NULL){}
    else {
        while(aux != NULL && aux->ch != ch) 
            aux = aux->prox;

        if(aux == L->inicio) {
            L->inicio = aux->prox;
        }
        if(aux == L->fim) {
            L->fim = aux->prox;
        }
        else if(aux != L->fim && aux != L->inicio) {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        free(aux);
    }
}

void main() {
    Lista *L = criarLista();

    inserirFinal(L, 1);
    inserirFinal(L, 2);
    inserirFinal(L, 3);
    inserirFinal(L, 4);
    inserirFinal(L, 5);

    removeNo(L, 1);

    imprimirLista(L);


}