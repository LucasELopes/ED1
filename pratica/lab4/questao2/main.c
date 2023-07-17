#include "fila.h"

typedef struct processo {
    int id;
    float tempo; // ms
    int *bits;
}Processo;

Processo* criarProcesso(int id, float tempo, int bits[]) {
    Processo *novoProcesso = (Processo*)calloc(1, sizeof(Processo));
    if(!novoProcesso) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoProcesso->id = id;
    novoProcesso->tempo = tempo;
    novoProcesso->bits = bits;

    return novoProcesso;
}

void imprimirProcesso(void *info) {
    Processo *pro = (Processo*)info;
    printf("Id: %d ", pro->id);
    printf("Tempo: %f \n", pro->tempo);
    // printf("Bits: %d ", pro->bits);
}

int main() {

    Fila *F = criarNo((void*)0);

    inserirFila(F, (void*)criarProcesso(1, 3000, (int[]){0, 1, 1, 0, 1}));
    inserirFila(F, (void*)criarProcesso(2, 6000, (int[]){1, 0, 1, 0, 1}));
    inserirFila(F, (void*)criarProcesso(3, 2000, (int[]){1, 1, 0, 0, 0}));
    
    imprimirFila(F, imprimirProcesso);

    return 0;
}