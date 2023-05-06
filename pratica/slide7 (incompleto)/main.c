#include "lista.c"

void excluiChaveSelection(No **L, int index) {
    No *aux = *L;

    if(*L == NULL){}
    else {
        for(int i = 0; i < index; i++) {
            aux = aux->prox;
            if(aux == NULL) break;
        }
        if(aux == NULL) {
            printf("Nó não existe!\n");
        }
        else {
            if(aux->ant != NULL && aux->prox == NULL) {
                aux->ant->prox = NULL;
            }
            else {
                if(aux->ant == NULL) {
                    *L = aux->prox;
                }
                else {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                }
            }
            free(aux);
        }
    }
}

No* fusaoOrd(No *L1, No *L2) {
    No *auxL1 = L1;
    No *auxL2 = L2;

    if(auxL2 == NULL) {}
    else if (auxL1 == NULL) L1 = auxL2;
    else {
        while(auxL1->prox != NULL && auxL2 != NULL) {
            if(auxL1->chave < auxL2->chave) {
                auxL1 = auxL1->prox;
            }
            else {
                if(auxL1->ant == NULL) {
                    auxL1->ant = auxL2;
                    auxL2 = auxL2->prox;
                    auxL1->ant->prox = auxL1;
                }
                else {
                    auxL1->ant->prox = auxL2;
                    auxL1->ant->prox->ant = auxL1->ant;
                    auxL1->ant = auxL1->ant->prox;
                    auxL2 = auxL2->prox;
                    auxL1->ant->prox = auxL1;
                }
            }
        } 
    }

    if(auxL1->prox == NULL && auxL2 != NULL) {
        auxL1->prox = auxL2;
        auxL2->ant = auxL1;
    } 

    return L1;
}

void main() {
    No *L1 = NULL;

    insereOrd(&L1, 2);
    insereOrd(&L1, 122);
    insereOrd(&L1, 17);
    insereOrd(&L1, 92);
    insereOrd(&L1, 12);
    imprimiLista(&L1);

    No *L2 = NULL;

    insereOrd(&L2, 12);
    insereOrd(&L2, 13);
    insereOrd(&L2, 19);
    insereOrd(&L2, 22);
    insereOrd(&L2, 442);
    imprimiLista(&L2);

    No *L3 = fusaoOrd(L1, L2);

    imprimiLista(&L3);

}