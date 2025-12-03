#include <stdio.h>
#include <stdlib.h>

int tem_ciclo(int n, int **grafo);
int dfs(int v, int n, int **grafo, int *cor);

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
            grafo[j] = calloc(n, sizeof(int));
        }

        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);

            grafo[a - 1][b - 1] = 1;
        }

        if (tem_ciclo(n, grafo)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // libera matriz
        for (int j = 0; j < n; j++) {
            free(grafo[j]);
        }
        free(grafo);
    }
}

int tem_ciclo(int n, int **grafo) {
    int *cor = calloc(n, sizeof(int));
    int ciclo = 0;
    
    for (int i = 0; i < n; i++) {
        if (cor[i] == 0) {
            if (dfs(i, n, grafo, cor)) {
                ciclo = 1;
                break;
            }
        }
    }
    
    free(cor);
    return ciclo;
}

// 0 = nao visitado, 1 = visitando, 2 = visitado
int dfs(int v, int n, int **grafo, int *cor) {
    cor[v] = 1;

    for (int i = 0; i < n; i++) {
        if (grafo[v][i]) {
            if (cor[i] == 1) {
                return 1;
            }
            if (cor[i] == 0 && dfs(i, n, grafo, cor)) {
                return 1;
            }
        }
    }
    
    cor[v] = 2;
    return 0;
}