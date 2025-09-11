#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n, *menor, *posicao, *x, *i;

    n = (int *) malloc(sizeof(int));
    menor = (int *) malloc(sizeof(int));
    posicao = (int *) malloc(sizeof(int));
    i = (int *) malloc(sizeof(int));

    scanf("%d", n);

    x = (int *) malloc(*n * sizeof(int));

    scanf("%d", &x[0]);
    *menor = x[0];
    *posicao = 0;

    for (*i = 1; *i < *n; *i = *i + 1) {
        scanf("%d", &x[*i]);

        if (x[*i] < *menor) {
            *menor = x[*i];
            *posicao = *i;
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", *posicao);

    free(n);
    free(menor);
    free(posicao);
    free(x);

    return 0;
}