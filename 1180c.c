#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n, *menor, *posicao, *x, *p, *i;

    n = (int *) malloc(sizeof(int));
    menor = (int *) malloc(sizeof(int));
    posicao = (int *) malloc(sizeof(int));
    i = (int *) malloc(sizeof(int));

    scanf("%d", n);

    x = (int *) malloc(*n * sizeof(int));
    p = x;

    scanf("%d", p);
    *menor = *p;
    *posicao = 0;
    p++;

    for (*i = 1; *i < *n; *i = *i + 1) {        
        scanf("%d", p);
        
        if (*p < *menor) {
            *menor = *p;
            *posicao = *i;
        }

        p++;
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", *posicao);

    free(n);
    free(menor);
    free(posicao);
    free(x);

    return 0;
}