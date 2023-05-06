#include "lista.h"
#include "stdio.h"
#include "stdlib.h"

No* criaNo(int ch) {
    No *novoNo = (No*) calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("Erro na alocação do nó.\n");
        exit(1);
    }

    novoNo->prox = NULL;
    novoNo->ant = NULL;
    novoNo->chave = ch;

    return novoNo;
}

No* criaLista() {
    No *novaLista = calloc(1, sizeof(No));
    if(novaLista == NULL) {
        printf("Erro na alocação da lista.\n");
        exit(1);
    }
    return novaLista;
}

void imprimirList(No *L) {
    No *aux = L->prox;

    if(aux == NULL)
        printf("Lista vazia!\n");
    else {
        printf("\n");
        while(aux != NULL) {
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void insereInicio(No *L, int ch) {
    No *aux = L->prox;
    No *novoNo = criaNo(ch);

    if(L->prox == NULL) {
        L->prox = novoNo;
        L->ant = novoNo;
    }    
    else {
        novoNo->prox = aux;
        aux->ant = novoNo;
        L->prox = novoNo;
    }
}

int ocorrerencias(No *L , int ch) {
    int repeticoes = 0;
    No *aux = L->prox;

    if(aux == NULL) {}
    else {
        while(aux != NULL) {
            if(aux->chave == ch) repeticoes++;
            aux = aux->prox;
        }
    }
    return repeticoes;
}

No* ultimoLista(No *L) {
    if(L->ant != NULL) {
        return L->ant;
    }
}

void inverteLista(No *L) {
    No *aux = L->prox;
    No *listaAux = criaLista();

    while((aux = retiraInicio(L)) != NULL) {     
        if(listaAux->prox == NULL) {
            listaAux->prox = aux;
            listaAux->ant = aux;
        }
        else {
            aux->prox = listaAux->prox;
            listaAux->prox->ant = aux;
            listaAux->prox = aux;
        }
    }
    L->prox = listaAux->prox;
    L->ant = listaAux->ant;
    free(listaAux);
}

int somaLista(No *L, int soma) {
    No *aux = L->prox;
    
    if(aux != NULL) {
        return soma + somaLista(aux, aux->chave);
    }
    return soma;
}

void substituiNo(No* L, int num1, int num2) {
    No *aux = L->prox;

    if(aux != NULL) {
        if(aux->chave == num1) 
            aux->chave = num2;
        return substituiNo(aux, num1, num2);
    }
}

int iguais(No* L1, No* L2) {
    No* aux1 = L1->prox;
    No* aux2 = L1->prox;

    if(aux1 != NULL && aux2 != NULL) {
        if(aux1->chave != aux2->chave) return 0;
        return iguais(aux1, aux2);
    }

    return 1;
}

No* retiraInicio(No *L) {
    No *aux = L->prox;

    if(aux == NULL) return NULL;
    else if(aux->prox == NULL) {
        L->prox = NULL;
        L->ant = NULL;
    }
    else {
        L->prox = aux->prox;
        L->prox->ant = NULL;
        aux->prox = NULL;
    }

    return aux;
}

int iesimoIgual(No *L1, No *L2, int index) {

    No *auxL1 = L1->prox;
    No *auxL2 = L2->prox;

    if(auxL1 == NULL || auxL2 == NULL);
    else {
        for(int i = 0; i < index; i++) {
            if(auxL1 == NULL || auxL2 == NULL) return 0;
            auxL1 = auxL1->prox;
            auxL2 = auxL2->prox;
        }
        if(auxL1->chave == auxL2->chave) return 1;
    }
    return 0;
}

void main() {
    
    No* L = criaLista();
    No* L2 = criaLista();

    insereInicio(L, 8);
    insereInicio(L, 1);
    insereInicio(L, 1);
    insereInicio(L, 2);
    insereInicio(L, 1);
    imprimirList(L);

    insereInicio(L2, 5);
    insereInicio(L2, 1);
    insereInicio(L2, 1);
    insereInicio(L2, 2);
    insereInicio(L2, 1);
    imprimirList(L2);

    printf("\nNumero de ocorrencias: %d\n", ocorrerencias(L, 1));
    printf("\nUltimo da lista: %d\n", ultimoLista(L)->chave);
    
    // printf("Lista invertida: ");
    // inverteLista(L);
    // imprimirList(L);
    // imprimirList(L);
    printf("\nResultado da soma da lista: %d\n", somaLista(L, 0));

    printf("\nIguais: %d", iesimoIgual(L, L2, 0));
    // int escolha = -1;
    // int addChave;

    // while(escolha != 0) {
    //     printf(system("cls || clear"));
    //     printf("-----------Menu de escolhas-----------\n");
    //     printf("1- Imprimir lista.\n");
    //     printf("2- Inserir no inicio da lista.\n");
    //     printf("0- Sair.\n");
    //     printf("\nSua escolha: ");
    //     scanf("%d", &escolha);

    //     if(escolha == 1) {
    //         imprimirList(L);
    //         printf("Pressione Enter para continuar");
    //         scanf("%c");
    //     }
    //     else if(escolha == 2) {
    //         printf("\nDeseja qual número do início da lista: ");
    //         scanf("%d", &addChave);        
    //         insereInicio(L, addChave);
    //     }
    // }


}