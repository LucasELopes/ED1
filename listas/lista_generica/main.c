#include "lista.h"

void imprimirInt(void *info) {
    int *info_int = (int*)info;
    printf("%d ", *(info_int));
}

void insereInteiro(NoGen *L, int inteiro) {
    int *pont_int = (int*)calloc(1, sizeof(int));
    *(pont_int) = inteiro;
    inserirInicio(L, pont_int); 
}

void quadrado(void *info) {
    *((int*)info) = (*(int*)info) * (*(int*)info);
}

int main() {
    NoGen *L = criarNo((void*)0);

    insereInteiro(L, 1);
    insereInteiro(L, 2);
    insereInteiro(L, 3);
    insereInteiro(L, 4);

    percorreLista(L, imprimirInt);
    percorreLista(L, quadrado);
    percorreLista(L, imprimirInt);

    return 0;
}