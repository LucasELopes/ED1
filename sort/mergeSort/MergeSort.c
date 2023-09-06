#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void merge(int *v, int ini, int meio, int fim) {
    int i = ini, j = meio+1, k = 0;
    int *vAux = calloc((fim-ini)+1, sizeof(int));

    while(k < fim-ini+1) {
        if(i <= meio && j <= fim) {
            if(v[i] < v[j]) {
                vAux[k] = v[i++]; 
            }
            else {
                vAux[k] = v[j++];
            }
        }
        else {
            if(i <= meio) {
                vAux[k] = v[i++];
            }
            else{
                vAux[k] = v[j++];
            }
        }
        k++;
    }
    i = ini, k = 0;
    while(k < ((fim-ini)+1)) {
        v[i] = vAux[k];
        i++, k++; 
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
    int vetorTeste[] = {13, 4, 15, 9, 2, 7, 10, 8};

    int sizeVetorTeste = sizeof(vetorTeste)/sizeof(vetorTeste[0]);

    imprimirVetor(vetorTeste, sizeVetorTeste);
    mergeSort(vetorTeste, 0, sizeVetorTeste-1);
    imprimirVetor(vetorTeste, sizeVetorTeste);
    
}