#include "lista.h"

void imprimirInt(void *info) {
    printf("%d ", *((int*)info));
}



int main() {
    NoGen *L = NULL;

    L = inserirInicio(L, criarNo((void*)1));
    L = inserirInicio(L, criarNo((void*)2));
    L = inserirInicio(L, criarNo((void*)3));
    L = inserirInicio(L, criarNo((void*)4));
    L = inserirInicio(L, criarNo((void*)5));

    imprimirLista(L, imprimirInt);

    return 0;
}