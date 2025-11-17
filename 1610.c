// nao finalizado

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int **grafo = (int **) malloc(n * sizeof(int *));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", grafo[i][j]);
            }
            printf("\n");
        }

        // for (int j = 0; j < m; j++) {
        //     int a, b;
        //     scanf("%d %d", &a, &b);

        //     grafo[a][b] = 1;
        // }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%d ", grafo[i][j]);
        //     }
        //     printf("\n");
        // }

        for (int i = 0; i < m; i++) {
            free(grafo[i]);
        }
        
        free(grafo);
    }
}