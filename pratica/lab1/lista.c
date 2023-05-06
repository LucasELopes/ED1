#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Mon* criarMon(int numero, int incognita) {
    Mon *novoMon = (Mon*)calloc(1, sizeof(Mon));
    if(novoMon == NULL) return NULL;
    
    novoMon->numero = numero;
    novoMon->incognita = incognita;
    novoMon->prox = NULL;

    return novoMon;
}

Mon* inserirOrd(Mon *P, int numero, int incognita) {
    Mon *novoMon = criarMon(numero, incognita);
    Mon *aux = P;
    Mon *pred = NULL;

    if(P == NULL) P = novoMon;
    else {
        while(aux != NULL && aux->incognita >= incognita) {
            if(aux->incognita == incognita) {
                aux->numero += numero;
                free(novoMon);
                return P;
            }
            pred = aux;
            aux = aux->prox;
        } 
        if(pred == NULL) {
            novoMon->prox = P;
            P = novoMon;
        }
        else {
            pred->prox = novoMon;
            novoMon->prox = aux;
        }
    }
    return P;
}

void imprimirPol(Mon *P) {
    Mon *aux = P;

    printf("\n");
    while(aux != NULL) {
        printf("%d^%d ", aux->numero, aux->incognita);
        aux = aux->prox;
    }
    printf("\n");
}

// Mon* somaSubPol(Mon *P1, Mon *P2, char operacao) {
//     Mon *auxP1 = P1;
//     Mon *auxP2 = P2;
//     Mon *lixo = NULL;
//     if(auxP1 != NULL && auxP2 == NULL) return P1; // Verificação do conteudo dos Polinomos
//     else if(auxP1 == NULL && auxP2 != NULL) return P2;
//     else if(auxP1 == NULL && auxP2 == NULL) return NULL;
//     else {
//         while(auxP1 != NULL && auxP2 != NULL) { // Garantindo que os ponteiro auxilares nao sao null para futuras verificoes
//             if(auxP1->incognita == auxP2->incognita) { // Caso o numero das incognita essa iguais ocorrerá a soma no monominio da P1
//                 if(operacao == '+' ) auxP1->numero += auxP2->numero;
//                 else if(operacao == '-') auxP1->numero -= auxP2->numero;
//                 auxP1 = auxP1->prox; // O auxliar tanto da P1 e P2 vai para o proximo monomio. 
//                 lixo = auxP2;
//                 auxP2 = auxP2->prox;
//                 free(lixo);
//             }
//             else if(auxP1->incognita < auxP2->incognita) { // Caso a incognita do ponteiro auxP2 seja maior que o do auxP1 vou apenas inserir o mesmo
//                 P1 = inserirOrd(P1, auxP2->numero, auxP2->incognita); // de forma ordenada no P1;
//                 auxP2 = auxP2->prox; // E o auxP2 aponta para o proximo monomio
//             }
//             else {
//                 auxP1 = auxP1->prox; // caso contrario o auxP1 vai para o proximo monomio
//             }
//             if(auxP1->prox == NULL && auxP2 != NULL) { // caso o auxP1 esteja na ultima posicao e a auxP2 nao seja vazio, o programa fará a seguintes verificações
//                 if(auxP1->incognita == auxP2->incognita) { // se o expoente da incognita do auxP1 e auxP2 é igual.
//                     if(operacao == '+' ) auxP1->numero += auxP2->numero; // caso seja fará a respectiva operação que foi passada com argumento.
//                     else if(operacao == '-') auxP1->numero -= auxP2->numero; 
//                     lixo = auxP2; // lixo apontará p/ o auxP2.
//                     auxP2 = auxP2->prox; // auxP2 vai para o proximo valor da lista.
//                     free(lixo); // o lixo é limpado
//                 }
//                 auxP1->prox = auxP2;    // e o ultimo termo da P1 aponta para o auxP2.
//                 break; // O laço é quebrado
//             }
//         }
//         P2 = NULL; // como todas as modificações e inserções estam no P1, logo a P2 pode aponta para NULL sem problemas.
//         // free(P2);
//         return P1; // O P1 é retornado com as suas respectivas operações aritmeticas realizadas e as inclusoes dos monomios
//     }
// }

Mon* somaSubPol(Mon *P1, Mon *P2, char operacao) { // Funcao responsavel por fazer a adição e subtração dos polinomios
    Mon *auxP1 = P1;
    Mon *auxP2 = P2;
    Mon *P3 = NULL;
    Mon *auxP3 = P3;

    if(auxP1 != NULL && auxP2 == NULL) return P1; // Verificação do conteudo dos Polinomos
    else if(auxP1 == NULL && auxP2 != NULL) return P2;
    else if(auxP1 == NULL && auxP2 == NULL) return NULL;
    else {
        while(auxP1 != NULL && auxP2 != NULL) {
            if(auxP1->incognita == auxP2->incognita) {
                if(operacao == '+') P3 = inserirOrd(P3, auxP1->numero + auxP2->numero, auxP1->incognita);
                else P3 = inserirOrd(P3, auxP1->numero - auxP2->numero, auxP1->incognita);
                auxP1 = auxP1->prox;
                auxP2 = auxP2->prox;
            }
            else if(auxP1->incognita < auxP2->incognita) {
                P3 = inserirOrd(P3, auxP2->numero, auxP2->incognita);
                auxP2 = auxP2->prox;
            }
            else {
                P3 = inserirOrd(P3, auxP1->numero, auxP1->incognita);
                auxP1 = auxP1->prox;
            }
        }
        return P3;
    }

}

Mon* produtoPol(Mon *P1, Mon *P2) {
    Mon *auxP1 = P1;
    Mon *auxP2 = P2;
    // Mon *novoMon = NULL;
    Mon *P3 = NULL;

    if(auxP1 == NULL && auxP2 != NULL) P3 = auxP2;
    else if(auxP1 != NULL && auxP2 == NULL) P3 = auxP1;
    else if(auxP1 == NULL && auxP2 == NULL) return NULL;
    else {
        while(auxP1 != NULL) {
            while (auxP2 != NULL)
            {   
                P3 = inserirOrd(P3, auxP1->numero * auxP2->numero, auxP1->incognita + auxP2->incognita);
                // free(novoMon);
                auxP2 = auxP2->prox;
            }
            auxP1 = auxP1->prox;
            auxP2 = P2;
        }
    }
    return P3;
}


