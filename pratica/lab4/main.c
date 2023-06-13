#include "fila.h"

void imprimirInt(void *info) {
    int* info_int = (int *)info;
    printf("%d ", *info_int);
}

int main() {
    Fila *F = criarNo((void*)0);

    inserirFila(F, (void*)1);
    // inserirFila(F, (void*)2);
    // inserirFila(F, (void*)3);
    
    imprimirFila(F, imprimirInt);

    return 1;
}