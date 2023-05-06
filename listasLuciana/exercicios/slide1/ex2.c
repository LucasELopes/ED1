#include "lista.c"

No *repetidosNo(No *L) {
    No *comparado = L;
    No *aux = L->prox;
    No *pred = NULL;

    if(L == NULL) return NULL;
    else {
        while(comparado != NULL && comparado->prox != NULL) {
            while(aux != NULL) {
                if(aux->chave == comparado->chave) {
                    if(pred == NULL) {
                        comparado->prox = aux->prox;
                        free(aux);
                        aux = comparado->prox;
                    }    
                    else {
                        pred->prox = aux->prox;
                        free(aux);
                        aux = pred->prox;
                    } 
                }
                pred = aux;
                aux = aux->prox;
            }
            comparado = comparado->prox;
            aux = comparado->prox;
            pred = NULL;
        }
    }
    return L;
}

void main() {
    No * L = NULL;
    
    L = insereFinal(L, 1);
    L = insereFinal(L, 1);
    L = insereInicio(L, 2);
    // L = insereInicio(L, 4);
    L = insereInicio(L, 19);
    L = insereInicio(L, 9);
    L = insereInicio(L, 19);

    imprimirLista(L);

    L = repetidosNo(L);
    imprimirLista(L);
}