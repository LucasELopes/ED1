#include "lista.c"

void concatenaOrd(No **L1, No **L2) {
    No *auxL1 = *L1; // O(1)
    No *predL1 = NULL; // O(1)
    No *auxL2 = *L2; // O(1)
 
    if(*L1 == NULL && *L2 != NULL) *L1 = *L2; // O(1)
    while(auxL1 != NULL && auxL2 != NULL) { // O(n) 
        if(auxL1->chave < auxL2->chave) { // O(1)
            predL1 = auxL1; // O(1)
            auxL1 = auxL1->prox; // O(1)
        }
        else {
            predL1->prox = auxL2; // O(1)
            predL1 = auxL2;
            auxL2 = auxL2->prox; // O(1)
            predL1->prox = auxL1; // O(1)
        }
    }
    if(*L2 != NULL) { // O(1)
        predL1->prox = auxL2; // O(1)
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

    printf("\n\"Fusão\" da Lista 1 e 2");
    concatenaOrd(&L1, &L2);
    imprimirLista(L1);
}