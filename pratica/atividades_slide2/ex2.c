#include "lista.c"

void noRepeat(No **L1) {
    No *auxFixed = *L1;
    No *aux = NULL;
    No *pred = NULL;

    if(*L1 == NULL) return;
    else {
        pred = auxFixed;
        aux = pred->prox;

        while(auxFixed->prox != NULL) {
            while(aux != NULL) {
                if(aux->chave == auxFixed->chave) {
                    pred->prox = aux->prox;
                    free(aux);
                    aux = pred->prox;
                    continue;                    
                }
                pred = aux;
                aux = aux->prox;
            }
            auxFixed = auxFixed->prox;
            pred = auxFixed;
            aux = pred->prox;
        }
    }
}

void main() {
    No *L1 = NULL;

    printf("Lista 1 com repetições");
    L1 = inserirFinal(L1, 5);
    L1 = inserirFinal(L1, 2);
    L1 = inserirFinal(L1, 9);
    L1 = inserirFinal(L1, 3);
    L1 = inserirFinal(L1, 5);
    L1 = inserirFinal(L1, 1);
    L1 = inserirFinal(L1, 7);
    L1 = inserirFinal(L1, 2);
    L1 = inserirFinal(L1, 8);
    L1 = inserirFinal(L1, 3);
    imprimirLista(L1);

    printf("\nLista 1 sem repetições");
    noRepeat(&L1);
    imprimirLista(L1);

}