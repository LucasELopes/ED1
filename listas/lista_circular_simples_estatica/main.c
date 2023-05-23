#include <stdio.h>
#include <stdlib.h>

typedef struct listaCircular {
    int cap, tam, ini, fim;
    int *v;
}LC;

LC* criarLC(int capacidade) {
    LC *novoLC = (LC*)calloc(1, sizeof(LC));

    if(novoLC == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoLC->cap = capacidade;
    novoLC->v = (int*)calloc(capacidade, sizeof(int));
    if(novoLC->v == NULL)
        exit(1);
    return novoLC;
}

void inserir(LC *lc, int ch) {
    if(lc->cap > lc->tam) {
        lc->v[lc->fim] = ch;
        if(lc->fim + 1 == lc->cap)
            lc->fim = 0;
        else
            lc->fim++;
        lc->tam++;
    }else{
        printf("Lista cheia!\n");
    }
}

int remover(LC *lc) {
    if(lc->tam != 0) {
        int *aux = lc->v[lc->ini];
        lc->v[lc->ini] = 0;
        lc->ini++;
        lc->tam--;
    }
    else {
        printf("Lista Vazia!\n");
    } 
}

void imprimirLC(LC *lc) {
    LC *aux = lc;

    if(aux->tam == 0) {
        printf("Lista vazia!\n");
    }else {
        for(int i = lc->ini; i < lc->fim; i++) {
            printf("%d ", aux->v[i]);
        }
        printf("\n");
    }

}

void main() {
    int size = 10;
    LC *lc = criarLC(size);
    inserir(lc, 1);
    inserir(lc, 2);
    inserir(lc, 3);
    inserir(lc, 4);
    inserir(lc, 5);
    
    imprimirLC(lc);
    
    remover(lc);
    remover(lc);
    remover(lc);
    imprimirLC(lc);



}