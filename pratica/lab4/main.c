#include "fila.h"

void imprimirInt(void *info) {
    printf("%d ", *((int*)info));
}

int main() {

    Fila *F = criarNo((void*)0);
   
    inserirFila(F, (void*)1);

    
    imprimirFila(F, imprimirInt);

    return 0;
}