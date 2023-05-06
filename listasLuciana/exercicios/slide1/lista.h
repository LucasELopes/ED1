#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no {
    int chave;
    struct no *prox;
}No;

No* criaNo(int valor);
No* insereInicio(No *L, int valor);
No* insereFinal(No *L, int valor);
No* buscaChave(No *L, int valor);
No* excluirInicio(No *L);
No* excluirFinal(No *L);
No* excluirChave(No *L, int chave);
void imprimirLista(No *L);

#endif 