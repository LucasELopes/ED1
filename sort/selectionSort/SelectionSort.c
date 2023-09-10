#include <stdio.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int size) {
    int copia;
    for(int i = 0; i < size; i++) {
        copia = vetor[i];
        for(int j = i+1; j < size; j++) {
            if(vetor[i] > vetor[j]) {
                copia = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = copia;
            }   
        }
    }
}

void main() {
    int vetorTeste[] = {2, 7, 1, 5, 12, 23123,3123, 23, 2, 2};

    int sizeVetorTeste = sizeof(vetorTeste)/sizeof(vetorTeste[0]);

    imprimirVetor(vetorTeste, sizeVetorTeste);
    selectionSort(vetorTeste, sizeVetorTeste);
    imprimirVetor(vetorTeste, sizeVetorTeste);
    
}