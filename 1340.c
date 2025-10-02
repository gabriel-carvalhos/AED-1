#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} cel;

void empilha(cel *, int);
void empilha(cel *, int);

int main() {
    int n, comando, x;
    
    printf("Digite N: ");
    scanf("%d", &n);

    while(n != -1) {
        cel cabeca;
        cel *pilha = &cabeca;
        pilha->seg = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%d", &comando);
            scanf("%d", &x);

            if (comando == 1) {
                empilha(pilha, x);
                continue;
            }


        }

        printf("Digite N: ");
        scanf("%d", &n);
    }
}

void empilha(cel *pilha, int x) {
    cel *nova;
    nova = malloc(sizeof(cel));
    nova->conteudo = x;
    nova->seg = pilha->seg;
    pilha->seg = nova;
}

void desempilha(cel *pilha) {
    cel *q;
}