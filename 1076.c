#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int grafo[50][50];
    int t, x, n, m, u, v;
    int caminhos = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &x);

        scanf("%d %d", &n, &m);

        memset(grafo, 0, sizeof(grafo));

        for (int j = 0; j < m; j++) {
            scanf("%d %d", &u, &v);
            grafo[u][v] = 1;
            grafo[v][u] = 1;
        }

        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                if (grafo[j][k] == 1) {
                    caminhos++;
                }
            }
        }

        printf("%d\n", caminhos + caminhos);
    }

    return 0;
}