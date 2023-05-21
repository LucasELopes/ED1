#include "lista.h"

int main() {
    No *L = criaLista();

    insereInicio(L, 1);
    insereInicio(L, 2);
    insereInicio(L, 3);
    insereInicio(L, 4);
    insereInicio(L, 5);

    excluiInicio(L);

    imprimirLista(L);
    return 0;
}