#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    void *info;
    struct fila *prox, *ant;
}Fila;

/*
Função: criarNo
Descrição:
    Aloca dinamicamente um espaço na memória armazenado o valor genérico passado com parâmetro.
Entrada:
    void *info: O valor que o nó armazenará
Saída:
    Fila*: O nó já alocado que armazanando seu respectivo valor.
*/
Fila* criarNo(void *info);

/*
Função: inserirFila
Descrição: Insere ao final da fila o no alocado dinamicamente.
Entrada:
    Fila *F: A fila onde sera inserido o nó.
    void *info: O valor genérico que o nó armazenará.
Saída:
    void
*/
void inserirFila(Fila *F, void *info);

/*
Função: retirarDaFila
Descrição: Retira o nó que estiver no início da fila.
Entrada:
    Fila *F: A fila onde sera retirado o nó.
Saída:
    O nó retirado.
*/
Fila* retirarDaFila(Fila *F);

/*
Função: imprimirFila
Descrição: imprime o valores contidos na fila;
Entrada:
    Fila *F: A respectiva fila que será imprimida.
    void (*cb) (void *): recebe a funcão implemtada pelo usuário do pacote para que a função imprimirFila possa percorrer a fila 
        imprimido as informações guardas nos nós com auxilio do callback.
Saída: 
    void
*/
void imprimirFila(Fila *F, void (*cb) (void *));

/*
Função: destruirFila
Descrição: desaloca o espaçõ ocupado pela fila na memória
Entrada: 
    Fila *F: A respectiva fila que será desalocada.
Saída: 
    void.
*/
void destruirFila(Fila *F);

#endif