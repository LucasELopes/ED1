#include "arvore.h"

int main() {
    No *A = NULL;

    inserirArvore(&A, 184);
    inserirArvore(&A, 115);
    inserirArvore(&A, 237);
    inserirArvore(&A, 47);
    inserirArvore(&A, 138);
    inserirArvore(&A, 212);
    inserirArvore(&A, 296);
    inserirArvore(&A, 30);
    inserirArvore(&A, 86);
    inserirArvore(&A, 130);
    inserirArvore(&A, 159);
    inserirArvore(&A, 206);
    inserirArvore(&A, 219);
    inserirArvore(&A, 258);
    inserirArvore(&A, 307);
    inserirArvore(&A, 95);
    inserirArvore(&A, 166);
    inserirArvore(&A, 224);
    inserirArvore(&A, 314);

    // imprimirArvore(&A, 1);

    removerNo(&A, 314);
    removerNo(&A, 307);
    removerNo(&A, 296);
    removerNo(&A, 258);
    removerNo(&A, 237);
        
    
    // removerNo(&A, 47);
    imprimirArvore(&A, 1);
}