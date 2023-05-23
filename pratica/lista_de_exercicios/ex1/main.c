#include <stdio.h>
#include <limits.h>

int elementMax(int *v, int size, int valorMaximo) {
    if(size == 0) {
        return valorMaximo;
    }
    else {
        --size;
        if(valorMaximo < v[size])
            valorMaximo = v[size];
        elementMax(v, size, valorMaximo);
    }
}

int elementMin(int *v, int size, int valorMinimo) {
    if(size == 0) {
        return valorMinimo;
    }
    else {
        --size; 
        if(valorMinimo > v[size])
            valorMinimo = v[size];
        elementMin(v, size, valorMinimo);
    }
}

int somaTudo(int *v, int size) {
    --size;
    if(size <= 0) {
        return v[size];
    }
    else {
        return v[size]+somaTudo(v,size);
    }
}

int multiplicaTudo(int *v, int size) {
    --size;
    if(size <= 0) {
        return v[0];
    }
    else {
        return v[size]*multiplicaTudo(v,size);
    }
}

double mediaVetor(int *v, int size, int divisor) {
    --size;
    if(size <= 0) {
        return v[0];
    }
    else {
        if(size+1 == divisor) 
            return (v[size] + mediaVetor(v, size, divisor))/divisor; 
        else 
            return v[size] + mediaVetor(v, size, divisor);
    }

}

void main() {
    int vetor[] = {42, 87, 15, 63, 29, 55, 91, 37, 68, 12, 77, 24, 50};
    int sizeVetor = sizeof(vetor)/sizeof(vetor[0]);

    printf("Valor máximo: %d\n", elementMax(vetor, sizeVetor, INT_MIN));
    printf("Valor minímo: %d\n", elementMin(vetor, sizeVetor, INT_MAX));
    printf("Soma de todos os elementos: %d\n", somaTudo(vetor, sizeVetor));
    printf("Produto de todos os elementos: %d\n", multiplicaTudo(vetor, sizeVetor));
    printf("Media do vetor: %.2lf\n", mediaVetor(vetor, sizeVetor, sizeVetor));
}