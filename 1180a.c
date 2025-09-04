#include <stdio.h>

int main() {
    int n, menor = 9999, posicao;

    scanf("%d", &n);

    int x[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);

        if (x[i] < menor) {
            menor = x[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d", posicao);

    return 0;
}