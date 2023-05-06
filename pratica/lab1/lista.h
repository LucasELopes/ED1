#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct mon{
    int numero;
    int incognita;
    struct mon *prox;
}Mon;

Mon* criarMon(int numero, int incignita);
Mon* inserirOrd(Mon *P, int numero, int incognita);
void imprimirPol(Mon *P);
Mon* somaSubPol(Mon *P1, Mon *P2, char operacao);
Mon* produtoPol(Mon *P1, Mon *P2);
#endif