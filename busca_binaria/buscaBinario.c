#include <stdio.h>

#include <stdio.h>

int buscaBinaria(int *v, int size, int key){
    int meio = 0, inicio = 0, final = size-1;

    while(inicio != final) {
        meio = (final+inicio)/2;
        // Caso o valor do meio seja maior do que o a key procurada, vamos pegar a parte da esquerda do vetor divido.
        if(*(v+meio) > key) {
            final = meio-1;
        }
        // Caso o valor do meio seja menor do que o a key procurada, vamos pegar a parte da direita do vetor divido.
        else if(*(v+meio) < key) {
            inicio = meio+1;
        }
        // Quando a função encontrar o valor procurado a mesma apenas retorna o inteiro.
        else if(*(v+meio) == key){
            return *(v+meio);
        }
    }
    // Caso o loop termine e o inicio seja igual ao final significa que o valor procurado não existe.
    if(inicio == final) {
        if(v[inicio] == key)
            return v[inicio];
        printf("Valor não existe!\n");
        return -1;
    }
}

void main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeV = sizeof(v)/sizeof(v[0]);
    printf("%d\n", buscaBinaria(v, sizeV, 5));
}