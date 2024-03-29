#include <stdio.h>

/*
* No insertSort, quando temos um vetor vamos olhar primeiramente para o segundo indice do vetor.
* onde temos um variavel que vai copiar o valor que esta no respectivo indice, e outra variavel para armazenar
* o indice do elemento. 
*/

void imprimir(int vetor[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void insertSort(int vetor[], int size) {
    int copia;
    for(int i = 1; i < size; i++) {
        copia = vetor[i];
        for(int j = i; j > 0; j--) {
            if(vetor[j-1] > vetor[j]) {
                copia = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = copia;
            }
        }
    }
}

void main() {
    int vetorTeste[] = {2, 7, 1, 5, 12, 23123,3123, 23, 2, 2};

    int sizeVetor = sizeof(vetorTeste)/ sizeof(vetorTeste[0]);

    imprimir(vetorTeste, sizeVetor);

    insertSort(vetorTeste, sizeVetor);

    imprimir(vetorTeste, sizeVetor);
}


