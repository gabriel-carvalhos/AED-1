#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} cel;

void pop(cel *);
void push(cel *);

int main() {
    char exp[1001];

    while (scanf("%1000s", exp) != EOF) {
        int valido = 1;
        cel cabeca, *pilha;
        pilha = &cabeca;
        pilha->seg = NULL;

        for (int i = 0; i < strlen(exp); i++) {
            if (exp[i] == '(') {
                push(pilha);
            } else if (exp[i] == ')') {
                if (pilha->seg != NULL) {
                    pop(pilha);
                    continue;
                }

                valido = 0;
                break;
            }
        }

        if (pilha->seg == NULL && valido == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;

}

void pop(cel *pilha) {
    cel *q;
    q = pilha->seg;
    pilha->seg = q->seg;
    free(q);
}

void push(cel *pilha) {
    cel *nova;
    nova = malloc(sizeof(cel));
    nova->conteudo = '(';
    nova->seg = pilha->seg;
    pilha->seg = nova;
}