#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int x;
    struct no *esq;
    struct no *dir;
} no;
typedef no *arvore;

arvore insere(arvore, no*);
void imprime(arvore);

int main() {
    int nc, n, h;
    arvore raiz;
    no *novo;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);

        scanf("%d", &h);

        raiz = (no *) malloc(sizeof(no) * n);
        raiz->chave = h;
        raiz->esq = NULL;
        raiz->dir = NULL;
        
        for (int j = 1; j < n; j++) {
            scanf("%d", &h);
            novo = (no *) malloc(sizeof(no));
            novo->chave = h;
            novo->esq = NULL;
            novo->dir = NULL;
            insere(raiz, novo);
        }

        imprime(raiz);
        printf("\n");
        
        free(raiz);

        // for (int j = 0; j < n; j++) {
        //     if (j != 0) {
        //         printf(" ");
        //     }
        //     printf("%d", h[j]);
        // }

    }
    
    return 0;
}

arvore insere(arvore raiz, no *novo) {
    no *f, *p;
    if (raiz == NULL) {
        return novo;
    }

    f = raiz;
    while (f != NULL) {
        p = f;
        if (f->chave > novo->chave) {
            f = f->esq;
        } else {
            f = f->dir;
        }
    }

    if (p->chave > novo->chave) {
        p->esq = novo;
    } else {
        p->dir = novo;
    }

    return raiz;
}

void imprime(arvore raiz) {
    if (raiz != NULL) {
        // printf(" ");
        imprime(raiz->esq);
        printf("%d ", raiz->chave);
        imprime(raiz->dir);
    }
}