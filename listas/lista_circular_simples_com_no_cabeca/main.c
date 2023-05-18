#include "lista.c"

void main() {
    No *L = criaLista();

    inseriFinal(L, 1);
    inseriFinal(L, 2);
    inseriFinal(L, 3);
    inseriFinal(L, 4);
    inseriFinal(L, 5);

    excluiFim(L);
    excluiFim(L);
    excluiFim(L);
    excluiFim(L);
    excluiFim(L);
    
    imprimirLista(L);
}