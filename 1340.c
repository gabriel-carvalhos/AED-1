#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    int pilha[MAX], fila[MAX], fila_prioridade[MAX];
    int topo, frente_fila, tras_fila, tamanho_fila_prioridade;
    
    while (scanf("%d", &n) != EOF) {
        topo = -1;
        frente_fila = 0;
        tras_fila = -1;
        tamanho_fila_prioridade = 0;
        
        int eh_pilha = 1, eh_fila = 1, eh_prioridade = 1;
        
        for (int i = 0; i < n; i++) {
            int operacao;
            scanf("%d", &operacao);
            
            if (operacao == 1) {
                int x;
                scanf("%d", &x);
                
                if (eh_pilha) {
                    pilha[++topo] = x;
                }

                if (eh_fila)  {
                    fila[++tras_fila] = x;
                }

                if (eh_prioridade) {
                    int j = tamanho_fila_prioridade++;
                    fila_prioridade[j] = x;
                    
                    while (j > 0 && fila_prioridade[(j - 1) / 2] < fila_prioridade[j]) {
                        int temp = fila_prioridade[j];
                        fila_prioridade[j] = fila_prioridade[(j - 1) / 2];
                        fila_prioridade[(j-1)/2] = temp;
                        j = (j - 1) / 2;
                    }
                }

            } else {
                int esperado;
                scanf("%d", &esperado);
                
                if (eh_pilha) {
                    if (topo == -1 || pilha[topo--] != esperado) {
                        eh_pilha = 0;
                    }
                }
                
                if (eh_fila) {
                    if (frente_fila > tras_fila || fila[frente_fila++] != esperado) {
                        eh_fila = 0;
                    }
                }
                
                if (eh_prioridade) {
                    if (tamanho_fila_prioridade == 0 || fila_prioridade[0] != esperado) {
                        eh_prioridade = 0;
                    } else {
                        fila_prioridade[0] = fila_prioridade[--tamanho_fila_prioridade];
                        int j = 0;
                        
                        while (1) {
                            int esquerda = 2 * j + 1;
                            int direita = 2 * j + 2;
                            int maior = j;
                            
                            if (esquerda < tamanho_fila_prioridade && fila_prioridade[esquerda] > fila_prioridade[maior])
                                maior = esquerda;
                            if (direita < tamanho_fila_prioridade && fila_prioridade[direita] > fila_prioridade[maior])
                                maior = direita;
                            
                            if (maior == j) break;
                            
                            int temp = fila_prioridade[j];
                            fila_prioridade[j] = fila_prioridade[maior];
                            fila_prioridade[maior] = temp;
                            j = maior;
                        }
                    }
                }
            }
        }
        
        int contador = eh_pilha + eh_fila + eh_prioridade;
        
        if (contador == 0) {
            printf("impossible\n");
        } else if (contador > 1) {
            printf("not sure\n");
        } else {
            if (eh_pilha) {
                printf("stack\n");
            } else if (eh_fila) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }
    
    return 0;
}