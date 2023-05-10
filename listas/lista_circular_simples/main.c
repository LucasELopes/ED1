#include "lista.c"

void main() {
    No *L = NULL;

    L = inseriFinal(L, 1);
    L = inseriFinal(L, 2);
    L = inseriFinal(L, 3);
    L = inseriFinal(L, 4);

    L = excluiFim(L);
    L = excluiFim(L);
    L = excluiFim(L);
    L = excluiFim(L);

    imprimirLista(L);
}