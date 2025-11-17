#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
    int valor;
    struct cel *abaixo;
} cel;

void push(cel**, int);
void pop(cel**);

int main() {
    int n, x;
    cel *a, *estacao, *b;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        while (scanf("%d", &x)) {
            if (x == 0) {
                printf("\n");
                break;
            }

            a = NULL;
            estacao = NULL;
            b = NULL;

            push(&a, x);
            push(&b, 1);

            for (int i = 2; i <= n; ++i) {
                scanf("%d", &x);
                push(&a, x);
                push(&b, i);
            }

            while (a != NULL || estacao != NULL || b != NULL) {
                if (a != NULL && b != NULL && a->valor == b->valor) {
                    pop(&a);
                    pop(&b);
                } else if (estacao != NULL && b != NULL && estacao->valor == b->valor) {
                    pop(&estacao);
                    pop(&b);
                } else if (a != NULL) {
                    push(&estacao, a->valor);
                    pop(&a);
                } else {
                    break;
                }
            }

            if (a == NULL && estacao == NULL && b == NULL) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            while (a != NULL) {
                pop(&a);
            }

            while (estacao != NULL) {
                pop(&estacao);
            }

            while (b != NULL) {
                pop(&b);
            }
        }
    }

    return 0;
}

void push(cel **topo, int valor) {
    cel *novoTopo = (cel*) malloc(sizeof(cel));
    novoTopo->valor = valor;
    novoTopo->abaixo = *topo;
    *topo = novoTopo;
}

void pop(cel **topo) {
    if (*topo != NULL) {
        cel *velhoTopo = *topo;
        *topo = (*topo)->abaixo;
        free(velhoTopo);
    }
}