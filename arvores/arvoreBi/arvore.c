#include "arvore.h"

NoArvore* criarNoArvore(int chave) {
    NoArvore *novoNo = (NoArvore*)calloc(1, sizeof(NoArvore));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->chave = chave;
    return novoNo;
}

NoPilha* criarNoPilha(NoArvore *info) {
    NoPilha *novoNo = (NoPilha*)calloc(1, sizeof(NoPilha));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }   

    novoNo->info = info;
    return novoNo;
}

void inserirPilha(NoPilha *pilha, NoArvore *info) {
    NoPilha *novoNo = criarNoPilha(info);
    if(pilha) {
        novoNo->prox = pilha;
    }
    pilha = novoNo;
}

NoPilha* removerPilha(NoPilha *pilha) {
    NoPilha *aux = NULL;
    if(pilha) {
        aux = pilha;
        pilha = pilha->prox;
    }
    return aux;
}

void imprimirArvore(NoArvore **A) {
    NoPilha *pilha = NULL;
    NoArvore *aux = *A;
    int nivel = 1;
    
    printf(aux->chave);
    do {
        if(aux->dir || aux->esq) {
            if(aux->dir) {
                printf("%d",aux->dir->chave);
                inserirPilha(pilha, aux->dir);
            }
            if(aux->esq) {
                printf("%d",aux->dir->chave);
                inserirPilha(pilha, aux->esq);
            }
        }
        else {

        }    

    }while(pilha);

}