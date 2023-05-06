#include <stdio.h>

int palindromo(char p[], int i, int j) {    
    if(i < j) {
        if(p[i] == p[j]) return palindromo(p, ++i, --j);
        return 0;
    }
    return 1;
}

void main() {
    char nome[] = "azs";
    printf("%d", palindromo(nome, 0, 2));
}   