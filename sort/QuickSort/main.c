#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVetor(int vetor[], int sizeVetor) {

    for(int i = 0; i < sizeVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int particionaAletorio(int *v, int ini, int fim) {
    int i, j, aux, pivo;
    i = ini, j = fim;
    pivo = v[ini];
    while(i < j) {
        while(v[i] <= pivo)
            i++;
        while(v[j] > pivo)
            j--;
        if(i < j) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    v[ini] = v[j];
    v[j] = pivo;
    return j;
}

void quickSort(int *v, int ini, int fim) {
    if(ini < fim) {
        int pivo = particionaAletorio(v, ini, fim);
        quickSort(v, ini, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

void main() {
    int vetorTeste[] = {13, 4, 15, 9, 2, 7, 10, 8};

    int sizeVetorTeste = sizeof(vetorTeste)/sizeof(vetorTeste[0]);

    imprimirVetor(vetorTeste, sizeVetorTeste);
    quickSort(vetorTeste, 0, sizeVetorTeste-1);
    imprimirVetor(vetorTeste, sizeVetorTeste);

}