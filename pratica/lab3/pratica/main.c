#include "pilha.h"

int main() {
    FILE *file = fopen("arq.txt", "r");
    delimitador(file);
    fclose(file);
}