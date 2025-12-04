#include <stdio.h>
#include <string.h>

int inverter_numero(int);
int bfs(int, int);

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d\n", bfs(a, b));
    }
    
    return 0;
}

int inverter_numero(int n) {
    int invertido = 0;

    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }

    return invertido;
}

int bfs(int A, int B) {
    if (A == B) return 0;
    
    int visitado[10000] = {0};
    int distancia[10000] = {0};
    int fila[10000];
    int frente = 0, tras = 0;
    
    fila[tras++] = A;
    visitado[A] = 1;
    distancia[A] = 0;
    
    while (frente < tras) {
        int atual = fila[frente++];
        
        int prox1 = atual + 1;
        if (prox1 < 10000 && !visitado[prox1]) {
            if (prox1 == B) return distancia[atual] + 1;
            visitado[prox1] = 1;
            distancia[prox1] = distancia[atual] + 1;
            fila[tras++] = prox1;
        }
        
        int prox2 = inverter_numero(atual);
        if (prox2 < 10000 && !visitado[prox2]) {
            if (prox2 == B) return distancia[atual] + 1;
            visitado[prox2] = 1;
            distancia[prox2] = distancia[atual] + 1;
            fila[tras++] = prox2;
        }
    }
    
    return -1;
}