#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int chave;
    int x;
    struct cel *esq;
    struct cel *dir;
} cel;
typedef cel *arvore;

arvore insere(arvore, cel*);
void prefixo(arvore);
void infixo(arvore);
void posfixo(arvore);

int main() {
    int c, n, x;
    cel *novo;
    arvore raiz;

    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        raiz = NULL;
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d", &x);

            novo = malloc(sizeof(cel));
            novo->chave = x;
            novo->dir = NULL;
            novo->esq = NULL;

            raiz = insere(raiz, novo);
        }
        
        printf("Case %d:\n", i + 1);

        printf("Pre.:");
        prefixo(raiz);
        printf("\n");

        printf("In..:");
        infixo(raiz);
        printf("\n");

        printf("Post:");
        posfixo(raiz);
        printf("\n\n");
    }

}

arvore insere(arvore r, cel *novo) {
    cel *f, *p;
    if (r == NULL) {
        return novo;
    }

    f = r;
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

    return r;
}

void prefixo(arvore r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        prefixo(r->esq);
        prefixo(r->dir);
    }
}

void infixo(arvore r) {
    if (r != NULL) {
        infixo(r->esq);
        printf(" %d", r->chave);
        infixo(r->dir);
    }
}

void posfixo(arvore r) {
    if (r != NULL) {
        posfixo(r->esq);
        posfixo(r->dir);
        printf(" %d", r->chave);
    }
}