#include "arvore.h"

int main() {

    Arvore *A = NULL;
    imprime(A, 0);
    A = insere(A, 40);
    imprime(A, 0);
    A = insere(A, 35);
    // A = insere(A, 4);
    // A = insere(A, 9);
    // A = insere(A, 1237);
    imprime(A, 0);

    return 0;
}