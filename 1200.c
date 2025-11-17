#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    int chave;
    char x;
    struct cel *esq;
    struct cel *dir;
} cel;
typedef cel *arvore;

arvore insere(arvore, cel*);
void prefixo(arvore);
void infixo(arvore);
void posfixo(arvore);
cel *busca(arvore, char);

// Funções auxiliares
void prefixo_aux(arvore, int*);
void infixo_aux(arvore, int*);
void posfixo_aux(arvore, int*);

int main() {
    char op[7], c;
    cel *novo;
    arvore raiz = NULL;

    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "I") == 0) {
            getchar();
            scanf("%c", &c);

            novo = malloc(sizeof(cel));
            novo->chave = c;
            novo->x = c;
            novo->dir = NULL;
            novo->esq = NULL;

            raiz = insere(raiz, novo);
        } else if (strcmp(op, "INFIXA") == 0) {
            infixo(raiz);
            printf("\n");
        } else if (strcmp(op, "PREFIXA") == 0) {
            prefixo(raiz);
            printf("\n");
        } else if (strcmp(op, "POSFIXA") == 0) {
            posfixo(raiz);
            printf("\n");
        } else if (strcmp(op, "P") == 0) {
            getchar();
            scanf("%c", &c);

            if (busca(raiz, c) != NULL) {
                printf("%c existe\n", c);
            } else {
                printf("%c nao existe\n", c);
            }
        }
    }
    return 0;
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

// Funções wrapper
void prefixo(arvore r) {
    int primeiro = 1;
    prefixo_aux(r, &primeiro);
}

void infixo(arvore r) {
    int primeiro = 1;
    infixo_aux(r, &primeiro);
}

void posfixo(arvore r) {
    int primeiro = 1;
    posfixo_aux(r, &primeiro);
}

// Funções auxiliares que controlam os espaços
void prefixo_aux(arvore r, int *primeiro) {
    if (r != NULL) {
        if (*primeiro) {
            printf("%c", r->x);
            *primeiro = 0;
        } else {
            printf(" %c", r->x);
        }
        prefixo_aux(r->esq, primeiro);
        prefixo_aux(r->dir, primeiro);
    }
}

void infixo_aux(arvore r, int *primeiro) {
    if (r != NULL) {
        infixo_aux(r->esq, primeiro);
        if (*primeiro) {
            printf("%c", r->x);
            *primeiro = 0;
        } else {
            printf(" %c", r->x);
        }
        infixo_aux(r->dir, primeiro);
    }
}

void posfixo_aux(arvore r, int *primeiro) {
    if (r != NULL) {
        posfixo_aux(r->esq, primeiro);
        posfixo_aux(r->dir, primeiro);
        if (*primeiro) {
            printf("%c", r->x);
            *primeiro = 0;
        } else {
            printf(" %c", r->x);
        }
    }
}

cel *busca(arvore r, char x) {
    if (r == NULL || r->x == x) {
        return r;
    }

    if (r->x > x) {
        return busca(r->esq, x);
    } else {
        return busca(r->dir, x);
    }
}