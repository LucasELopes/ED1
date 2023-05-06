#include <stdio.h>
#include <stdlib.h>

void main() {
    // alocacao versao malloc o valor dos espacos recém alocados é indeterminado!
    //int *inteiro;
    //inteiro = (int*) malloc(10 * sizeof(int));
    //printf("%d\n", *inteiro);

    // alocacao versao calloc: O valor dos espacos recém alocados é zerados!
    //int *inteiro2;
    //inteiro2 = (int*) calloc(10, sizeof(int));
    //printf("%d", *inteiro2);

    //Criando matriz:
    int **matriz;

    matriz = (int**) calloc(3, sizeof(int*));

    for(int i = 0; i < 3; i++) {
        matriz[i] = (int*) calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++) {
            matriz[i][j] = (i + j) * 2;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}