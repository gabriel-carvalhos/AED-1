#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int conteudo;
    struct cel *seg;
} cel;

void empilha(cel *, int);
void mostraPilha(cel *);

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

        mostraPilha(pilha);

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

void mostraPilha(cel *pilha) {
    for (cel *p = pilha; p != NULL; p = p + 1) {
        printf("%d\n", p->conteudo);
    }
}