#include "arvore.h"

Arvore* criaNo(int info) {
    Arvore* newLeaf = (Arvore*)calloc(1, sizeof(Arvore));

    if(!newLeaf) {
        printf("Erro na aloção!\n");
        exit(1);
    }

    newLeaf->info = info;
    return newLeaf;
}

Arvore* busca(Arvore *A, int info, Arvore **pred) {
    Arvore* aux = A;
    
    if(aux != NULL) {
        if(aux->info == info) aux = NULL;
        else if (info < aux->info) busca(aux->esq, info, pred = &aux);
        else busca(aux->dir, info, pred = &aux);
    }
    return aux;

    // if(A != NULL) {
    //     while (aux != NULL) {
    //         if(aux->info == info) break;
    //         else if(info < aux->info) {
    //             pred = aux;
    //             aux = aux->esq;
    //         }
    //         else {
    //             pred = aux;
    //             aux = aux->dir;
    //         }
    //     }
    // }
    // return aux;
}

Arvore* insere(Arvore *A, int info) {
    if(A == NULL) 
        return criaNo(info);

    Arvore *pred = NULL;
    Arvore *aux = busca(A, info, &pred);

    if(pred == NULL && aux == NULL) 
        return criaNo(info);
    else if(aux->info != info) {
        Arvore *newLeaf = criaNo(info);
        if(aux == NULL) {
            if(info < pred->info)
                pred->esq = newLeaf;
            else 
                pred->dir = newLeaf;
        }
    }
    return A;
}

void imprime(Arvore *A, int nivel) {
    Arvore *aux = A;
    if(aux) {
        while(nivel)
            printf("\t");
        printf("%d\n", aux->info);
        if(aux->esq != NULL)
            imprime(aux->esq, ++nivel);
        if(aux->dir != NULL)
            imprime(aux->dir, ++nivel);
    }
    else {
        printf("Árvore vazia!\n");
    }
}