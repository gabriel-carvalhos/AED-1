#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int x;
    struct cel *seg;
} cel;

int dfs(int, cel **, int *);
int tem_ciclo(int, cel **);

int main() {
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        cel **grafo;

        scanf("%d", &n);
        scanf("%d", &m);

        grafo = malloc(n * sizeof(cel*));

        for (int j = 0; j < n; j++) {
            grafo[j] = NULL;
        }

        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            cel* novo = malloc(sizeof(cel));
            novo->x = b - 1;
            novo->seg = grafo[a - 1];
            grafo[a - 1] = novo;
        }

        if (tem_ciclo(n, grafo)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // libera memória da lista
        for (int j = 0; j < n; j++) {
            cel* temp = grafo[j];

            while (temp != NULL) {
                cel* seg = temp->seg;
                free(temp);
                temp = seg;
            }
        }
        free(grafo);
    }
    
    return 0;
}

// 0 = não visitado, 1 = visitando (em processo), 2 = visitado completamente
int dfs(int v, cel **grafo, int *cor) {
    cor[v] = 1;
    
    cel* temp = grafo[v];
    while (temp != NULL) {
        int vizinho = temp->x;
        if (cor[vizinho] == 1) {
            return 1;
        }
        if (cor[vizinho] == 0 && dfs(vizinho, grafo, cor)) {
            return 1;
        }
        temp = temp->seg;
    }
    
    cor[v] = 2;
    return 0;
}

int tem_ciclo(int n, cel** grafo) {
    int *cor = calloc(n, sizeof(int));
    int ciclo = 0;
    
    for (int i = 0; i < n; i++) {
        if (cor[i] == 0) {
            if (dfs(i, grafo, cor)) {
                ciclo = 1;
                break;
            }
        }
    }
    
    free(cor);
    return ciclo;
}