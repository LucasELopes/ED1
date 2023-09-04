#include <stdio.h>

void imprimir(int v[], int size, int index, int level) {
    for(int i = 0; i < level; i++) 
        printf("-");

    printf("%d\n", v[index]);

    if((index+1)*2 < size) 
        imprimir(v, size, (index+1)*2, level+1);
    if(((index+1)*2 + 1) < size)
        imprimir(v, size, ((index+1)*2 + 1), level+1);
}

void main() {
    int v[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    // printf("%d", *(v));
    imprimir(v, sizeof(v)/sizeof(v[0]), 0, 1);
}