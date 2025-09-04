#include <stdio.h>

int main() {
    int n, menor = 9999, posicao = 0, *p;

    scanf("%d", &n);

    int x[n];
    p = x;

    for (int i = 0; i < n; i++) {
        scanf("%d", p);

        if (*p < menor) {
            menor = *p;
            posicao = i;
        }

        p++;
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}