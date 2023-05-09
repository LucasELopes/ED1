#include "lista.c"

void main() {
    No *L = NULL;

    L = inseriFinal(L, 1);
    L = inseriFinal(L, 2);
    L = inseriFinal(L, 3);
    L = inseriFinal(L, 4);

    L = excluiInicio(L);
    L = excluiInicio(L);

    imprimirLista(L);
}