#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

Lista* criaLista() {
    Lista *novaLista = (Lista*) calloc(1, sizeof(Lista));

    if(novaLista == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novaLista->inicio = NULL;
    return novaLista;
}

No* criaNo(int valor) {
    No *novoNo = (No*) calloc(1, sizeof(No));

    if(novoNo == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }

    novoNo->proximo = NULL;
    novoNo->valor = valor;

    return novoNo;
}

void inserirInicio(Lista *lista, int valor) {
    
    if(lista == NULL) {
        printf("Lista nao inicializada!");
        exit(1);
    }
    
    if(lista->inicio == NULL) lista->inicio = criaNo(valor);

    else {
        No *novoNo = criaNo(valor);
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo; 
    }  
}

void inserirFinal(Lista *list, int value) {
    if(list == NULL) {
        printf("Lista nao inicializada!");
        exit(1);
    }

    if(list->inicio == NULL) list->inicio = criaNo(value);

    else {
        No *aux = list->inicio;
        while(aux->proximo != NULL) aux = aux->proximo;
        aux->proximo = criaNo(value);
    }
}

No* buscarChave(Lista *list, int findValue) {
    if(list == NULL) return NULL;

    No *aux = list->inicio;

    while(aux != NULL) {
        if(aux->valor == findValue)
            return aux;
        aux = aux->proximo;
    }

    return aux;
}

void excluirNoInicio(Lista *list) {
    if(list == NULL) {
        printf("Lista não iniciada!\n");
        exit(1);
    }

    No *aux = list->inicio;

    if(aux != NULL)
        list->inicio = aux->proximo;
        free(aux);
}

void excluirNoFim(Lista *list) {
    if(list == NULL) return;

    No *aux = list->inicio;
    No *pred = NULL;

    while(aux->proximo != NULL) {
        pred = aux;
        aux = aux->proximo;
    }

    if(pred == NULL) list = NULL;

    else {
        pred->proximo = NULL;
        free(aux);
    }
}

void excluirChave(Lista *list, int valor) {
    if(list == NULL) return;

    No *aux = list->inicio;
    No *pred = NULL;

    while(aux != NULL && aux->valor != valor) {
        pred = aux;
        aux = aux->proximo;
    }

    if(pred == NULL) list->inicio = aux->proximo;
     
    else pred->proximo = aux->proximo;

    free(aux);
}

void imprimirLista(Lista *l) {
    No *aux = l->inicio;
    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}


void main() {
    Lista *list1 = criaLista();

    printf("Inserindo no inicio list1\n");
    inserirInicio(list1, 12);
    inserirInicio(list1, 1122);
    inserirInicio(list1, 121);
    inserirInicio(list1, 132);
    inserirInicio(list1, 22);

    imprimirLista(list1);
    // --------------------------------------- //

    Lista *list2 = criaLista();

    printf("\nInserindo no final da list2\n");
    inserirFinal(list2, 12);
    inserirFinal(list2, 1122);
    inserirFinal(list2, 121);
    inserirFinal(list2, 132);
    inserirFinal(list2, 22);

    imprimirLista(list2);
    
    // ------------------------------------- //

    Lista *list3 = criaLista();
    
    printf("\nInserindo no final da list3\n");
    inserirFinal(list3, 1);
    inserirFinal(list3, 2);
    inserirFinal(list3, 3);
    inserirFinal(list3, 4);
    inserirFinal(list3, 5);

    imprimirLista(list3);

    // ------------------------------------- //

    excluirNoInicio(list2);
    excluirNoInicio(list2);
    printf("\nApagando no inicio list2\n");
    imprimirLista(list2);

    // ------------------------------------- //
    excluirNoFim(list1);
    excluirNoFim(list1);
    printf("\nApagando no fim da list1\n");
    imprimirLista(list1);

    // ------------------------------------- //
    excluirChave(list3, 4);
    excluirChave(list3, 2);
    
    printf("\nApagando nó da list3\n");
    imprimirLista(list3);


}