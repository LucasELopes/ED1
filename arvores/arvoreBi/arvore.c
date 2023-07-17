#include "arvore.h"

No* criarNo(int chave) {
    No *novoNo = (No*)calloc(1, sizeof(No));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->chave = chave;
    return novoNo;
}

void imprimirArvore(No **A, int nivel) {
    // Pré-ordem
    if(*A) {
        for(int i = 0; i < nivel; i++)
            printf("-");
        printf("%d\n", (*A)->chave);
        if((*A)->esq) imprimirArvore(&(*A)->esq, nivel+1);
        if((*A)->dir) imprimirArvore(&(*A)->dir, nivel+1);
    }

    // Ordem simétrica
    // if(*A) {
    //     if((*A)->esq) imprimirArvore(&(*A)->esq, nivel+1);
    //     for(int i = 0; i < nivel; i++)
    //         printf("-");
    //     printf("%d\n", (*A)->chave);
    //     if((*A)->dir) imprimirArvore(&(*A)->dir, nivel+1);
    // }

    //Pós Ordem
    // if(*A) {
    //     if((*A)->esq) imprimirArvore(&(*A)->esq, nivel+1);
    //     if((*A)->dir) imprimirArvore(&(*A)->dir, nivel+1);
    //     for(int i = 0; i < nivel; i++)
    //         printf("-");
    //     printf("%d\n", (*A)->chave);
    // }

}

No* busca(No **A, int ch, No **pred) {
    No* aux = *A;
    while(aux) {
        if(aux->chave == ch) break;
        else if(aux->chave > ch) {
            *pred = aux;
            aux = aux->esq;
        }
        else {
            *pred = aux;
            aux = aux->dir;
        }    
    }
    return aux;
}

void inserirArvore(No **A, int ch) {
    No *pred = NULL;
    No *aux = busca(A, ch, &pred);
    if(!(*A)) {
        *A = criarNo(ch);
    }
    else {
        if(aux) 
            printf("Chave já existente na arvore!\n");
        else {
            No *novoNo = criarNo(ch);
            if(pred->chave < ch)
                pred->dir = novoNo;
            else 
                pred->esq = novoNo;
        }
    }
}

No* sucessor(No **A, No **pred) {
    No *aux = (*A)->dir;
    if(!aux)
        return NULL;
    else {
        while(aux->esq) {
            *pred = aux;
            aux = aux->esq;
        }
        return aux;
    }
}

void removerNo(No **A, int ch) {
    No *pred = NULL;
    No *aux = busca(A, ch, &pred);
    if(aux) {
        if(aux->dir == NULL && aux->esq == NULL) {
            if(!pred)
                free(aux);
            else {
                if(pred->esq == aux)
                    pred->esq = NULL;
                else 
                    pred->dir = NULL;
                free(aux);
            }
        }
        else {
            if(aux->dir && aux->esq) {
                No *paiSuc = NULL;
                No *suc = sucessor(&aux, &paiSuc);
                aux->chave = suc->chave;
                if(!paiSuc)
                    aux->dir = suc->dir;
                else
                    paiSuc->esq = suc->dir;
                free(suc);
            }
            else {
                if(pred->dir == aux) {
                    if(aux->dir)
                        pred->dir = aux->dir;
                    else
                        pred->dir = aux->esq;
                }else {
                    if(aux->esq)
                        pred->esq = aux->dir;
                    else
                        pred->esq = aux->esq;
                }
                free(aux);
            }
        }
    }
}