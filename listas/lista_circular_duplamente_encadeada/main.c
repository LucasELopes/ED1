#include "lista.h"

int main() {
    No *L = NULL;

    L = insereInicio(L, 1);
    L = insereInicio(L, 2);
    L = insereInicio(L, 3);
    L = insereInicio(L, 4);
    L = insereInicio(L, 5);

    L = excluiInicio(L);
    L = excluiInicio(L);
    L = excluiInicio(L);
    L = excluiInicio(L);
    L = excluiInicio(L);

    imprimirLista(L);

    return 0;
}