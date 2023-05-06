#include <stdio.h>

int greaterElem(int vetor[], int sizeVector, int index) {
    
    if(sizeVector - 1 == 0) return vetor[index];
    else {
        --sizeVector;
        if(vetor[index] < vetor[sizeVector]) index = sizeVector;
        greaterElem(vetor, sizeVector, index);
    }
}

int lowerElem(int vetor[], int sizeVector, int index) {
    
    if(sizeVector - 1 == 0) return vetor[index];
    else {
        --sizeVector;
        if(vetor[index] > vetor[sizeVector]) index = sizeVector;
        lowerElem(vetor, sizeVector, index);
    }
}

int sumElem(int vetor[], int sizeVector) {
  
    if(sizeVector > 0) {
        return vetor[sizeVector - (sizeVector - 2)] += sumElem(vetor, --sizeVector);
    }

    return 0;
}

void main() {
    int a[] = {12, 4, 6};
    int sizeVector = sizeof(a)/sizeof(a[0]);

    printf("Maior elemento: %d\n", greaterElem(a, sizeVector, 0));
    printf("Menor elemento: %d\n", lowerElem(a, sizeVector, 0));
    printf("Soma dos elementos: %d\n", sumElem(a, sizeVector));

}
