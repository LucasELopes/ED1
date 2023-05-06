#include <stdio.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int sizeVetor) {
    // 2, 1, 5, 7
    int copia;
    int indice;

    for(int i = 0; i < sizeVetor; i++) {
        copia = vetor[i];
        indice = i;

        for(int j = i + 1; j < sizeVetor; j++) {
            if(copia > vetor[j]) {
                copia = vetor[j];
                indice = j;
            }
        }
        vetor[indice] = vetor[i];
        vetor[i] = copia;
    }

}

void main() {
    int vetorTeste[] = {2};

    int sizeVetorTeste = sizeof(vetorTeste)/sizeof(vetorTeste[0]);

    imprimirVetor(vetorTeste, sizeVetorTeste);
    selectionSort(vetorTeste, sizeVetorTeste);
    imprimirVetor(vetorTeste, sizeVetorTeste);
    
}