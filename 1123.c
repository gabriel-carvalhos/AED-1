#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 62500  // 250 cidades * 250 pedágio máximo

typedef struct no {
    int destino;
    int peso;
    struct no* proximo;
} no;

typedef struct {
    no* cabeca;
} lista;

void inicializarGrafo();
void adicionarAresta(int, int, int);
void limparLista(int u);
int dijkstra(int origem, int destino);

lista grafo[260];
int n, m, c, k;

int main() {
    while (1) {
        int caminho = 0, resultado;
        int custoAcumulado[260];

        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &c);
        scanf("%d", &k);
        
        if (n == 0 && m == 0 && c == 0 && k == 0) {
            break;
        }
        
        inicializarGrafo();
        
        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            adicionarAresta(u, v, p);
            adicionarAresta(v, u, p);
        }
        
        custoAcumulado[c - 1] = 0;
        
        for (int i = c - 2; i >= 0; i--) {
            int custoParaProximo = INF;
            no* atual = grafo[i].cabeca;
            
            while (atual != NULL) {
                if (atual->destino == i + 1) {
                    custoParaProximo = atual->peso;
                    break;
                }
                atual = atual->proximo;
            }
            
            caminho += custoParaProximo;
            custoAcumulado[i] = caminho;
            
            limparLista(i);
            
            adicionarAresta(i, c - 1, custoAcumulado[i]);
        }
        
        resultado = dijkstra(k, c - 1);
        printf("%d\n", resultado);
    }
    
    return 0;
}

void inicializarGrafo() {
    for (int i = 0; i < n; i++) {
        grafo[i].cabeca = NULL;
    }
}

void adicionarAresta(int u, int v, int peso) {
    no* novo = (no *) malloc(sizeof(no));
    novo->destino = v;
    novo->peso = peso;
    novo->proximo = grafo[u].cabeca;
    grafo[u].cabeca = novo;
}

void limparLista(int u) {
    no* atual = grafo[u].cabeca;

    while (atual != NULL) {
        no* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    grafo[u].cabeca = NULL;
}

int dijkstra(int origem, int destino) {
    int dist[260];
    int visitado[260];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        int minDist = INF;
        
        for (int i = 0; i < n; i++) {
            if (!visitado[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        
        if (u == -1 || u == destino) break;
        visitado[u] = 1;
        
        no* atual = grafo[u].cabeca;
        while (atual != NULL) {
            int v = atual->destino;
            int peso = atual->peso;
            
            if (!visitado[v] && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
            
            atual = atual->proximo;
        }
    }
    
    return dist[destino];
}