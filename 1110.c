#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
    int valor;
    struct cel *anterior, *proximo;
} cel;

typedef struct deque {
    int tamanho;
    struct cel *frente, *tras;
} deque;

void inicializar(deque *);
void destroi(deque *);
int tamanho(deque *);
int vazio(deque *);
int carta_frente(deque *);
void push_atras(deque *, int);
void pop_frente(deque *);

int main() {
    int n;
    deque cartas;

    while (scanf("%d", &n)) {
        int primeiro;

        if (n == 0) {
            break;
        }

        inicializar(&cartas);

        for (int i = 1; i <= n; ++i) {
            push_atras(&cartas, i);
        }

        primeiro = 1;

        printf("Discarded cards: ");
        while (tamanho(&cartas) > 1) {
            if (!primeiro) {
                printf(", ");
            } else {
                primeiro = 0;
            }

            printf("%d", carta_frente(&cartas));

            pop_frente(&cartas);
            push_atras(&cartas, carta_frente(&cartas));
            pop_frente(&cartas);
        }

        printf("\nRemaining card: %d\n", carta_frente(&cartas));

        destroi(&cartas);
    }

    return 0;
}

void inicializar(deque *d) {
    d->frente = NULL;
    d->tras = NULL;
    d->tamanho = 0;
}

void destroi(deque *d) {
    while (!vazio(d)){
        pop_frente(d);
    }
}

int tamanho(deque *d) {
    return d->tamanho;
}

int vazio(deque *d) {
    if (d->tamanho == 0) {
        return 1;
    }

    return 0;
}

int carta_frente(deque *d) {
    return d->frente->valor;
}

void push_atras(deque *d, int valor) {
    d->tamanho += 1;
    cel *novoTras = (cel *) malloc(sizeof(cel));

    novoTras->valor = valor;
    novoTras->anterior = d->tras;
    
    if (d->tras != NULL) {
        d->tras->proximo = novoTras;
    }
        
    d->tras = novoTras;

    if (d->frente == NULL) {
        d->frente = d->tras;
    }
}

void pop_frente(deque *d) {
    if (d->tamanho > 0) {
        d->tamanho -= 1;
        cel *velhaFrente = d->frente;
        d->frente = d->frente->proximo;
        free(velhaFrente);
    }
}