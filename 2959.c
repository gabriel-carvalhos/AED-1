#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int main() {
    long long valores[MAX];
    long long minimos[MAX];
    int topo = -1;
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char operacao[10];
        scanf("%s", operacao);
        
        if (strcmp(operacao, "PUSH") == 0) {
            long long valor;
            scanf("%lld", &valor);
            
            topo++;
            valores[topo] = valor;
            
            if (topo == 0) {
                minimos[topo] = valor;
            } else {
                minimos[topo] = (valor < minimos[topo - 1]) ? valor : minimos[topo - 1];
            }
            
        } else if (strcmp(operacao, "POP") == 0) {
            if (topo == -1) {
                printf("EMPTY\n");
            } else {
                topo--;
            }
            
        } else if (strcmp(operacao, "MIN") == 0) {
            if (topo == -1) {
                printf("EMPTY\n");
            } else {
                printf("%lld\n", minimos[topo]);
            }
        }
    }
    
    return 0;
}