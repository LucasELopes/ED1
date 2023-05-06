#include "lista.c"

void concatenarLista(No **L1, No **L2) {
    /*
        A função recebe dois parâmetros ponteiro de ponteiro do tipo No, o conteudo 
        do L2 será inserida ao final do L1.
    */
    No *aux = *L1;

    if(*L1 == NULL && *L2 != NULL) {
        *L1 = *L2;
        *L2 = NULL;
    } 
    else if(*L1 != NULL && *L2 != NULL) {
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox= *L2;
        *L2 = NULL;
    }
}


void main() {
    No *L1 = NULL;
    No *L2 = NULL;

    printf("Lista 1");
    L1 = inserirOrd(L1, 32);
    L1 = inserirOrd(L1, 12);
    L1 = inserirOrd(L1, 37);
    L1 = inserirOrd(L1, 17);
    L1 = inserirOrd(L1, 1);
    imprimirLista(L1);

    printf("\nLista 2");
    L2 = inserirOrd(L2, 19);
    L2 = inserirOrd(L2, 72);
    L2 = inserirOrd(L2, 34);
    L2 = inserirOrd(L2, 92);
    L2 = inserirOrd(L2, 119);
    imprimirLista(L2);

    printf("\nConcatenando Lista 1 e 2");
    concatenarLista(&L1, &L2);
    imprimirLista(L1);

}