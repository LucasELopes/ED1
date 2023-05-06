#include <stdio.h>

void minMax(int vetor[], int sizeVetor, int *min, int *max) {
    int *aux = vetor;

    *min = *aux;
    *max = *aux;

    for(int i = 1; i < sizeVetor; i++) {
        if(*min > *(aux + i)) *min = *(aux + i);
        else if(*max < *(aux + i)) *max = *(aux + i);
    }
}

void main() {
    int min, max; 
    int vetor[] = {3, 7, 4, 2, 6, 8, 9, 1, 5, 10};
    int sizeVetor = sizeof(vetor)/sizeof(vetor[0]);

    minMax(vetor, sizeVetor, &min, &max);
    printf("%d %d", min, max);
}
