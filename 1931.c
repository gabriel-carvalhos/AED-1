#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct aresta {
    int destino;
    int peso;
    int prox;
} aresta;

typedef struct no {
    int vertice;
    int distancia;
} no;

void adicionar_aresta(int, int, int);
void heap_push(int, int);
no heap_pop();
int dijkstra(int, int, int);

aresta grafo[4 * 50000 + 10];
int head[2 * 10001 + 10];
int contador_aresta;
no heap[4 * 50000 + 10];
int tamanho_heap;

int main() {
    int c, v;
    
    while (scanf("%d %d", &c, &v) != EOF) {
        for (int i = 0; i < 2 * (c + 1); i++) {
            head[i] = -1;
        }
        contador_aresta = 0;

        for (int i = 0; i < v; i++) {
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            
            c1--;
            c2--;
            
            adicionar_aresta(c1, c2 + c, g);
            adicionar_aresta(c2, c1 + c, g);
            
            adicionar_aresta(c1 + c, c2, g);
            adicionar_aresta(c2 + c, c1, g);
        }
        
        int inicio = 0;
        int destino = (c - 1);
        int total_vertices = 2 * c;
        
        int resultado = dijkstra(inicio, destino, total_vertices);
        printf("%d\n", resultado);
    }
    
    return 0;
}

void adicionar_aresta(int u, int v, int peso) {
    grafo[contador_aresta].destino = v;
    grafo[contador_aresta].peso = peso;
    grafo[contador_aresta].prox = head[u];
    head[u] = contador_aresta++;
}

void heap_push(int vertice, int distancia) {
    int i = tamanho_heap++;
    heap[i].vertice = vertice;
    heap[i].distancia = distancia;
    
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[pai].distancia <= heap[i].distancia) {
            break;
        }

        no temp = heap[pai];
        heap[pai] = heap[i];
        heap[i] = temp;
        
        i = pai;
    }
}

no heap_pop() {
    no topo = heap[0];
    heap[0] = heap[--tamanho_heap];

    int i = 0;
    while (1) {
        int menor = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        
        if (esq < tamanho_heap && heap[esq].distancia < heap[menor].distancia)
            menor = esq;
        if (dir < tamanho_heap && heap[dir].distancia < heap[menor].distancia)
            menor = dir;
        
        if (menor == i) {
            break;
        }
        
        no temp = heap[i];
        heap[i] = heap[menor];
        heap[menor] = temp;
        
        i = menor;
    }
    
    return topo;
}

int dijkstra(int inicio, int destino, int total_vertices) {
    // Arrays locais com tamanho adequado
    int *distancia = (int *)malloc(total_vertices * sizeof(int));
    int *visitado = (int *)calloc(total_vertices, sizeof(int));
    
    if (!distancia || !visitado) {
        if (distancia) free(distancia);
        if (visitado) free(visitado);
        return -1;
    }
    
    for (int i = 0; i < total_vertices; i++) {
        distancia[i] = INF;
    }
    
    distancia[inicio] = 0;
    tamanho_heap = 0;
    heap_push(inicio, 0);
    
    while (tamanho_heap > 0) {
        no atual = heap_pop();
        int u = atual.vertice;
        
        if (visitado[u]) {
            continue;
        }
        visitado[u] = 1;
        
        if (u == destino) {
            int resultado = distancia[u];
            free(distancia);
            free(visitado);
            return resultado == INF ? -1 : resultado;
        }
        
        for (int i = head[u]; i != -1; i = grafo[i].prox) {
            int v = grafo[i].destino;
            int peso = grafo[i].peso;
            
            if (!visitado[v] && distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                heap_push(v, distancia[v]);
            }
        }
    }
    
    free(distancia);
    free(visitado);
    return -1;
}