#include "lista.c"

No* concatenaLista(No *L1, No *L2) {
    No *aux = L1;
    if(L1 == NULL && L2 != NULL) return L2;
    else if (L1 != NULL && L2 == NULL) return L1;
    else if(L1 == NULL && L2 == NULL) return NULL;
    else {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = L2;
        L2 = NULL;
        free(L2);
    } 
    return L1;
}

void main() {
    // 1- Escrever uma função que recebe duas listas L1 e L2 e as concatena.

    // Criando o L1:
    No *L1 = NULL;
    L1 = insereInicio(L1, 1);
    L1 = insereInicio(L1, 2);
    L1 = insereInicio(L1, 3);
    L1 = insereInicio(L1, 4);
    L1 = insereInicio(L1, 5);
    imprimirLista(L1);

    No *L2 = NULL;
    L2 = insereFinal(L2, 0);
    L2 = insereFinal(L2, -1);
    L2 = insereFinal(L2, -2);
    L2 = insereFinal(L2, -3);
    L2 = insereFinal(L2, -4);
    imprimirLista(L2);

    imprimirLista(concatenaLista(L1, L2));

}


