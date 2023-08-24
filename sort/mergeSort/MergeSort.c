#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void merge(int *vetor, int ini, int meio, int fim) {
    int i = ini, j = meio, k = fim;
    int *vetorAux = calloc((fim-ini)+1, sizeof(int));

    while(k < ((fim-ini)+1)) {

    }

}

void mergeSort(int *vetor, int ini, int fim) {
    if(ini < fim) {
        int metade = (ini+fim)/2;
        mergeSort(vetor, ini, metade);
        mergeSort(vetor, metade+1, fim);
        merge(vetor, ini, metade, fim);
    }
}

void main() {
    int vetorTeste[] = {2, 7, 1, 5, 12, 23123,3123, 23, 2, 2};

    int sizeVetorTeste = sizeof(vetorTeste)/sizeof(vetorTeste[0]);

    imprimirVetor(vetorTeste, sizeVetorTeste);
    selectionSort(vetorTeste, sizeVetorTeste);
    imprimirVetor(vetorTeste, sizeVetorTeste);
    
}