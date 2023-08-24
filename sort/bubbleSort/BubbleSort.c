#include <stdio.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Pega o primeiro valor do vetor como paramentro de comparação, e compara com o proximo, caso i seja maior que
// i+1 então: i+1 = i e i = i+1. Caso contrário guardo o valor de i+1.
void bubbleSort(int vetor[], int size) {
    int maior = vetor[0];

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < ((size-i)-1); j++) {
            if(vetor[j] > vetor[j+1]) {
                maior = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = maior;
            }
        }
    }
}

void main() {
    int vetor[] = {12, 3, 1, 11, 12, 343, 123421, 543, 94, 10, 9313, 122};
    int sizeVetor = sizeof(vetor) / sizeof(vetor[0]);

    imprimirVetor(vetor, sizeVetor);
    bubbleSort(vetor, sizeVetor);
    imprimirVetor(vetor, sizeVetor);

}