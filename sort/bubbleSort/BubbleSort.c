#include <stdio.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubbleSort(int vetor[], int size) {
    int copia = vetor[0];

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < (size - i) - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                copia = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = copia;
            }
            imprimirVetor(vetor, size);
        } 
    }
}

void main() {
    int vetor[] = {12, 3, 1, 11, 12, 343, 123421, 543, 94, 10, 9313, 122};
    int sizeVetor = sizeof(vetor) / sizeof(vetor[0]);

    bubbleSort(vetor, sizeVetor);
    imprimirVetor(vetor, sizeVetor);

}