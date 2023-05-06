#include <stdio.h>

int palindromo(char p[]) {
    int sizeP = 0;

    while (p[sizeP] != '\0') {
        sizeP++;
    }
    if(sizeP == 0) return 0;

    int i = 0, j = sizeP - 1;

    while(i <= j) {
        if(p[i] == p[j]) {
            i++;
            j--;
            continue;
        }
        return 0;
    }

    return 1;
}

void main() {
    char nome[] = "";
    printf("%d", palindromo(nome));

}