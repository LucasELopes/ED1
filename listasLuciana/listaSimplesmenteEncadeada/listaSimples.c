#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
}No;

// Criação de nó.
No* criarNo(int valor) {
    No *novoNo = (No*)calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("ERRO: Problemas com a alocacao de memoria!.\n");
        exit(1);
    }

    novoNo->prox = NULL;
    novoNo->valor = valor;
}

void imprimirLista(No *L) {
    if(L == NULL) return;
    No *aux = L;
    printf("\n");
    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

No* inserirInicio(No *L, int valor) {
    No *novoNo =  criarNo(valor);
    novoNo->prox = L;
    L = novoNo;

    return L;
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

No* buscaChave(No *L, int valor) {
    No *aux = L;

    if(L == NULL) return NULL;
    else {
        while(aux != NULL) {
            if(aux->valor == valor) break;
            aux = aux->prox;
        }
    }
    return aux;
}

No* excluirInicio(No *L) {
    if(L == NULL) return NULL;
    No *aux = L->prox;
    L ->prox = NULL;
    free(L);

    return aux;
}

No* excluirFinal(No *L) {
    No *aux = L;
    No *pred = NULL;

    if(L == NULL) return NULL;
    else{
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

void main()
{
    No *L1 = NULL;

    printf("\nInserindo no inicio da L1");
    L1 = inserirInicio(L1, 1);
    L1 = inserirInicio(L1, 2);
    L1 = inserirInicio(L1, 3);
    L1 = inserirInicio(L1, 4);
    L1 = inserirInicio(L1, 5);
    L1 = inserirInicio(L1, 6);
    imprimirLista(L1);

//------------------------------------------------------------//

    No *L2 = NULL;

    printf("\nInserindo ao final da L2");
    L2 = inserirFinal(L2, 1);
    L2 = inserirFinal(L2, 2);
    L2 = inserirFinal(L2, 3);
    L2 = inserirFinal(L2, 4);
    L2 = inserirFinal(L2, 5);
    L2 = inserirFinal(L2, 6);
    imprimirLista(L2);

//------------------------------------------------------------//
    printf("\nRetirando a chave 2 da L2:\n%d\n", buscaChave(L2, 2)->valor);

    // printf("\nRetirando a chave 4 da L2: %d", buscaChave(L2, 4)->valor); // Falha de segmentacao.

//------------------------------------------------------------//

    printf("\nExcluindo no do inicio:");
    L2 = excluirInicio(L2);
    imprimirLista(L2);

//------------------------------------------------------------//

    printf("\nExcluindo no final:");
    L1 = excluirFinal(L1);
    imprimirLista(L1);

}
