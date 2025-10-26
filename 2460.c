#include <stdio.h>
#include <stdlib.h>

int removeElemento(int, int, int[]);

int main() {
    int n, m, *fila, *sairam;

    scanf("%d", &n);
    fila = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &m);
    sairam = (int *) malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &sairam[i]);
        n = removeElemento(n, sairam[i], fila);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0 && i <= n - 1) {
            printf(" ");
        }
        printf("%d", fila[i]);
    }
    printf("\n");

    free(fila);
    free(sairam);
}

int removeElemento(int n, int x, int v[]) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (v[i] == x) {
            break;
        }
    }

    for (int j = i; j < n; j++) {
        v[j] = v[j + 1];
    }

    return n - 1;
}