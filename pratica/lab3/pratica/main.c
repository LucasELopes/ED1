#include "pilha.h"
// #include <stdio.h>

int main() {
    FILE *file = fopen("arq.txt", "r");
    No *p1 = criarNo('\0');
    delimitador(file, p1);
    fclose(file);
}