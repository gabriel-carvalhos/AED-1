#include <stdio.h>

int main() {
    int n, menor, posicao = 0, *p;

    scanf("%d", &n);

    int x[n];
    p = x;

    scanf("%d", p);
    menor = *p;
    posicao = 0;
    p++;

    for (int i = 1; i < n; i++) {
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