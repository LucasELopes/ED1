#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no
{
    int chave;
    struct no *prox;
}No;

No* criarNo(int chave);
void imprimirLista(No *L);
No* inserirInicio(No *L, int chave);
No* inserirFinal(No *L, int chave);
No* buscarChave(No *L, int chave);
No* excluirInicio(No* L);
No* excluirFinal(No *L);
No* excluirChave(No* L, int chave);
No* buscarChaveOrd(No *L, int chave);
No* inserirOrd(No *L, int chave);
No* excluirOrd(No *L, int chave);
No *buscaListaOrd(No *L, int valor, No **pred);

#endif