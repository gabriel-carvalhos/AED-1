#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int criticidade;
    char tipo;
} problema;

int comparar(const void *a, const void *b);

int main() {
    int n, m;
    problema *problemas;
    scanf("%d %d", &n, &m);
    
    int total = n * m;
    problemas = (problema *) malloc(total * sizeof(problema));
    
    for (int i = 0; i < total; i++) {
        char entrada[3];
        scanf("%s", entrada);
        
        problemas[i].criticidade = entrada[0] - '0';
        problemas[i].tipo = entrada[1];
    }
    
    qsort(problemas, total, sizeof(problema), comparar);
    
    for (int i = 0; i < total; i++) {
        printf("%d%c\n", problemas[i].criticidade, problemas[i].tipo);
    }
    
    free(problemas);
    return 0;
}

int comparar(const void *a, const void *b) {
    problema *p1 = (problema *)a;
    problema *p2 = (problema *)b;
    
    if (p1->tipo != p2->tipo) {
        if (p1->tipo == 'V' && p2->tipo == 'D') {
            return -1;
        } 
        if (p1->tipo == 'D' && p2->tipo == 'V') {
            return 1;
        }
    }
    
    return p2->criticidade - p1->criticidade;
}