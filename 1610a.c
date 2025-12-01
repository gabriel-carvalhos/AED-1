// nao finalizado

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        int **grafo;

        scanf("%d", &n);
        scanf("%d", &m);
        
        // aloca memoria para matriz
        grafo = malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            grafo[j] = calloc(n, sizeof(int *));
        }

        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);

            grafo[a - 1][b - 1] = 1;
        }

        // imprime matriz
        // for (int j = 0; j < n; j++) {
        //     for (int k = 0; k < n; k++) {
        //         printf("%d ", grafo[j][k]);
        //     }
        //     printf("\n");
        // }

        // libera matriz
        for (int j = 0; j < n; j++) {
            free(grafo[j]);
        }
        free(grafo);
    }
}