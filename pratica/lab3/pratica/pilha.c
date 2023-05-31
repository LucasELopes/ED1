#include "pilha.h"

void imprimirPilha(No* p) {
    if(p->prox == NULL)
        printf("Pilha vazia!\n");
    else {
        No *aux = p->prox;
        while (aux != NULL) {
            printf("%c ", aux->delim);
            aux = aux->prox;
        }
        printf("\n");
    }
}

No* criarNo(char delim) {
    No *novoNo = (No*)calloc(1,sizeof(No));
    if(!novoNo) {
        printf("Erro na alocação!\n");
        exit(1);
    }
    novoNo->delim = delim;
    return novoNo;
}

void inserirNo(No* p, char delim) {
    No *novoNo = criarNo(delim);
    novoNo->ant = p->ant;
    if(p->prox == NULL)
        p->prox = novoNo;
    else
        p->ant->prox = novoNo;
    p->ant = novoNo;
}

void removerNo(No *p) {
    if(p->ant != NULL){
        No *aux = p->ant;
        if(aux->ant == NULL) {
            p->ant = NULL;
            p->prox = NULL;
        }else {
            aux->ant->prox = NULL;
            p->ant = aux->ant;
        }
        free(aux);
    }
}

No* retirarNo(No *p) {
    if(p->ant != NULL){
        No *aux = p->ant;
        if(aux->ant == NULL) {
            p->ant = NULL;
            p->prox = NULL;
        }else {
            aux->ant->prox = NULL;
            p->ant = aux->ant;
            aux->ant = NULL;
        }
        return aux;
    }
    return NULL;
}

int delimitador(FILE *file) {
    No *p = criarNo('\0');
    char delimitador;
    No *deliDaPilha;

    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    do {
        delimitador = fgetc(file);
        if(delimitador == 40 || 
            delimitador == 91 ||
            delimitador == 123) 
        {
            inserirNo(p, delimitador);
        }
        else{
            if(delimitador == 41 ||
                delimitador == 93 ||
                delimitador == 125)
            {   
                deliDaPilha = retirarNo(p);
                if(deliDaPilha == NULL || (deliDaPilha->delim + 1 != delimitador && deliDaPilha->delim + 2 != delimitador)) {
                    printf("Delimitadores desbalanceados\n");
                    return 0;
                }
            }
        }
    }while(delimitador != EOF);
    printf("Delimitadores balanceados\n");
    return 1;
}