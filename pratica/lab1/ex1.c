#include "lista.c"

#define color_reset "\x1b[0m"
#define color_red  "\x1b[31m"

void main() {
    char desejo;
    int QuantidadeMonomios;

    int numero;
    int incognita;

    Mon *P1 = NULL;
    Mon *P2 = NULL;

    system("clear || cls");
    printf(color_red "----------------------- CALCULADORA DE POLINÔMIOS -----------------------\n" color_reset);
    printf("\n 1 - Somar\n 2 - Subtrair\n 3 - Multiplicar\n 0 - Sair\n");
    
    printf("\n Digite o respectivo numero da operação que deseja: ");
    scanf("%c", &desejo);

    printf("\n Quantos monomios tem seu 1° polinômios: ");
    scanf("%d", &QuantidadeMonomios);

    for(int i = 0; i < QuantidadeMonomios; i++) {
        printf(" Insira a numero e o expoente %d° monômio: ", i + 1);
        scanf("%d %d", &numero, &incognita);
        
        P1 = inserirOrd(P1, numero, incognita);
    }

    printf("\n Quantos monomios tem seu 2° polinômios: ");
    scanf("%d", &QuantidadeMonomios);

    for(int i = 0; i < QuantidadeMonomios; i++) {
        printf(" Insira a numero e o expoente %d° monômio: ", i + 1);
        scanf("%d %d", &numero, &incognita);
        
        P2 = inserirOrd(P2, numero, incognita);
    }

}